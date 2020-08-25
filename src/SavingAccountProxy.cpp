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

stringstream* SavingAccountProxy::deposit(double depMoney, stringstream* ss)
{

	balance = getBalance() + depMoney;
	s << "Saving account, $" << depMoney << " has been deposited, " << "New Balance: $" << balance << endl;
	ss = &s;
	cout << depMoney << " dollors has been deposited" << endl;
	setBalance(balance);
	return ss;

}



stringstream* SavingAccountProxy::withdraw(double withMoney, stringstream* ss)
{
	balance = getBalance() - withMoney;
	if (withMoney > balance) {
		cout << "Sorry, this amount of money is over your balance." << endl;
	}
	else {
		s << "Saving account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
		ss = &s;
		cout << withMoney << " dollors has been withdrawn" << endl;
		setBalance(balance);
		return ss;	
                }

}

void SavingAccountProxy::logOut(stringstream* ss)
{
    ptr->logOut(ss);
}

void SavingAccountProxy::setBalance(double bl) {
	ptr->setBalance(bl);
}

double SavingAccountProxy::getBalance()
{
	return ptr->getBalance();
}





bool SavingAccountProxy::accountHistory()
{
	return ptr->accountHistory();
}


double SavingAccountProxy::fetchStockPrice() {
	double sharePrice= double( rand() % 20) + 50;
	return sharePrice;
}

double SavingAccountProxy::calculateProfit() {
	return (getStockNum() * fetchStockPrice()) - (getStockNum() * getStockPrice());
}

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
		ss = withdraw(stockNum * stockPrice, nullptr);
		setStockNum(getStockNum() + stockNum);
		setStockPrice((getStockPrice() + stockPrice)/2);
	}
	return ss;
}


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
		deposit(sellNum * stockPrice, nullptr);
		setStockNum(getStockNum() - sellNum);
	}
	return ss;
}

void SavingAccountProxy::setStockNum(int stockShareNum) {
	ptr->setStockNum(stockShareNum);
}

double SavingAccountProxy::getStockNum() {
	return ptr->getStockNum();
}

void SavingAccountProxy::setStockPrice(double stockSharePrice) {
	ptr->setStockPrice(stockSharePrice);
}

double SavingAccountProxy::getStockPrice() {
	return ptr->getStockPrice();
}


void SavingAccountProxy::setPassword(string pass)
{
	ptr->setPassword(pass);
}

string SavingAccountProxy::getPassword()
{
	return ptr->getPassword();
}

int SavingAccountProxy::getID()
{
	return ptr->getID();
}



