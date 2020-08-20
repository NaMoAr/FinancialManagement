#ifndef __ACCOUNTLIST_HPP__
#define __ACCOUNTLIST_HPP__

#include <unordered_map>


class AccountList {

	private: 
		
		AccountList();
		
		unordered_map database = new unordered_map;
	
	public:
	
		void createAccount();
		
		void deleteAccount();
		
		void traverseDatabase();
	
};

#endif
