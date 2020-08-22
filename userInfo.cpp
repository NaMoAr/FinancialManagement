#include "customerList.hpp"
#include "userInfo.hpp"

UserInfo::UserInfo() {
	string t;
	string c;

	ifstream inFS ("UserInfo.csv");
	if (!inFS.is_open()) {
		cout << "Error opening file for reading in" << endl;
		return 1;
	}

	//CSV FILE REQUIREMENTS
	//No spaces
	//If user does not use a budget tool, value inside vector must be 0

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
	}
	inFS.close();

	for (int i = 0; i < id.size(); ++i) {
		//Calls Account to create Account objects
		profile = new Profile(); // or new Account();
		profile->setID(id.at(i));
		profile->setPassword(pw.at(i));
		profile->setBalance(stod(balance.at(i)));
		if(acType.at(i) == "s") {
			profile->setStocks(stod(funds.at(i)));
		}
		else if(acType.at(i) == "c") {
			profile->setMonthlyHomeRent(stod(funds.at(i)));
		}
	}
}

UserInfo::~UserInfo() {
	//When we add an account, do we manually update the csv file? Because UserInfo reads in the list before creating objects	
	UserInfo* csv = new CSVSave();
	UserInfo* txt = new TXTSave();	

	csv->PrintList();
	txt->PrintList();	

	delete csv;
	delete txt;
	delete profile;
}

UserInfo::SaveInfo(Account* p) {
	for (int i = 0; i < id.size(); ++i) {
		if (id.at(i) == p->getID()) {
			balance.at(i) = to_string(p->getBalance());
			if(acType.at(i) == "s") {
				funds.at(i) = to_string(p->getUserStocks());
			}
			else if (acType.at(i) == "c") {
				funds.at(i) = to_string(p->getMonthlyHomeRent());
			}
		}
	}
}
