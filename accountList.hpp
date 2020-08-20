#ifndef __ACCOUNTLIST_HPP__
#define __ACCOUNTLIST_HPP__

#include <unordered_map>
#include <string>
#include <iostream>

class AccountList {

	private: 
		
		static AccountList* AccountList_; // we hold the pointer to the object

		AccountList(); // must be private so we control the instantiation of new objects of this type to maintain the singleton design pattern
		
		~AccountList(); // does it matter if I keep this priveate??

		unordered_map<int,Account*> database = new unordered_map<int,Account*>; // this is our "data" the object stores
	
		Account* userPointer = NULL;
	
		std::string adminAccess = "96a~eU=tWyVkz'4V"; // a randomly generated 16 character password to verify an admin before allowing access to admin functions

	public:

		AccountList(AccountList &other) = delete// we can't let the object be copyable

		void operator= (const AccountList &) = delete // we con't let the object be assignable
	
		AccountList* GetInstance(); // the public interface which manages the creation of the AccountList object

		void createAccount(); //  a function for admins to create new accounts in the list
		
		void deleteAccount(); // a function for admins to delete accounts within the list
		
		void traverseDatabase(); // a helper function that allows both admins and users to search the list for a given account

		Account* logIn(); //a function that allows users to sign into their accounts.
	
		void logOut(); // unsets the user pointer and reprompts log in
};

#endif
