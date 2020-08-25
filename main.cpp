// all proper includes
#include<csvSave.hpp>
#include<txtSave.hpp>
#include<accountList.hpp>
#include<CheckingAccount.hpp>
#include<SavingAccount.hpp>
#include<CheckingAccountProxy.hpp>
#include<SavingAccountProxy.hpp>
 

int main() {

	// make the userinfo objects
	readerOne* = new txtSave();
	readerTwo* = new csvSave();

	// make the list with userinfo objects as parametsrs
	AccountList* DATABASE = new AccountList(readerOne,readerTwo); 
	// call list interface
	DATABASE->interface();
	// program ends




}// as the program ends readerOne readerTwo and DATABASE pass out of scope and their desturctors are called which handle the desruction of the objects they contain
