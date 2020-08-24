#include "AccountList.hpp"
#include <typeinfo>

// TODO: verify the function and implementation of utilized unordered_map functions associated to the object "list"

AccountList::AccountList () {
// call Chloe's class to read the database file
auto v = object->ReadList(); //TODO: we still need the name of chloe's userifo object

	for (int i = 0, i < v.size(); i++){
		if (v[i][0] == "s"){ // this implementation of element access for a vecotr of vecotrs of strings may need review
			Account* temp = new SavingAccountProxy(v[i][3], v[i][1], v[i][2], v[i][4], 0);	
			list.insert(v[i][1],temp);
		}
		else {
			Account* Temp = new CheckingAccountProxy(v[i][3], v[i][1], v[i][2], v[i][4]);
			list.insert(v[i][1],Temp);
		}
	}
}

AccountList::~AccountList() {
// call Chloe's class to write the account data to the database file


// delete all pointers in the hash map
	for (auto x : list) {
		if (typeid(x.second).name() == CheckingAccountProxy*)
			object->saveinfo(c,x.second->getID(), x.second->getPassword(), x.second->getBalance, x.second->getMonthlyHomeRent() ); //TODO: figure out the name of chloe's userinfo object
		if (typeid(x.second).name() == SavingAccountProxy*)
			object->saveinfo(c,x.second->getID(), x.second->getPassword(), x.second->getBalance, x.second->getStockNum() );
		delete x.second();
	} //once objects in memory are deleted we can close the program
delete this; // this might be overkill or could somehow break the program? not realy sure
}


AccountList* AccountList::GetInstance() {
// check to see if an accountlist exists, if so return it
// if it doesnt exist create the object by calling the constructor
// return the pointer of the object you just created
}

void interface() {
	char temp = 4;
	std::cout << "Welcome to the financial planning and stock management account access tool" << endl << "to access administrator functions enter '0', to log in to a user account enter '2' to quit the program enter '3' " << endl;
	if (temp == 1) 	adminMenu();
	if (temp == 2)	login();
	if (temp != 3)	interface();
	// final saves to the file calling chloes stuff?
	return;
	
}

void AccountList::createAccount () {
	std::string temp = "";
	std::string pass = "";
	int value;
	// verify admin status with an admin password
	std::cout << "Verify administrator status" << endl;
	std::cin >> temp;
	if (temp != AdminAccess) {cout << "Verification failed, terminating operation"<<endl; return;}
	// request new password
	std::cout << "Assign a password"<<endl;
	std::cin >> pass;
	std::cout <<"The password to be assigned is "<< pass << endl; 
	// generate a unique ID
	int ID = 0;
	ID =  list.size()+1; // ignore account 0 which is reserved for admin access
	std::cout << "account ID generated: " << ID << endl;
	// specify initial deposit
	std::cout << "specify initial deposit amount" << endl;
	std cin >> value;
	std:: cout << "the account will be initialized with an inital balance of " << value << end;
	// assign a type for the account
	std::cout << "specify account type: 'c' for checking and 's' for savings"
	char flag = ' ';
	cin >> flag;
	// create an account object
	// fit the pointer into the map
	if (flag != 'c' && flag != 's'){
		cout << "Account type invalid, terminating" << endl; return;
	}
	if (flag = 'c') {
		// construct and store a checking account object
		Account* toAdd = new CheckingAccountProxy(value,ID,pass,0,0);
		list.insert(ID, toAdd);
		return;
	}
	// construct and store a saving account object
	Account* toadd = new SavingAccountProxy(value,ID,pass,0);
	list.insert(ID, toadd);
	return;
}

void AccountList::deleteAccount () {
	Account* toRemove;
	int temp = ""
	// verify admin status with an admin password
	std::cout << "Verify administrator status" << endl;
	std::cin >> temp;
	if (temp != AdminAccess) {cout << "Verification failed, terminating operation"<<endl; return;}	
	// search for id, report an error if it doesn't exist 
	std::cout << "specify account ID to remove" << endl;
	cin >> temp;
	toRemove = traverseDatabase();
	if (toRemove == NULL) {std::cout<< "account not found, terminationg operation" << endl; return;}
	list.erase(ID); 
	delete toRemove; // may be an incorrect deletion type
	return;
	// delete the object and set the pointer to null
}

// a helper function to let people search the list
Account* AccountList::traverseDatabase (int ID) {  // Final implementation will return an account*
	Account* temp = NULL;
	// this function searches the database for a given id returning it
	temp = list.find(ID);
	// if none exists it will return NULL
	return temp;
}

void AccountList::logIn() {
	int ID = 0;
	string pass = "";
	// prompt ID & Password
	std::cout << "Enter ID" << endl;
	std:: cin >> ID;
	// scan list for ID returning null on a fail to find and print "account not found"
	userPointer = traverseDatabase(ID);
	// compare Password returning the account pointer on a match and null on a mismatch, in the fail case print "password incorrect" 
	if (userPointer == NULL) {std::cout<<"account not found, terminating"; return;}
	if (userPointer->getPassword() != pass) {std::cout << "password invalid, terminating"; return;}
	userPointer->Menu(); // this function call will depend on the way Najmeh implements her menu
}

void adminMenu() {
char temp
std::cout << "1 to remove an account. 2 to create an account, any other character to exit admin"<< endl;
cin >> temp;
if (temp == '1') deleteAccount();
if (temp == '2') createAccount();
return;

}

void AccountList::logOut() {
// is called by account history proxy logout function
// unset user pointer
userPointer = NULL;
// re call the log in prompt
logIn();  
}

