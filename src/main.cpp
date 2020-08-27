// all proper includes
#include"../header/userInfo.hpp"
#include"../header/csvSave.hpp"
#include"../header/txtSave.hpp"
#include"../header/accountList.hpp"
#include"../header/CheckingAccount.hpp"
#include"../header/SavingAccount.hpp"
#include"../header/CheckingAccountProxy.hpp"
#include"../header/SavingAccountProxy.hpp"
 

int main() {

	// make the userinfo objects
	TXTSave* readerOne =  new TXTSave();
	CSVSave* readerTwo =  new CSVSave();
	// make the list with userinfo objects as parametsrs
	AccountList* DATABASE = DATABASE->GetInstance(readerOne, readerTwo);
	// call list interface
	DATABASE->interface();
	// program ends




}// as the program ends readerOne readerTwo and DATABASE pass out of scope and their desturctors are called which handle the desruction of the objects they contain
