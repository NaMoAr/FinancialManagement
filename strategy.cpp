#include "customerList.hpp"

Strategy::Strategy() {
	ifstream fn(UserInfo.txt);
	string s;

	if(!fn.is_open()) {
		cout << "Cannot open UserInfo.txt" << endl;
		return 1;
	}

	while (fn >> s) {
		//ID
		//	call constructor to set as a pointer
		//password
		//account balance
		//get MaxTransferWithdrawal
		//get MonthlyHomeRent
		fn >> s;
	}
	fn.close();
}

void Strategy::SignOut(Profile/Customer* P) { //have a parameter that is a pointer to the customer's profile?
	ofstream fn(UserInfo.txt);
	string s;

	if(!fn.is_open()) {
		cout << "Cannot open UserInfo.txt" << endl;
		return 1;
	}

	//get profile name
	//go through list
	//if cannot fine name, add profile to the end of the list
	//else update the information
	//if no info is stored, i.e. user has a checkings but not savings, set as blank string
	while(fn.get(s)) {
		if (s == P->getID()) {
			//update file
		}

		else {
			//new customer info
		}
	}

	fn.close();
}
