#ifndef __ACCOUNTLIST_HPP__
#define __ACCOUNTLIST_HPP__

#include <unordered_map>


class AccountList {

	private: 
		
		static AccountList* AccountList_;

		AccountList();
		
		~AccountList();

		unordered_map database = new unordered_map;
	
	public:

		AccountList(AccountList &other) = delete// we can't let the object be copyable

		void operator= (const AccountList &) = delete // we con't let the object be assignable
	
		AccountList* GetInstance(); // the public interface which manages the creation of the AccountList object

		void createAccount();
		
		void deleteAccount();
		
		void traverseDatabase();
	
};

#endif
