/**
 * An interface that includes the common functions of its subclasses
 * @auther Najmeh M.A
 */
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
 virtual ~Account() {};
 virtual bool accountHistory() = 0;
 virtual void logOut(stringstream* ss) = 0;
 virtual void setBalance(double bl) = 0;
 virtual double getBalance() = 0;
 virtual void setPassword(string pass) = 0;
 virtual string getPassword() = 0;
 virtual int getID() = 0;
 virtual void Menu() {};
 virtual char whatType()=0;  // a function used by accountList to identify types of accounts for storace
};

#endif // ACCOUNT_HPP
