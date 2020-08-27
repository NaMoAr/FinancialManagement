#include "../header/txtSave.hpp"

TXTSave::~TXTSave() {
	UserInfo* u = new TXTSave();
	u->PrintList();
	delete u;
//Called upon program termination to write out everything in the vectors to the TXT file
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
		outFS << stock.at(i) << endl;
		outFS << endl;
	}

	outFS.close();
//Writes out everything in the vectors into a TXT file
}

void TXTSave::SaveInfo(string ac, int ID, string pass, double b, double f) {
	acType.push_back(ac);
	id.push_back(to_string(ID));
	pw.push_back(pass);
	balance.push_back(to_string(b));
	funds.push_back(to_string(f));
	stock.push_back("0");
//Called by CustomerList if account is a checking account. Stock pushes back "0" as a place holder
}

void TXTSave::SaveInfo(string ac, int ID, string pass, double b, double f, double n) {
	acType.push_back(ac);
	id.push_back(to_string(ID));
	pw.push_back(pass);
	balance.push_back(to_string(b));
	funds.push_back(to_string(f));
	stock.push_back(to_string(n));
//Called by CustomerList if account is a savings account
}

vector<vector<string>> TXTSave::ReadList() {
	vector<vector<string>> v;
	string t;
	string c;
	string temp = "UserInfo.txt";
	ifstream inFS(temp);
	if (!inFS.is_open()) {	
		cout << "Error! Cannot open "<<temp <<" for reading in" << endl;
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
		getline(inFS, t);
		stock.push_back(t);
		inFS >> c;
	}

	inFS.close();

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
//Called by CustomerList to read in all account information from TXT file. Each vector in the header pushes back one piece of information, and then all those vectors are stored in a vector of vector<string> called v, which is then returned to the CustomerList
}

string TXTSave::PrintDebug() {
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
//Helper function for google testing
}
