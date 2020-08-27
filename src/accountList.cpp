#include "../header/accountList.hpp"
#include "../header/txtSave.hpp"
#include "../header/csvSave.hpp"
#include <typeinfo>
#include <vector>
using namespace std;

AccountList *AccountList::AccountList_ = 0;
 
AccountList::AccountList (TXTSave* object1, CSVSave* Object2) { // we assume that a file named UserInfo.csv and UserInfo.txt exist, they may be empty to show a new database 
//TODO suffering out of range
// call Chloe's class to read the database file
	AccountList_ = this;
	rOne = object1;
	rTwo = Object2; // NOTE: whenever a new file save type is added it must be included in the constructor and as a pushback here
	//vector<vector<string>> v = rOne->ReadList();
	
	// vector<vector<string>> v  = {};

	vector<vector<string>> v = {{"s","1","apple","12345","5","4"},{"c","2","banana","123456","6","0"},{"s","3","carrot","123456","6","3"},{"c","4","donut","12345","5","0"},{"c","5","eggtart","123456","7","0"}};




	cout << "list read" << endl;
	std::vector< std::vector<string> >::const_iterator row;
	if (!v.empty()){
 		for (int row = 0; row < v.size(); ++row) {
			auto it = v.at(row);
			if (it.at(0)== "c") {//checking entry
				CheckingAccountProxy* temp = new CheckingAccountProxy(std::stod(it.at(3)), std::stoi(it.at(1)), it.at(2),std::stoi(it.at(4)));
				database->emplace(std::stoi(it.at(1)), temp); cout << "creating check" << endl; 
			}	
			else {// otherwise saving entry
				SavingAccountProxy* Temp = new SavingAccountProxy(std::stod(it.at(3)), std::stoi(it.at(1)), it.at(2),std::stoi(it.at(4)),std::stod(it.at(5)));
				database->emplace(std::stoi(it.at(1)),Temp); cout << "creating save" << endl;
			}
		}
	} 
}

AccountList::~AccountList() { //TODO Get this working suffering out of range
// call Chloe's class to write the account data to the database file

//cout << "we have reached the end times" <<endl;
// delete all pointers in the hash map
		int i = 1;
		int max = database->size();
		while (i <= max) {
	cout << "i is: " << i <<endl;		
			cout << "we have "<<database->size()-i <<" more accounts to log" << endl;
			auto x = database->at(i);
			i++;
			cout << x->whatType()<< endl;
			if (x->whatType() == 'c'){
				cout << "submitting a checking account to save" << endl;
				CheckingAccountProxy* y = dynamic_cast<CheckingAccountProxy*>(x);
				cout <<"expect c: "<< y->whatType()<< endl;
				rOne->SaveInfo("c",y->getID(), y->getPassword(), y->getBalance(), y->getMonthlyHomeRent());
				rTwo->SaveInfo("c",y->getID(), y->getPassword(), y->getBalance(), y->getMonthlyHomeRent());		
			}
			if (x->whatType() == 's'){//		NOTE: testing can't support this request at this time, we'll fo it later
				cout << "submitting a saving account to save" << endl;
				SavingAccountProxy* z = dynamic_cast<SavingAccountProxy*>(x);
				cout<<"expect s: " << z->whatType()<< endl;
				rOne->SaveInfo("s",z->getID(), z->getPassword(), z->getBalance(), z->getStockNum(),z->getStockPrice() );
				rTwo->SaveInfo("s",z->getID(), z->getPassword(), z->getBalance(), z->getStockNum(),z->getStockPrice() );
			}
			delete x;
			

		} //once objects in memory are deleted we can close the program
//delete this; // this might be overkill or could somehow break the program? not realy sure
}


AccountList* AccountList::GetInstance(TXTSave* one, CSVSave* two) {
// check to see if an accountlist exists, if so return it 
	if (AccountList_==nullptr) AccountList_ = new AccountList(one,two);
	return AccountList_;
// if it doesnt exist create the object by calling the constructor
// return the pointer of the object you just created
}

void AccountList::interface() {
	char temp = '4';
	std::cout << "Welcome to the financial planning and stock management account access tool" << endl << "to access administrator functions enter '1',"<< endl <<" to log in to a user account enter '2' "<<endl<< "to quit the program enter '3' " << endl;
	std::cin >> temp;
	if (temp == '1')adminMenu();
	if (temp == '2')logIn();
	if (temp != '3')interface();
	// final saves to the file calling chloes stuff?
	delete this;
	return;
	
}

void AccountList::createAccount () {
	std::string pass = "";
	int value;
	// request new password
	std::cout << "Assign a password"<<endl;
	std::cin >> pass;
	std::cout <<"The password to be assigned is "<< pass << endl; 
	// generate a unique ID
	int ID = 0;
	// this function searches the database for a given id returning it
	unordered_map<int,Account*>::iterator it = database->begin();
		ID = it->first+1; 
	// if (ID == 0) ID = database->end-1.first;
	std::cout << "account ID generated: " << ID << endl;
	// specify initial deposit
	std::cout << "specify initial deposit amount" << endl;
	std::cin >> value;
	std::cout << "the account will be initialized with an inital balance of " << value << endl;
	// assign a type for the account
	std::cout << "specify account type: 'c' for checking and 's' for savings "<< endl;
	char flag = ' ';
	cin >> flag;
	// create an account object
	// fit the pointer into the map
	if (flag != 'c' && flag != 's'){
		cout << "Account type invalid, terminating" << endl; return;
	}
	if (flag = 'c') {
		// construct and store a checking account object
		CheckingAccountProxy* toAdd = new CheckingAccountProxy(value,ID,pass,0);
		database->insert({ID, toAdd});
		return;
	}
	// construct and store a saving account object
	SavingAccountProxy* toadd = new SavingAccountProxy(value,ID,pass,0,0);
	database->insert({ID, toadd});
	return;
}

void AccountList::deleteAccount () {
	Account* toRemove;	
	int ID = 0;
	// search for id, report an error if it doesn't exist 
	std::cout << "specify account ID to remove" << endl;
	cin >> ID;
	toRemove = traverseDatabase(ID);
	if (toRemove == nullptr) {std::cout<< "account not found, terminationg operation" << endl; return;}
	
	database->erase(ID); 
	toRemove = nullptr; // flag for reuse
	delete toRemove; // may be an incorrect deletion type
	return;
	// delete the object and set the pointer to null
}
int AccountList::size(){
	return database->size();
}

// a helper function to let people search the list
Account* AccountList::traverseDatabase (int ID) {  // Final implementation will return an account*
	Account* temp = nullptr; // defualt assumption the pointer isnt there
		
	// this function searches the database for a given id returning it
	for (unordered_map<int,Account*>::iterator it = database->begin();it != database->end() ;it++) {
		if (ID == it->first)
			temp = it->second; //segs here:
	}
	// if none exists it will return NULL
	return temp;
}

void AccountList::logIn() {
	int ID = 0;
	string pass = "";
	// prompt ID
	std::cout << "Enter ID" << endl;
	std:: cin >> ID;
	// scan list for ID returning null on a fail to find and print "account not found"
	userPointer = traverseDatabase(ID);
	// compare Password returning the account pointer on a match and null on a mismatch, in the fail case print "password incorrect" 
	if (userPointer == nullptr) {std::cout<<"account not found, terminating"; return;}
	// prompt  Password
	std::cout << "Enter Password" << endl;
	std::cin >> pass;
	if (userPointer->getPassword() != pass) {std::cout << "password invalid, terminating"; return;}
	userPointer->Menu();
	userPointer = nullptr;
}

void AccountList::adminMenu() {
	
	std::string Temp = "";
	// verify admin status with an admin password
	std::cout << "Verify administrator status" << endl;
	std::cin >> Temp;
	if (Temp != adminAccess) {cout << "Verification failed, terminating operation"<<endl; return;}		
	char temp;
	std::cout << "1 to remove an account. 2 to create an account, any other character to exit admin"<< endl;
	cin >> temp;
	if (temp == '1') deleteAccount();
	if (temp == '2') createAccount();
	return;

}
