#ifndef CHECKINGACCOUNTPROXY_HPP
#define CHECKINGACCOUNTPROXY_HPP
#include "Account.h"
#include "CheckingAccount.h"

class CheckingAccountProxy : public Account
{

private:
	CheckingAccount* ptr;
	stringstream s;

public:
	CheckingAccountProxy();
	CheckingAccountProxy(double initialBalance, string userID);
	~CheckingAccountProxy();

	stringstream* deposit(double depMoney, stringstream* ss);
    void logOut(string depOrwith, double Money, stringstream* ss);
    stringstream* withdraw(double withMoney, stringstream* ss);
    void transfer(double tranmoney, string giverID, string recieverID);
    double getBalance();

	

	
	void accountHistory();

};

#endif // CHECKINGACCOUNTPROXY_HPP

