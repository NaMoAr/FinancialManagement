#include "userInfo.hpp"

class CSVSave : public UserInfo {
	public:
		CSVSave() : UserInfo() {};
		~CSVSave();
		void PrintList();
		void SaveInfo(string ac, int ID, string pass, double b, double f);
		vector<vector<string>> ReadList();
		string PrintDebug();
		void AddAccount(string ac, int ID, string pass, double b, double f);
		void DeleteAccount(string ac, int ID, string pass, double b, double f);

		vector<string> acType;
		vector<string> id;
		vector<string> pw;
		vector<string> balance;
		vector<string> funds;

};
		
