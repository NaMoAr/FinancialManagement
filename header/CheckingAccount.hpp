#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP
#include "Account.hpp"
using namespace std;

class CheckingAccount : public Account
{


public:
	 
	 CheckingAccount(double initialBalance, int userID);
	 ~CheckingAccount();
         void logOut(stringstream* ss);
         void accountHistory();
	 

};

#endif // CHECKINGACCOUNT_HPP

