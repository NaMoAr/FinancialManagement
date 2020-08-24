#include "../header/CheckingAccountProxy.hpp"
#include "../header/Account.hpp"
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


CheckingAccountProxy::CheckingAccountProxy(double initialBalance, int theUserID,string pass, double homeRent)
{
	balance = initialBalance;
	userID = theUserID;
	password = pass;
	monthlyHomeRent = homeRent;
	ptr = new CheckingAccount(initialBalance, theUserID,pass, homeRent);
}

CheckingAccountProxy::~CheckingAccountProxy()
{
	
}

stringstream* CheckingAccountProxy::deposit(double depMoney, stringstream* ss)
{

	balance = getBalance() + depMoney;
	s << "Checking account, $" << depMoney << " has been deposited, " << "New Balance: $" << balance<<endl;
	ss = &s;
	cout << depMoney << " dollors has been deposited" << endl;
	return ss;
	
}



stringstream* CheckingAccountProxy::withdraw(double withMoney, stringstream* ss)
{
        if (withMoney > balance) {
		cout << "Sorry, this amount of money is over your balance."<<endl;
	}
	else if (balance - withMoney < monthlyHomeRent) {
		cout << "Sorry, you have to keep your balance greater than $"<<monthlyHomeRent<<" to pay your monthly home rent. Are you sure you still want to do this transacrion?(y/n)" << endl;
		string yn = "";
		cin >> yn;
		if (yn == "y") {
			balance = getBalance() - withMoney;
			s << "Checking account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
			ss = &s;
			cout << withMoney << " dollors has been withdrawn" << endl;
			return ss;
		}
		if (yn == "n") {
			cout << "The transaction heve been canceled." << endl;
		}
	}
	else {
		balance = getBalance() - withMoney;
		s << "Checking account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
		ss = &s;
		cout << withMoney << " dollors has been withdrawn" << endl;
		return ss;
	}
}
	


void CheckingAccountProxy::logOut(stringstream* ss)
{

	ptr->logOut(ss);
}


double CheckingAccountProxy::getBalance()
{
	return balance;
}





void CheckingAccountProxy::accountHistory()
{
	ptr->accountHistory();
}


void CheckingAccountProxy::setMonthlyHomeRent(double homeRent)
{
	monthlyHomeRent = homeRent;
	ptr->setMonthlyHomeRent(homeRent);
}

double CheckingAccountProxy::getMonthlyHomeRent()
{
	return ptr->getMonthlyHomeRent();
}


void CheckingAccountProxy::setPassword(string pass)
{
	ptr->setPassword(pass);
}

string CheckingAccountProxy::getPassword()
{
	return ptr->getPassword();
}

int CheckingAccountProxy::getID()
{
	return ptr->getID();
}
