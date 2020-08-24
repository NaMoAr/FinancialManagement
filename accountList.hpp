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

		void adminMenu(); // a function that helps admins navigate creation and destruction of accounts					Accessed by logIn

		void createAccount(); //  a function for admins to create new accounts in the list						Accessed by adminMenu
		
		void deleteAccount(); // a function for admins to delete accounts within the list						Accessed by adminMenu
		
		void traverseDatabase(int ID); // a helper function that allows both admins and users to search the list for a given account	Helper for login, delete and create

		void logIn(); //a function that allows users to sign into their accounts.							Accessed by interface?
	
	public:

		AccountList(AccountList &other) = delete// we can't let the object be copyable							MUST BE PUBLIC

		void operator= (const AccountList &) = delete // we con't let the object be assignable						MUST BE PUBLIC
	
		AccountList* GetInstance(); // the public interface which manages the creation of the AccountList object			MUST BE PUBLIC

		void interface(); // the public interface that allows a user to log in or quit the program					MUST BE PUBLIC

		void logOut(); // unsets the user pointer and reprompts log in									MUST BE PUBLIC - called by proxy
};

#endif
