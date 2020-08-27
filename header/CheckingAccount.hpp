/*
 * A real class of proxy design pattern consisting of CheckingAccount's 
 * functions
 * @auther Najmeh M.A
 */

#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP
#include "Account.hpp"
using namespace std;

class CheckingAccount : public Account
{

private:
	double monthlyHomeRent;
public:
	 
	CheckingAccount(double initialBalance, int userID, string pass, double homeRent);
	~CheckingAccount();	
	void logOut(stringstream* ss);
        bool accountHistory();
	void setBalance(double bl);
	double getBalance();
        void setPassword(string pass);
	string getPassword();
	int getID();
	void setMonthlyHomeRent(double homeRent);
	double getMonthlyHomeRent();
	
};

#endif // CHECKINGACCOUNT_HPP

