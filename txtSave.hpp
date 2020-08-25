#include "userInfo.hpp"

class TXTSave : public UserInfo {
	public:
		TXTSave() : UserInfo() {};
		~TXTSave();
		void PrintList();
		void SaveInfo(string ac, int ID, string pass, double b, double f);
		vector<vector<string>> ReadList();
		string PrintDebug();
		void AddAccount(string ac, int ID, string pass, double b, double f);
		void DeleteAccount(string ac, int ID, string pass, double b, double f);
	
		vector<string> id;
		vector<string> pw;
		vector<string> acType;
		vector<string> balance;
		vector<string> funds; 
};
