#include"../header/csvSave.hpp"
#include"../header/txtSave.hpp"
#include"../header/accountList.hpp"
#include"../header/CheckingAccount.hpp"
#include"../header/SavingAccount.hpp"
#include"../header/CheckingAccountProxy.hpp"
#include"../header/SavingAccountProxy.hpp"
 

int main() {

	// make the userinfo objects
	UserInfo* readerOne =  new TXTSave();
	UserInfo* readerTwo =  new CSVSave();
	// make the list with userinfo objects as parametsrs
	AccountList* DATABASE = DATABASE->GetInstance(readerOne, readerTwo);
	// call list interface
	DATABASE->interface();
	// program ends


  return 0;

}// as the program ends readerOne readerTwo and DATABASE pass out of scope and their desturctors are called which handle the desruction of the objects they contain
