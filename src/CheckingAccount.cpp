#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../header/CheckingAccount.hpp"
#include "../header/Account.hpp"
//#include <ctime>
//#include <chrono>


using namespace std;



/*
 * Constructor for CheckingAccount class
 * @param initialBalance the initial balance of checking account
 * @param theUserID the id of user
 * @param pass the password of user
 * @param homeRent the monthly home rent of the user
 */
CheckingAccount::CheckingAccount(double initialBalance, int theUserID, string pass, double homeRent)
{
	balance = initialBalance;
	userID = theUserID;
	password = pass;
	monthlyHomeRent = homeRent;
}

CheckingAccount::~CheckingAccount()
{
}
/*
 * write stringstream buffer to a text file named by user's ID
 * @param ss pointer to the stringstream buffer
 */
void CheckingAccount::logOut(stringstream* ss)
{
	string id = to_string(userID);
	string filename = id + ".txt";
        std::fstream f;
	f.open(filename,  std::fstream::in | std::fstream::out | std::fstream::app);
	if (ss != nullptr) {
		f << ss->str();
	}
	f.close();
	
}
/*
 * read the file associated with the user's ID and print it out to the console 
 * @return false if it fails to open the file, true if it opens the file and read it successfully  
 */
bool CheckingAccount::accountHistory()
{
	cout << "Today's transactions would appear in the account history the next day after the bank approval."<< endl;
	
        string id = to_string(userID);
	string filename = id + ".txt";
	std::fstream f;
	f.open(filename);
	if (!f) {

		cout << "There is no transaction to show!" << endl;
		return false;
	}


	if (cin.get() == '\n') {
		char str[2000];
		int i = 2000;

		while (f) {
			f.getline(str, i);
			if (f) cout << str << endl;


		}

		f.close();
		return true;
	}
	
	
}
/*
 * initialize the user's monthly home rent
 * @param homeRent user's monthly home rent
 */
void CheckingAccount::setMonthlyHomeRent(double homeRent)
{
	monthlyHomeRent = homeRent;
}
/*
 * give the user's monthly home rent
 * @return user's monthly home rent
 */
double CheckingAccount::getMonthlyHomeRent()
{
	return monthlyHomeRent;
}
/*
 * initialize the user's password
 * @param the user's password
 */
void CheckingAccount::setPassword(string pass)
{
	password = pass;
}
/*
 * give the user's password
 * @param user's password
 */
string CheckingAccount::getPassword()
{
	return password;
}
/*
 * give the user's ID
 * @return user's ID
 */
int CheckingAccount::getID()
{
	return userID;
}
/*
 * give the checking account's balance
 * @return the users's checking account balance
 */
double CheckingAccount::getBalance()
{
	return balance;
}
/*
 * initialize the user's checking account balance
 * @param bl the user's checking account balance 
 */
void CheckingAccount::setBalance(double bl)
{
	balance = bl;
}



