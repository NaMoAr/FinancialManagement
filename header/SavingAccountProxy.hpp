#ifndef SAVINGACCOUNTPROXY_HPP
#define SAVINGACCOUNTPROXY_HPP
#include "Account.hpp"
#include "SavingAccount.hpp"

class SavingAccountProxy : public Account
{

private:
	SavingAccount* ptr;
	stringstream s;

public:
	
	SavingAccountProxy(double initialBalance, int userID);
	~SavingAccountProxy();

	stringstream* deposit(double depMoney, stringstream* ss);
	void logOut(string depOrwith, double Money, stringstream* ss);
	stringstream* withdraw(double withMoney, stringstream* ss);
	void transfer(double tranmoney, string giverID, string recieverID);
	double getBalance();
	void accountHistory();

};

#endif // CHECKINGACCOUNTPROXY_HPP

