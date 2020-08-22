#include "txtSave.hpp"

void txtSave::PrintList() {
	ofstream outFS("UserInfo.txt");
	if (!outFS.is_open()) {
		cout << "Error! Cannot open TXT file for reading out" << endl;
	}

	for (int i = 0; i < id.size(); ++i) {
		outFS << "User ID: " << id.at(i) << endl;
		outFS << "Password: " << pw.at(i) << endl;
		outFS << "Current Balance: " << balance.at(i) << endl;
		
		if(acType.at(i) == "s") {
			outFS << "My Stock Price: " << funds.at(i) << endl;
		}
	
		else if (acType.at(i) == "c") {
			outFS << "My Monthly Home Rent: " << funds.at(i) << endl;
		}
		outFS << endl;
	{

	outFS.close();
}
