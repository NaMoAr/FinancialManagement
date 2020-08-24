#include "userInfo.hpp"

UserInfo::UserInfo() {}

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
	vector<vector<string>> v;
	string c, t;
	ifstream inFS("UserInfo.csv");
	if(!inFS.is_open()) {
		cout << "Error opening CSV file for reading in" << endl;
		return 1;
	}

	while(getline(inFS, t)) {
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

	v.push_back(acType);
	v.push_back(id);
	v.push_back(pw);
	v.push_back(balance);
	v.push_back(funds);
	
	return v;
}
