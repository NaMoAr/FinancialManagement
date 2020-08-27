#include "../header/SavingAccountProxy.hpp"
#include "../header/SavingAccount.hpp"
#include "../header/Account.hpp"
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
using namespace std;


/*
 * Constructor for SavingAccountProxy class
 * @param initialBalance the initial balance of checking account
 * @param theUserID the id of user
 * @param pass the password of user
 * @param stochShareNum the number of stock shares that the user have bought
 * @param stockSharePrice the price of stock shares that the user have bought
 */
SavingAccountProxy::SavingAccountProxy(double initialBalance, int theUserID,string pass, int stochShareNum, double stockSharePrice)
{
	balance = initialBalance;
	userID = theUserID;
	password = pass;
	stockNum = stochShareNum;
	stockPrice = stockSharePrice;
	ptr = new SavingAccount(initialBalance, theUserID, pass, stochShareNum, stockSharePrice);
}

SavingAccountProxy::~SavingAccountProxy()
{

}
/*
 write the new balance ofter each transaction depostie into a stringstream buffer
 @param depMoney the money value that the user wants to deposit into his saving account 
 @return         a pointer to the stringstream buffer that holds transaction deposite history
 */
stringstream* SavingAccountProxy::deposit(double depMoney)
{
	stringstream* ss;
	balance = getBalance() + depMoney;
	s << "Saving account, $" << depMoney << " has been deposited, " << "New Balance: $" << balance << endl;
	ss = &s;
	cout << depMoney << " dollors has been deposited" << endl;
	setBalance(balance);
	return ss;

}


/*
 * write the new balance ofter each transaction withdraw into a stringstream buffer
 * @param withMoney the money value that the user wants to withdraw from his saving account
 * @return         a pointer to the stringstream buffer that holds transaction withdraw history
 */
stringstream* SavingAccountProxy::withdraw(double withMoney)
{
	stringstream* ss;
	balance = getBalance() - withMoney;
	if (withMoney > balance) {
		cout << "Sorry, this amount of money is over your balance." << endl;
		ss = nullptr;
		return ss;
	}
	else {
		s << "Saving account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
		ss = &s;
		cout << withMoney << " dollors has been withdrawn" << endl;
		setBalance(balance);
		return ss;	
                }

}
/*
 * calls the logOut function from the real class SavingAccount
 * @param ss the stringstream buffer that holds all the transactions of the saving account
 */
void SavingAccountProxy::logOut(stringstream* ss)
{
    ptr->logOut(ss);
}
/*
 * calls the setBalance function from the real class SavingAccount
 * @param bl the users's saving account balance
 */
void SavingAccountProxy::setBalance(double bl) {
	ptr->setBalance(bl);
}
/*
 * calls the getBalance function from the real class SavingAccount
 * @return the users's saving account balance
 */
double SavingAccountProxy::getBalance()
{
	return ptr->getBalance();
}




/*
 * calls the accountHistory function from the real class SavingAccount
 * @return false if it fails to open the file, true if it opens the file and read it successfully
 */
bool SavingAccountProxy::accountHistory()
{
	return ptr->accountHistory();
}

/*
 * generate a random number between 50 to 70 as the current stock share price
 * @return the current price of stock share
 */
double SavingAccountProxy::fetchStockPrice() {
	double sharePrice= double( rand() % 20) + 50;
	return sharePrice;
}
/*
 * calculate the profit based on the current share price
 * @retrun the user's profit at the current time 
 */
double SavingAccountProxy::calculateProfit() {
	return (getStockNum() * fetchStockPrice()) - (getStockNum() * getStockPrice());
}
/*
 * provide the current price of the stock share, reasign the user's number and price of stock shares 
 * upon a buying, withdraw money from the user saving account uopn buying
 * @return pointer to stringstram buffer which hold the transactions that happened when the user buy stocks  
 */
stringstream* SavingAccountProxy::buyStock( ) {
	
	stringstream* ss = nullptr;
	stockPrice = fetchStockPrice();
	cout << "The current stock share's price is $ " << stockPrice << endl;
	cout << "Hom many stock shares would you like to but?" << endl;
	cin >> stockNum;
	if (stockNum * stockPrice > getBalance()) {
		cout << "Sorry, there is not enough money in your account." << endl;
	}
	else {
		ss = withdraw(stockNum * stockPrice);
		setStockNum(getStockNum() + stockNum);
		setStockPrice((getStockPrice() + stockPrice)/2);
	}
	return ss;
}

 /*
 * provide the current price of the stock share, reasign the user's number and price of stock shares
 * upon a selling, deposit money from the user saving account uopn selling
 * @return pointer to stringstram buffer which hold the transactions that happened when the user sell stocks
 */

stringstream* SavingAccountProxy::sellStock() {
	stringstream* ss = nullptr;
	int sellNum = 0;
	stockPrice = fetchStockPrice();
	cout << "The current stock share's price is $ " << stockPrice << endl;
	cout << "How many stock shares would you like to sell?" << endl;
	cin >> sellNum;
	if (sellNum > stockNum) {
		cout << "Sorry, you only have " << stockNum << " stock shares to sell" << endl;
	}
	else {
		stockNum = stockNum - sellNum;
		deposit(sellNum * stockPrice);
		setStockNum(getStockNum() - sellNum);
	}
	return ss;
}
/*
 * calls the setStockNum function from the real class SavingAccount
 * @param stockShareNum number of stock shares that the user have bought
 */
void SavingAccountProxy::setStockNum(int stockShareNum) {
	ptr->setStockNum(stockShareNum);
}
/*
 * calls the getStockNum function from the real class SavingAccount
 * @return number of stock shares that the user have bought
 */
int SavingAccountProxy::getStockNum() {
	return ptr->getStockNum();
}
/*
 * calls the setStockPrice function from the real class SavingAccount
 * @param stockSharePrice price of stock shares that the user have bought
 */
void SavingAccountProxy::setStockPrice(double stockSharePrice) {
	ptr->setStockPrice(stockSharePrice);
}
 /*
 * calls the getStockPrice function from the real class SavingAccount
 * @return price of stock shares that the user have bought
 */
double SavingAccountProxy::getStockPrice() {
	return ptr->getStockPrice();
}

/*
 * calls the setPassword function from the real class SavingAccount
 * @param the user's password
 */
void SavingAccountProxy::setPassword(string pass)
{
	ptr->setPassword(pass);
}
/*
 * calls the getPassword function from the real class SavingAccount
 * @return the user's password
 */
string SavingAccountProxy::getPassword()
{
	return ptr->getPassword();
}
/*
 * calls the getID function from the real class SavingAccount
 * @return the user's ID
 */
int SavingAccountProxy::getID()
{
	return ptr->getID();
}

// calls menu function to allow user access to class functions
void SavingAccountProxy::Menu(){
 string option = "";
    double dep = 0.0;
    double with = 0.0;
    stringstream* ss = nullptr;
    string accountType = "";
    string pass = "";

	do {           
            cout << "1.Balance" << endl;
            cout << "2.deposit" << endl;
            cout << "3.withdraw" << endl;
            cout << "4.Account History" << endl;
            cout << "5.My Stock Shares" << endl;
            cout << "6.See My Current Profit" << endl;
            cout << "7.Sell Stock Share" << endl;
            cout << "8.Buy Stock Share" << endl;
            cout << "9.Change Password" << endl;
            cout << "10.logout" << endl;
            cin >> option;
            if (option == "1") {
                cout << "$" << getBalance() << endl;
            }
            if (option == "2") {
                cout << "How much do you want to deposit?" << endl;
                cin >> dep;
                ss = deposit(dep);
            }
            if (option == "3") {
                cout << "How much do you want to withdraw?" << endl;
                cin >> with;
                ss = withdraw(with);
            }
            if (option == "4") {
                accountHistory();
            }
            if (option == "5") {
                cout << getStockNum() << " stock share/shares of $" << getStockPrice() << endl;
            }
            if (option == "6") {
		 cout << "$" << calculateProfit() << endl;
            }
            if (option == "7") {
                ss = sellStock();
            }
            if (option == "8") {
                ss = buyStock();
            }
            if (option == "9") {
                cout << "Please enter your new password" << endl;
                cin >> pass;
                setPassword(pass);
                cout << "Your password has been changed to " << getPassword() << endl;
            }
        } while (option != "10");
            if (option == "10") {
                logOut(ss);// call container logout
                cout << "You have logged out successfully" << endl;  
            }
}

char SavingAccountProxy::whatType () {return's';} //helper function so the list can detemine account type
