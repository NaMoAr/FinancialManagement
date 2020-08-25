#ifndef __ACCOUNTDUMMY_HPP__
#define __ACCOUNTDUMMY_HPP__


class AccountDummy {
	
// verify that the constructor inputs are correct

AccountDummy(double initialBalance, int theUserID,string pass, int stochShareNum, double stockSharePrice){
	std::cout << "creating a checking account object with the following values -  balance: " << initialBalance << " ID: " << theUserID << " password: " << pass << " with"<<stochShareNum<<" stocks each bought for " << stockSharePrice<< endl;
}


AccountDummy(double initialBalance, int theUserID, string pass, double homeRent){
	std::cout << "creating a saving account object with the following values -  balance: " << initialBalance << " ID: " << theUserID << " password: " << pass << " and rent: " << homeRent<< endl;
}


};
#endif
