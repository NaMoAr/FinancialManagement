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
public:
	
	CheckingAccountProxy(double initialBalance, int userID);
	~CheckingAccountProxy();

	stringstream* deposit(double depMoney, stringstream* ss);
        void logOut(stringstream* ss);
        stringstream* withdraw(double withMoney, stringstream* ss);
        double getBalance();
        void accountHistory();
        void setMonthlyHomeRent(double homeRent);
        double getMonthlyHomeRent();




};

#endif // CHECKINGACCOUNTPROXY_HPP

