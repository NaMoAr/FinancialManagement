#ifndef SavingAccount_HPP
#define SavingAccount_HPP
#include<string>
#include "Account.hpp"
using namespace std;


class SavingAccount : public Account
{


public:
	
	SavingAccount(double initialBalance, int userID);
	~SavingAccount();
        void logOut(stringstream* ss);
	void accountHistory();


};


#endif
