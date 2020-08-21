#include "SavingAccountProxy.hpp"
#include"SavingAccount.hpp"
#include "Account.hpp"
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



SavingAccountProxy::SavingAccountProxy(double initialBalance, int theUserID)
{
	balance = initialBalance;
	userID = theUserID;
	ptr = new SavingAccount(initialBalance, theUserID);
}

SavingAccountProxy::~SavingAccountProxy()
{

}

stringstream* SavingAccountProxy::deposit(double depMoney, stringstream* ss)
{

	balance = getBalance() + depMoney;
	s << "Saving account, $" << depMoney << " has been deposited, " << "New Balance: $" << balance << endl;
	ss = &s;
	cout << depMoney << " dollors has been deposited" << endl;
	return ss;

}



stringstream* SavingAccountProxy::withdraw(double withMoney, stringstream* ss)
{
	balance = getBalance() - withMoney;
	if (withMoney > balance) {
		cout << "Sorry, this amount of money is over your balance." << endl;
	}
	else {
		s << "Saving account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
		ss = &s;
		cout << withMoney << " dollors has been withdrawn" << endl;
		return ss;
	}

}

void SavingAccountProxy::logOut(string depOrwith, double Money, stringstream* ss)
{

	if (depOrwith == "deposit") {
		ptr->deposit(Money, ss);
	}
	if (depOrwith == "withdraw") {
		ptr->withdraw(Money, ss);
	}

}

void SavingAccountProxy::transfer(double tranMoney, string giverID, string recieverID)
{
}

double SavingAccountProxy::getBalance()
{
	return balance;
}





void SavingAccountProxy::accountHistory()
{
	ptr->accountHistory();
}

