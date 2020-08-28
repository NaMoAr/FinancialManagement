#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../header/SavingAccount.hpp"
#include "../header/Account.hpp"


using namespace std;

/*
 * Constructor for SavingAccount class
 * @param initialBalance the initial balance of checking account
 * @param theUserID the id of user
 * @param pass the password of user
 * @param stochShareNum the number of stock shares that the user have bought
 * @param stochSharePrice the price of stock shares that the user have bought
 */
SavingAccount::SavingAccount(double initialBalance, int theUserID,string pass, int stochShareNum, double stockSharePrice)
{
	balance = initialBalance;
	userID = theUserID;
	password = pass;
	stockNum = stochShareNum;
	stockPrice = stockSharePrice;

}

SavingAccount::~SavingAccount()
{
	//cout << "Saving Account destructor" << endl;
}
/*
 * write stringstream buffer to a text file named by user's ID
 * @param ss pointer to the stringstream buffer
 */
void SavingAccount::logOut(stringstream* ss)
{
	string id = to_string(userID);
	string filename ="histories/"+ id + ".txt";
	std::fstream f;
	f.open(filename, std::fstream::in | std::fstream::out | std::fstream::app );
	if (ss != nullptr) {
		f << ss->str();
	}
	f.close();
	
}
/*
 * read the file associated with the user's ID and print it out to the console 
 * @return false if it fails to open the file, true if it opens the file and read it successfully  
 */
bool SavingAccount::accountHistory()
{
	cout << "Today's transactions would appear in the account history the next day after the bank approval." << endl;

	string id = to_string(userID);
	string filename ="histories/"+ id + ".txt";
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
 * initialize the number of stock shares that the user have bought
 * @param stockShareNum number of stock shares that the user have bought
 */
void SavingAccount::setStockNum(int stockShareNum) {
	stockNum = stockShareNum;
}
/*
 * give the number of stock shares that the user have bought
 * @return number of stock shares that the user have bought
 */
int SavingAccount::getStockNum() {
	return stockNum;
}
 /*
 * initialize the price of stock shares that the user have bought
 * @param stockSharePrice price of stock shares that the user have bought
 */
void SavingAccount::setStockPrice(double stockSharePrice) {
	stockPrice = stockSharePrice;
}
/*
 * give the price of stock shares that the user have bought
 * @return price of stock shares that the user have bought
 */
double SavingAccount::getStockPrice() {
	return stockPrice;
}
/*
 * initialize the user's password
 * @param the user's password
 */
void SavingAccount::setPassword(string pass)
{
	password = pass;
}
/*
 * give the user's password
 * @param user's password
 */
string SavingAccount::getPassword()
{
	return password;
}
/*
 * give the user's ID
 * @return user's ID
 */
int SavingAccount::getID()
{
	return userID;
}
/*
 * initialize the user's saving account balance
 * @param bl the user's saving account balance 
 */
void SavingAccount::setBalance(double bl)
{
	balance = bl;
}
/*
 * give the saving account's balance
 * @return the users's saving account balance
 */
double SavingAccount::getBalance()
{
	return balance;
}

char SavingAccount::whatType() {return'S';} // helper function to help the list determin account types for stroragevchar whatType() {return'C'} // helper function to help the list determin account types for strorage
