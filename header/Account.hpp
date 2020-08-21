#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include<string>
#include<sstream>
using namespace std; 


class Account
{
protected:
double balance = 0.0 ;
int userID = 0;
string password = "";
		

public:
 Account() {};
 Account(double initialBalance, string userID) {};
 virtual ~Account() {};
 virtual stringstream* deposit(double depMoney, stringstream* s) = 0;
 virtual stringstream* withdraw(double eithMoney, stringstream* s) = 0;
 virtual void transfer(double tranMoney, string giverID, string recieverID)=0;
 virtual void accountHistory() = 0;



};

#endif // ACCOUNT_HPP
