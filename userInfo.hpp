#ifndef __USERINFO_HPP__
#define __USERINFO_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class UserInfo {
	public:
		UserInfo() {};
		virtual void PrintList() = 0; // Print out all information into a file

		virtual void SaveInfo(string ac, int ID, string pass, double b, double f) = 0; // Called by CustomerList if account type is a checking account

		virtual void SaveInfo(string ac, int ID, string pass, double b, double f, double n) = 0; // Called by CustomerList if account type is a savings account

		virtual vector<vector<string>> ReadList() = 0; // Called by CustomerList to read in all info from file, store it into a vector of strings, and then return that vector of vector<string>

		virtual string PrintDebug() = 0; // Helper function for google testing

		
		vector<string> acType; // stores either a "c" for a checking account or an "s" for a savings account

		vector<string> id; // stores the user's ID

		vector<string> pw; // stores the user's password

		vector<string> balance; // stores the current balance

		vector<string> funds; // stores the monthly rent for a checking account, or stock price for a savings account

		vector<string> stock; // stores a "0" as a placeholder for the checking account, and the stock number for a savings account
};

#endif //__USERINFO_HPP__
