#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../header/CheckingAccount.hpp"
#include "../header/Account.hpp"
//#include <ctime>
//#include <chrono>


using namespace std;




CheckingAccount::CheckingAccount(double initialBalance, int theUserID, string pass, double homeRent)
{
	balance = initialBalance;
	userID = theUserID;
	password = pass;
	monthlyHomeRent = homeRent;
}

CheckingAccount::~CheckingAccount()
{
}

void CheckingAccount::logOut(stringstream* ss)
{
	string id = to_string(userID);
	string filename = id + ".txt";
        std::fstream f;
	f.open(filename,  std::fstream::in | std::fstream::out | std::fstream::app);
	if (ss != nullptr) {
		f << ss->str();
	}
	f.close();
	
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

void CheckingAccount::setMonthlyHomeRent(double homeRent)
{
	monthlyHomeRent = homeRent;
}

double CheckingAccount::getMonthlyHomeRent()
{
	return monthlyHomeRent;
}

void CheckingAccount::setPassword(string pass)
{
	password = pass;
}

string CheckingAccount::getPassword()
{
	return password;
}

int CheckingAccount::getID()
{
	return userID;
}

double CheckingAccount::getBalance()
{
	return balance;
}

