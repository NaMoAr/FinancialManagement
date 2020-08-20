#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

#include <iostream>
using namespace std;
#include <string>
#include <fstream>

class Strategy : public Customer /* ?? */ {
	private:
		Customer* customer;

	public:
		Strategy();
		//constructor that reads in UserInfo.txt and loads all user info on list

		void SignOut();
		//updates all user info into UserInfo.txt when customer selects sign out
};

#endif

