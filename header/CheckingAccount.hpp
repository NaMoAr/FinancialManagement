#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP
#include "Account.h"
using namespace std;

class CheckingAccount : public Account
{


public:
	 CheckingAccount();
	 CheckingAccount(double initialBalance, string userID);
	 ~CheckingAccount();

	 stringstream* deposit(double depMoney,stringstream* s);
	 stringstream* withdraw(double depMoney, stringstream* s);
	 void transfer(double tranmoney, string giverID, string recieverID);
     void accountHistory();
	 

};

#endif // CHECKINGACCOUNT_HPP

