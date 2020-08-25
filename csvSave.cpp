#include "csvSave.hpp"

CSVSave::~CSVSave() {
	UserInfo* u = new CSVSave();
	u->PrintList();
	delete u;
}

void CSVSave::PrintList() {
	ofstream outFS("UserInfo.csv");
	if(!outFS.is_open()) {
		cout << "Error! Cannot open CSV file for reading out" << endl;
	}

	for(int i = 0; i < id.size(); ++i) {
		outFS << acType.at(i) << ","
		      << id.at(i) << "," 
		      << pw.at(i) << "," 
                      << balance.at(i) << ","  
                      << funds.at(i) << endl;
	}

	outFS.close();
}

void CSVSave::SaveInfo(string ac, int ID, string pass, double b, double f) {
	for (int i = 0; i < id.size(); ++i) {
		if ( (ac == acType.at(i)) && (stoi(id.at(i)) == ID) )  {
			pw.at(i) = pass;
			balance.at(i) = to_string(b);
			funds.at(i) = to_string(f);
			break;
		}
	}
}

vector<vector<string>> CSVSave::ReadList() {
	string c;
	string t;
	
	ifstream inFS("UserInfo.csv");
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
	}

	inFS.close();

	vector<vector<string>> v;

	v.push_back(acType);
	v.push_back(id);
	v.push_back(pw);
	v.push_back(balance);
	v.push_back(funds);

	return v;	
	
}

string CSVSave::PrintDebug() {
	return "Testing";
}

void CSVSave::AddAccount(string ac, int ID, string pass, double b, double f) {
	bool found = false;
	for (int i = 0; i < id.size(); ++i) {
		if (to_string(ID) == id.at(i)) {
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

void CSVSave::DeleteAccount(string ac, int ID, string pass, double b, double f) {
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
