#include "../header/CheckingAccountProxy.hpp"
#include "../header/Account.hpp"
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


CheckingAccountProxy::CheckingAccountProxy(double initialBalance, int theUserID)
{
	balance = initialBalance;
	userID = theUserID;
	ptr = new CheckingAccount(initialBalance, theUserID);
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
	


void CheckingAccountProxy::logOut(string depOrwith, double Money, stringstream* ss)
{

	if (depOrwith == "deposit") {
		ptr->deposit(Money, ss);
	}
	if (depOrwith == "withdraw") {
		ptr->withdraw(Money, ss);
	}

}

void CheckingAccountProxy::transfer(double tranMoney, string giverID, string recieverID)
{
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
}

double CheckingAccountProxy::getMonthlyHomeRent()
{
	return monthlyHomeRent;
}



