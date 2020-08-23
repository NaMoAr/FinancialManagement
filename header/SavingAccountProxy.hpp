#ifndef SAVINGACCOUNTPROXY_HPP
#define SAVINGACCOUNTPROXY_HPP
#include "Account.hpp"
#include "SavingAccount.hpp"

class SavingAccountProxy : public Account
{

private:
	SavingAccount* ptr;
	stringstream s;
        int stockNum = 0 ;
	double stockPrice = 0.0;
public:
	
	SavingAccountProxy(double initialBalance, int userID);
	~SavingAccountProxy();

	stringstream* deposit(double depMoney, stringstream* ss);
	void logOut(stringstream* ss);
	stringstream* withdraw(double withMoney, stringstream* ss);
        double getBalance();
	void accountHistory();
        double fetchStockPrice();
        void calculateProfit();
        void buyStock();
        double getStockNum();
        double getStockPrice();
        void sellStock();
	void currentUserStock();

};

#endif // CHECKINGACCOUNTPROXY_HPP

