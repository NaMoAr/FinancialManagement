#ifndef __USERINFO_HPP__
#define __USERINFO_HPP__

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class UserInfo : public Account {
	private:
		Account* profile;

	public:
		UserInfo();
		//constructor that reads in UserInfo.txt and loads all user info on list
		
		~UserInfo();
	
		virtual void PrintList() {};
		//updates all user info into UserInfo.txt when customer selects sign out

	protected:
		vector<string> id;
		vector<string> pw;
		vector<string> budget; //budget tool to prevent overspending
		vector<string> balance; //current balance in account
		vector<string> funds; //monthlyrent for checkings, stocks for savings
};

#endif

