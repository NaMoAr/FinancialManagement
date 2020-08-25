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
	
	SavingAccountProxy(double initialBalance, int userID,string pass, int stochShareNum, double stockSharePrice);
	~SavingAccountProxy();

	stringstream* deposit(double depMoney, stringstream* ss);
	stringstream* withdraw(double withMoney, stringstream* ss);
	void logOut(stringstream* ss);       
	bool accountHistory();
	void setBalance(double bl);
	double getBalance();
	void setPassword(string pass);
	string getPassword();
	int getID();
        double fetchStockPrice();
        double calculateProfit();
	stringstream* buyStock();
   	stringstream* sellStock();
   	void setStockNum(int stockShareNum);
   	double getStockNum();
   	void setStockPrice(double stockSharePrice);
   	double getStockPrice();

};

#endif // CHECKINGACCOUNTPROXY_HPP

