/*
 * A real class of proxy design pattern consisting of SavingAccount's 
 * functions
 * @auther Najmeh M.A
 */

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
	bool accountHistory();
	void setBalance(double bl);
	double getBalance();
	void setPassword(string pass);
	string getPassword();
	int getID();
	void setStockNum(int stockShareNum);
	int getStockNum();
	void setStockPrice(double stockSharePrice);
	double getStockPrice();
	char whatType();
};


#endif
