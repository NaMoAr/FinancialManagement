#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../header/CheckingAccount.hpp"
#include "../header/Account.hpp"
#include <ctime>
#include <chrono>


using namespace std;




CheckingAccount::CheckingAccount(double initialBalance, int theUserID)
{
	balance = initialBalance;
	userID = theUserID;
	
	
}

CheckingAccount::~CheckingAccount()
{
}

stringstream* CheckingAccount::deposit(double depMoney, stringstream* ss)
{
                string id = to_string(userID);
                string filename = id + ".txt";
		std::fstream f;
		f.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
                f << ss->str();
		f.close();
	

	
	return nullptr;
}

stringstream* CheckingAccount::withdraw(double withMoney, stringstream* ss)
{
	
	        string id = to_string(userID);
		string filename = id + ".txt";
		std::fstream f;
		f.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
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
	
        string id = to_string(userID);
	string filename = id + ".txt";
	std::fstream f;
	f.open(filename);
	if (!f) {

		cout << "There is no transaction to show!" << endl;
		
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


