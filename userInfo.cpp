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

	v.at(0) = acType;
	v.at(1) = id;
	v.at(2) = pw;
	v.at(3) = balance;
	v.at(4) = funds;
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

void UserInfo::SaveInfo(int ID, string pass, double b, double f) {
	for (int i = 0; i < id.size(); ++i) {
		if (to_string(ID) == id.at(i)) {
			pw.at(i) = pass;
			balance.at(i) = to_string(b);
			funds.at(i) = to_string(f);
		}
	}
}

vector<vector<string>> UserInfo::ReadList() {
	return v;
}
