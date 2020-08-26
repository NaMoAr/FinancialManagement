#ifndef __ACCOUNTDUMMY_HPP__
#define __ACCOUNTDUMMY_HPP__


class AccountDummy {
double bal = 0;
int id = 0;
string p = "";
int ssn = 0;
int ssp = 0;
	// verify that the constructor inputs are correct
public:
	AccountDummy(double b, int I,string pass, int stockN, double stockPrice){
		bal = b;
		id = I;
		p = pass;
		ssn = stockN;
		ssp = stockPrice;	
	
		std::cout << "creating a checking account object with the following values -  balance: " << b << " ID: " << I << " password: " << pass << " with"<<stockN<<" stocks each bought for " << stockPrice<< endl;
			}

	
	
	AccountDummy(double initialBalance, int theUserID, string pass, double homeRent){
		std::cout << "creating a saving account object with the following values -  balance: " << initialBalance << " ID: " << theUserID << " password: " << pass << " and rent: " << homeRent<< endl;
	}
	void Menu() {
		std::cout << "does some stuff in the account then logs out to you" << endl;
		return;
	}
	
	string getPassword() {
		return p;
	}
	
	int getID(){
		return id;
	}

	double getBalance(){
		return bal;
	}

	int getStockNum(){
		return ssn;
	}

	double getStockPrice() {
		return ssp;
	}
};
#endif
