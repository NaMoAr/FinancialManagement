#include "CheckingAccountProxy.h"
#include "Account.h"
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

CheckingAccountProxy::CheckingAccountProxy()
{
}

CheckingAccountProxy::CheckingAccountProxy(double initialBalance, string theUserID)
{
	balance = initialBalance;
	userID.assign(theUserID);
	ptr = new CheckingAccount(initialBalance, theUserID);
}

CheckingAccountProxy::~CheckingAccountProxy()
{
	
}

stringstream* CheckingAccountProxy::deposit(double depMoney, stringstream* ss)
{

	balance = getBalance() + depMoney;
	s << "Checking account, $" << depMoney << " has been deposited, " << "New Balance: $" << balance<< endl;
	ss = &s;
	cout << depMoney << " dollors has been deposited" << endl;
	return ss;
	
}



stringstream* CheckingAccountProxy::withdraw(double withMoney, stringstream* ss)
{
	balance = getBalance() - withMoney;
	if (withMoney > balance) {
		cout << "Sorry, this amount of money is over your balance."<<endl;
	}
	else {
		s << "Checking account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
		ss = &s;
		cout << withMoney << " dollors has been withdrawn" << endl;
		return ss;
	}
	
}

void CheckingAccountProxy::logOut(string depOrwith, double Money, stringstream* ss)
{

	if (depOrwith == "deposite") {
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
