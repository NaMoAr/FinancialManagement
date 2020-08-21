#include "csvSave.hpp"

void CSVSave::PrintList() {
	ofstream outFS("UserInfo.csv");
	if(!outFS.is_open()) {
		cout << "Error! Cannot open CSV file for reading out" << endl;
	}

	for(int i = 0; i < id.size(); ++i) {
		outFS << id.at(i) << "," 
		      << pw.at(i) << "," 
                      << balance.at(i) << "," 
                      << budget.at(i) << "," 
                      << funds.at(i) << endl;
	}

	outFS.close();
}
