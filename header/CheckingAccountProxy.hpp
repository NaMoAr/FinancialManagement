/*
 * A proxy class of proxy design pattern consisting of 
 * CheckingAccountProxy's functions
 * @auther Najmeh M.A
 */

#ifndef CHECKINGACCOUNTPROXY_HPP
#define CHECKINGACCOUNTPROXY_HPP
#include "Account.hpp"
#include "CheckingAccount.hpp"

class CheckingAccountProxy : public Account
{

private:
	CheckingAccount* ptr;
	stringstream s;
        double monthlyHomeRent = 0.0; 
	char type = 'c';
public:
        CheckingAccountProxy(){};
	CheckingAccountProxy(double initialBalance, int userID, string pass, double homeRent);
	~CheckingAccountProxy();

	stringstream* deposit(double depMoney);
        stringstream* withdraw(double withMoney);
	void logOut(stringstream* ss);
        bool accountHistory();
	void setBalance(double bl);
	double getBalance();
	void setPassword(string pass);
	string getPassword();
	int getID();
        void setMonthlyHomeRent(double homeRent);
        double getMonthlyHomeRent();
	void Menu();
	char whatType();


};

#endif // CHECKINGACCOUNTPROXY_HPP

