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



SavingAccountProxy::SavingAccountProxy(double initialBalance, int theUserID)
{
	balance = initialBalance;
	userID = theUserID;
	ptr = new SavingAccount(initialBalance, theUserID);
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
		return ss;
	}

}

void SavingAccountProxy::logOut(stringstream* ss)
{
    ptr->logOut(ss);
}


double SavingAccountProxy::getBalance()
{
	return balance;
}





void SavingAccountProxy::accountHistory()
{
	ptr->accountHistory();
}


double SavingAccountProxy::fetchStockPrice() {
	double sharePrice= double( rand() % 20) + 50;
	return sharePrice;
}

void SavingAccountProxy::calculateProfit() {
	cout<<"$"<< (stockNum * fetchStockPrice()) - (stockNum * stockPrice)<<endl;
}

void SavingAccountProxy::buyStock( ) {
	
	
	stockPrice = fetchStockPrice();
	cout << "The current stock share's price is $ " << stockPrice << endl;
	cout << "Hom many stock shares would you like to but?" << endl;
	cin >> stockNum;
	if (stockNum * stockPrice > getBalance()) {
		cout << "Sorry, there is not enough money in your account." << endl;
	}
	else {
		withdraw(stockNum * stockPrice, nullptr);
	}

}

double SavingAccountProxy::getStockNum() {
	return stockNum;
}

double SavingAccountProxy::getStockPrice() {
	return stockPrice;
}

void SavingAccountProxy::sellStock() {
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
	}
}

void SavingAccountProxy::currentUserStock() {

	cout << getStockNum() << " stock share/shares of $" << getStockPrice() << endl;
}
