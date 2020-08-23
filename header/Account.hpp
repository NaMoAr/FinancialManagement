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
private:
string password = "";
		

public:
 Account() {};
 virtual ~Account() {};
 virtual void accountHistory() = 0;
 virtual void logOut(stringstream* ss) = 0;



};

#endif // ACCOUNT_HPP
