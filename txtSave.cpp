#include "txtSave.hpp"

TXTSave::~TXTSave() {
	UserInfo* u = new TXTSave();
	u->PrintList();
	delete u;
}

void TXTSave::PrintList() {
	ofstream outFS("UserInfo.txt");
	if (!outFS.is_open()) {
		cout << "Error! Cannot open TXT file for reading out" << endl;
	}

	for (int i = 0; i < id.size(); ++i) {
		outFS << acType.at(i) << endl;
		outFS << id.at(i) << endl;
		outFS << pw.at(i) << endl;
		outFS << balance.at(i) << endl;
		outFS << funds.at(i) << endl;
		outFS << endl;
	}

	outFS.close();
}

void TXTSave::SaveInfo(string ac, int ID, string pass, double b, double f) {
	for (int i = 0; i < id.size(); ++i) {
		if ((ac == acType.at(i)) && (to_string(ID) == id.at(i)) ) {
			pw.at(i) = pass;
			balance.at(i) = to_string(b);
			funds.at(i) = to_string(f);
			break;
		}
	}
}

vector<vector<string>> TXTSave::ReadList() {
	vector<vector<string>> v;
	string t;
	string c;
	
	ifstream inFS("UserInfo.txt");
	if (!inFS.is_open()) {	
		cout << "Error! Cannot open TXT file for reading in" << endl;
	}

	while (getline(inFS, t)) {
		acType.push_back(t);
		getline(inFS, t);
		id.push_back(t);
		getline(inFS, t);	
		pw.push_back(t);
		getline(inFS, t);
		balance.push_back(t);
		getline(inFS, t);
		funds.push_back(t);
		inFS >> c;
	}

	inFS.close();

	v.push_back(acType);
	v.push_back(id);
	v.push_back(pw);
	v.push_back(balance);
	v.push_back(funds);
	
	return v;
}

string TXTSave::PrintDebug() {
	return "print";
}

void TXTSave::AddAccount(string ac, int ID, string pass, double b, double f) {
	bool found = false;

	for (int i = 0; i < id.size(); ++i) {
		if ((ac == acType.at(i)) && (to_string(ID) == id.at(i)) ) {
			found = true;
			break;
		}
	}	
	
	if (!found) {
		acType.push_back(ac);
		id.push_back(to_string(ID));
		pw.push_back(pass);
		balance.push_back(to_string(b));
		funds.push_back(to_string(f));
	}
}

void TXTSave::DeleteAccount(string ac, int ID, string pass, double b, double f) {
	bool found = false;
	int index;
	for (int i = 0; i < id.size(); ++i) {
		if ((ac == acType.at(i)) && (to_string(ID) == id.at(i)) ) {
			found = true;
			index = i;
			break;
		}
	}

	if(found) {
		acType.erase(acType.begin() + index);
		id.erase(id.begin() + index);
		pw.erase(pw.begin() + index);
		balance.erase(balance.begin() + index);
		funds.erase(funds.begin() + index);
	}
}
