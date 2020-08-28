#ifndef __ACCOUNTLIST_HPP__
#define __ACCOUNTLIST_HPP__

#include <unordered_map>
#include <string>
#include <iostream>
#include "csvSave.hpp"
#include "txtSave.hpp"
#include "CheckingAccountProxy.hpp"
#include "SavingAccountProxy.hpp"

using namespace std;
class AccountList {

	private: 
		
		static AccountList* AccountList_; // we hold the pointer to the object This is supposed to be static but will not compile when it is, readon unkown

		AccountList(UserInfo* readerOne, UserInfo* readerTwo); // must be private so we control the instantiation of new objects of this type to maintain the singleton design pcattern
		
		~AccountList(); // kept private to ensure that the object is only destroyed on shut down

		unordered_map<int,Account*>* database = new unordered_map<int,Account*>(); // this is our "data" the object stores
	
		Account* userPointer = nullptr; // this pointer holds the account we are logged into, this is useful when saving individual account data.
	
		UserInfo* rTwo; // a vector that holds pointers to objects that save the database in different filetypes, to be populated in .cpp
		UserInfo* rOne;
	
		std::string adminAccess = "96a~eU=tWyVkz'4V"; // a randomly generated 16 character password to verify an admin before allowing access to admin functions TODO: !!BEYOND THE SCOPE OF THIS VERSION OF THE PROJECT!! use a tool to periodicall generate a new admin access code which is available only to the administrator.

		void adminMenu(); // a function that helps admins navigate creation and destruction of accounts					Accessed by interface

		void createAccount(); //  a function for admins to create new accounts in the list						Accessed by adminMenu
		
		void deleteAccount(); // a function for admins to delete accounts within the list						Accessed by adminMenu
		
		Account* traverseDatabase(int ID); // a helper function that allows both admins and users to search the list for a given account	Helper for login, delete and create

		void logIn(); //a function that allows users to sign into their accounts.							Accessed by interface
	
	public:

		AccountList(AccountList &other) = delete;// we can't let the object be copyable							MUST BE PUBLIC

		void operator= (const AccountList &) = delete; // we con't let the object be assignable						MUST BE PUBLIC
	
		AccountList* GetInstance(UserInfo*, UserInfo*); // the public interface which creates  AccountList object		MUST BE PUBLIC

		void interface(); // the public interface that allows a user to log in or quit the program					MUST BE PUBLIC

		

		int size(); //test function to verifgy size of the list
};

#endif
