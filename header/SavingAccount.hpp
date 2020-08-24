#ifndef SavingAccount_HPP
#define SavingAccount_HPP
#include<string>
#include "Account.hpp"
using namespace std;


class SavingAccount : public Account
{

private:
	int stockNum = 0;
	double stockPrice = 0.0;
public:
	
	SavingAccount(double initialBalance, int userID,string pass, int stochShareNum, double stockSharePrice);
	~SavingAccount();
        void logOut(stringstream* ss);
	void accountHistory();
	double getBalance();
	void setPassword(string pass);
	string getPassword();
	int getID();
	void setStockNum(int stockShareNum);
	double getStockNum();
	void setStockPrice(double stockSharePrice);
	double getStockPrice();

};


#endif
