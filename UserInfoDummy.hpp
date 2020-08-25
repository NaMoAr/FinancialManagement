#ifndef __DUMMY_HPP__
#define __DUMMY_HPP__

#include <vector>
using namespace std;
class UserInfoDummy {
	vector<vector<string>> vec;
public:
	UserInfoDummy() {
			vec = { 
				{"s","400","1","17","500"},	//account type, balance, ID, stocks owned, stock value
				{"s","7000","2","200","45"},
				{"c","67.84","3","50"},		//account type, balance, ID, monthly dues
				{"s","5321.45","4","14","72.6"}
			};
	}
	// we need to sm=imulate the following things from the UserInfo Class
	// simulate constuctor
	// simulate a readlist output
	// verify save info inputs
	
	vector<vector<string>> ReadList(){ // Provide a sample database
			return vec;
	}
	
	void SaveInfo(string ac, int ID, string pass, double b, double f){
		std::cout << "saving account "<<ID<< " of type " <<" checking "<<" with balance: " <<b <<". Monthly rent of" << f << endl;
	}
	void SaveInfo(string ac, int ID, string pass, double b, int a, double f){
		std::cout << "saving account "<<ID<< " of type " <<" savings "<<" with balance: " <<b <<", owning "<<f << " stocks worth" << f << " each."<<endl;
	}
};
#endif