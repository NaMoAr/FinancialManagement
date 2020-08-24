#ifndef __USERINFO_HPP__
#define __USERINFO_HPP__

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class UserInfo {
	public:
		UserInfo(); //constructor 
		
		~UserInfo(); //destructor

		void SaveInfo(int ID, string pass, double b, double f); //called by Account() upon signing out to save new changes

		vector<vector<string>> ReadList(); //called by AccountList to pass over all info read in from list


	protected:
		vector<string> acType; //classifies as c or s for checking or savings

		vector<string> id; //user id
		
		vector<string> pw; //password

		vector<string> balance; //current balance in account

		vector<string> funds; //monthlyrent for checkings, stocks for savings

		virtual void PrintList() = 0; //later called by CSVSave and TXTSave subclasses
};

#endif

