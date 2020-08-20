#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CheckingAccount.h"
#include "Account.h"
#include <ctime>
#include <chrono>


using namespace std;



CheckingAccount::CheckingAccount()
{
}

CheckingAccount::CheckingAccount(double initialBalance, string theUserID)
{
	balance = initialBalance;
	userID.assign(theUserID);
	
	
}

CheckingAccount::~CheckingAccount()
{
}

stringstream* CheckingAccount::deposit(double depMoney, stringstream* ss)
{
	
		string filename = userID + ".txt";
		fstream f;
		f.open(filename, ios_base::app);
		f << ss->str();
		f.close();
	
	
	return nullptr;
}

stringstream* CheckingAccount::withdraw(double withMoney, stringstream* ss)
{
	
	
		string filename = userID + ".txt";
		fstream f;
		f.open(filename, ios_base::app);
		f << ss->str();
		f.close();
		return nullptr;
    
}

void CheckingAccount::transfer(double tranMoney, string giverID, string recieverID)
{

}




void CheckingAccount::accountHistory()
{
	cout << "Today's transactions would appear in the account history the next day after the bank approval."<< endl;
	

	string filename = userID + ".txt";
	fstream f;
	f.open(filename);
	if (!f) {

		cout << "Cannot open the file!" << endl;
		
	}


	if (cin.get() == '\n') {
		char str[2000];
		int i = 2000;

		while (f) {
			f.getline(str, i);
			if (f) cout << str << endl;


		}

		f.close();
	}
	
	
	

}


