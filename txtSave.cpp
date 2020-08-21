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
		outFS << "Max Budget: " << budget.at(i) << endl;
		outFS << "Funds: " << funds.at(i) << endl;
		outFS << endl;
	{

	outFS.close();
}
