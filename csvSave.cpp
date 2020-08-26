#include "csvSave.hpp"

CSVSave::~CSVSave() {
	UserInfo* u = new CSVSave();
	u->PrintList();
	delete u;
//When the program terminates, destructor calls PrintList to print the accounts into UserInfo.csv
}

void CSVSave::PrintList() {
	ofstream outFS("files/UserInfo.csv");
	if(!outFS.is_open()) {
		cout << "Error! Cannot open CSV file for reading out" << endl;
	}

	for(int i = 0; i < id.size(); ++i) {
		outFS   << acType.at(i) << ","
		     	<< id.at(i) << "," 
		      	<< pw.at(i) << "," 
                   	<< balance.at(i) << ","  
                  	<< funds.at(i) << ","
			<< stock.at(i) <<endl;

	}

	outFS.close();
//Called upon program termination to print out all the information stored in vectors to the CSV file
}

void CSVSave::SaveInfo(string ac, int ID, string pass, double b, double f) {
	acType.push_back(ac);
	id.push_back(to_string(ID));
	pw.push_back(pass);	
	balance.push_back(to_string(b));
	funds.push_back(to_string(f));			
	stock.push_back("0");
//Called by CustomerList to store info when Account Type is a checking account. stock vector still pushes back a 0 for consistency with the other vectors, and for when reading in list
}

void CSVSave::SaveInfo(string ac, int ID, string pass, double b, double f, double n) {
	acType.push_back(ac);
	id.push_back(to_string(ID));
	pw.push_back(pass);
	balance.push_back(to_string(b));
	funds.push_back(to_string(f));
	stock.push_back(to_string(n));
//Called by CustomerList to store info when Account Type is a savings account
}

vector<vector<string>> CSVSave::ReadList() {
	string c;
	string t;
	
	ifstream inFS("files/UserInfo.csv");
	if (!inFS.is_open()) {
		cout << "Error! Cannot open CSV file for reading in" << endl;
	}

	while (getline(inFS, t)) {
		stringstream s(t);
	
		getline(s, c, ',');
		acType.push_back(c);
		getline(s, c, ',');	
		id.push_back(c);
		getline(s, c, ',');
		pw.push_back(c);
		getline(s, c, ',');
		balance.push_back(c);
		getline(s, c, ',');
		funds.push_back(c);
		getline(s, c, ',');
		stock.push_back(c);
	}

	inFS.close();

	vector<vector<string>> v;

	v.push_back(acType);
	v.push_back(id);
	v.push_back(pw);
	v.push_back(balance);
	v.push_back(funds);
	v.push_back(stock);

	acType.clear();
	id.clear();
	pw.clear();
	balance.clear();
	funds.clear();
	stock.clear();

	return v;	
//Called by CustomerList to read in all accounts in file and store each information in a vector. Another vector of type vector<string> will hold all the other vector<string>'s as declared in the header file, The vector<vector<string>> v will then be returned to CustomerList
}

string CSVSave::PrintDebug() {
	string s;
	for (int i = 0; i < id.size(); ++i) {
		if(acType.at(i) == "c") {
			s = s + id.at(i) + " " + pw.at(i) + " " + balance.at(i) + " " + funds.at(i) + "\n";
		}
		else if (acType.at(i) == "s") {
			s = s + id.at(i) + " " + pw.at(i) + " " + balance.at(i) + " " + funds.at(i) + " " + stock.at(i) + "\n";
		}
	}
	return s;
//Function created to help with google testing
}
