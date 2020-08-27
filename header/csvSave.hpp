#ifndef __CSVSAVE_HPP__
#define __CSVSAVE_HPP__

#include "userInfo.hpp"

class CSVSave : public UserInfo {
	public:
		CSVSave() : UserInfo() {};

		~CSVSave();

		void PrintList(); //Print all information into CSV file

		void SaveInfo(string ac, int ID, string pass, double b, double f); //Called by CustomerList to store Checking Account Info

		void SaveInfo(string ac, int ID, string pass, double b, double f, int n); //Called by CustomerList to store Savings Account Info

		vector<vector<string>> ReadList(); //Called by CustomerList, reads in info from CSV file

		string PrintDebug(); //function for googletest
};
#endif //__CSVSAVE_HPP__
