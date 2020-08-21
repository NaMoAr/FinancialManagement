#ifndef SavingAccount_HPP
#define SavingAccount_HPP
#include<string>
#include "Account.hpp"
using namespace std;


class SavingAccount : public Account
{


public:
	;
	SavingAccount(double initialBalance, int userID);
	~SavingAccount();

	stringstream* deposit(double depMoney, stringstream* s);
	stringstream* withdraw(double depMoney, stringstream* s);
	void transfer(double tranmoney, string giverID, string recieverID);
	void accountHistory();


};


#endif
