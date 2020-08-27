#ifndef __TXTSAVE_HPP__
#define __TXTSAVE_HPP__

#include "userInfo.hpp"

class TXTSave : public UserInfo {
	public:
		TXTSave() : UserInfo() {};

		~TXTSave();

		void PrintList(); //Print all information into TXT file

		void SaveInfo(string ac, int ID, string pass, double b, double f);// Called by CustomerList to store all Checking Account info

		void SaveInfo(string ac, int ID, string pass, double b, double f, int n); //Called by CustomerList to store all Savings Account info

		vector<vector<string>> ReadList(); // Called by CustomerList, reads in info from TXT file

		string PrintDebug(); // function for googletest
};
#endif //__TXTSAVE_HPP__
