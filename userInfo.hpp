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
		virtual void PrintList() = 0;
		virtual void SaveInfo(string ac, int ID, string pass, double b, double f) = 0;
		virtual vector<vector<string>> ReadList() = 0;
		virtual string PrintDebug() = 0;
		virtual void AddAccount(string ac, int ID, string pass, double b, double f) = 0;
		virtual void DeleteAccount(string ac, int ID, string pass, double b, double f) = 0;
};

#endif

