#include "../header/CheckingAccountProxy.hpp"
#include "../header/Account.hpp"
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*
 * Constructor for CheckingAccountProxy class
 * @param initialBalance the initial balance of proxy checking account
 * @param theUserID the id of user
 * @param pass the password of user
 * @param homeRent the monthly home rent of the user
 */
CheckingAccountProxy::CheckingAccountProxy(double initialBalance, int theUserID,string pass, double homeRent)
{
	balance = initialBalance;
	userID = theUserID;
	password = pass;
	monthlyHomeRent = homeRent;
	ptr = new CheckingAccount(initialBalance, theUserID,pass, homeRent);
}

CheckingAccountProxy::~CheckingAccountProxy()
{
	
}
/*
 * write the new balance ofter each transaction depostie into a stringstream buffer
 * @param depMoney the money value that the user wants to deposit into his checking account 
 * @return         a pointer to the stringstream buffer that holds transaction deposite history
 */
stringstream* CheckingAccountProxy::deposit(double depMoney)
{
	stringstream* ss;
	balance = getBalance() + depMoney;
	s << "Checking account, $" << depMoney << " has been deposited, " << "New Balance: $" << balance<<endl;
	ss = &s;
	cout << depMoney << " dollors has been deposited" << endl;
	setBalance(balance);
	return ss;
	
}


/*
 * write the new balance ofter each transaction withdraw into a stringstream buffer
 * @param withMoney the money value that the user wants to withdraw from his checking account
 * @return         a pointer to the stringstream buffer that holds transaction withdraw history
 */
stringstream* CheckingAccountProxy::withdraw(double withMoney)
{
        stringstream* ss;
        if (withMoney > balance) {
		cout << "Sorry, this amount of money is over your balance."<<endl;
		ss = nullptr;
		return ss;
	}
	else if (balance - withMoney < monthlyHomeRent) {
		cout << "Sorry, you have to keep your balance greater than $"<<monthlyHomeRent<<" to pay your monthly home rent. Are you sure you still want to do this transacrion?(y/n)" << endl;
		string yn = "";
		cin >> yn;
		if (yn == "y") {
			balance = getBalance() - withMoney;
			s << "Checking account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
			ss = &s;
			cout << withMoney << " dollors has been withdrawn" << endl;
			setBalance(balance);
			return ss;
		}
		if (yn == "n") {
			cout << "The transaction heve been canceled." << endl;
			ss = nullptr;
			return ss;
		}

	}
	else {
		balance = getBalance() - withMoney;
		s << "Checking account, $" << withMoney << " has been withdrawn, " << "New Balance: $" << balance << endl;
		ss = &s;
		cout << withMoney << " dollors has been withdrawn" << endl;
		setBalance(balance);
		return ss;
	}
}
	

/*
 * calls the logOut function from the real class CheckingAccount
 * @param ss the stringstream buffer that holds all the transactions of the checking account
 */
void CheckingAccountProxy::logOut(stringstream* ss)
{

	ptr->logOut(ss);
}
/*
 * calls the getID function from the real class CheckingAccount
 * @return the user's ID
 */
int CheckingAccountProxy::getID()
{
	return ptr->getID();
}
/*
 * calls the setBalance function from the real class CheckingAccount
 * @param bl the user's checking account balance 
 */
void CheckingAccountProxy::setBalance(double bl) {
	ptr->setBalance(bl);
}
/*
 * calls the getBalance function from the real class CheckingAccount
 * @return the users's checking account balance
 */
double CheckingAccountProxy::getBalance()
{
	return ptr->getBalance();
}




/*
 * calls the accountHistory function from the real class CheckingAccount
 * @return false if it fails to open the file, true if it opens the file and read it successfully
 */
bool CheckingAccountProxy::accountHistory()
{
	return ptr->accountHistory();
}

/*
 * calls the setMonthlyHomeRent function from the real class CheckingAccount
 * @param homeRent user's monthly home rent
 */
void CheckingAccountProxy::setMonthlyHomeRent(double homeRent)
{
	monthlyHomeRent = homeRent;
	ptr->setMonthlyHomeRent(homeRent);
}
/*
 * calls the getMonthlyHomeRent function from the real class CheckingAccount
 * @return user's monthly home rent
 */
double CheckingAccountProxy::getMonthlyHomeRent()
{
	return ptr->getMonthlyHomeRent();
}

/*
 * calls the setPassword function from the real class CheckingAccount
 * @param the user's password
 */
void CheckingAccountProxy::setPassword(string pass)
{
	ptr->setPassword(pass);
}
/*
 * calls the getPassword function from the real class CheckingAccount
 * @return the user's password
 */
string CheckingAccountProxy::getPassword()
{
	return ptr->getPassword();
}

// allows users to interfgace with class functions
void CheckingAccountProxy::Menu(){
 string option = "";
        double dep = 0.0;
        double with = 0.0;
        stringstream* ss = nullptr;
        string accountType = "";
        string pass = "";

        do {
              cout << "1.Balance" << endl;
              cout << "2.deposit" << endl;
              cout << "3.withdraw" << endl;
              cout << "4.Account History" << endl;
              cout << "5.budget planning" << endl;
              cout << "6.Change Password" << endl;
              cout << "7.logout" << endl;
              cin >> option;
              if (option == "1") {
                     cout << "$" << getBalance() << endl;
              }
              if (option == "2") {
	          cout << "How much do you want to deposit?" << endl;
	          cin >> dep;
	          ss = deposit(dep); 
              }
              if (option == "3") {
                  cout << "How much do you want to withdraw?" << endl;
                  cin >> with;
                  ss = withdraw(with); 
              }
              if (option == "4") {
                   accountHistory();
              }
              if (option == "5") {
                    string bp = "";
                    double monthlyHomeRent = 0.0;
                    cout << "1.Update monthly home rent" << endl;
                    cout << "2.Current monthly home rent" << endl;
                    cin >> bp;

                    if (bp == "1") {
                            cout << "How much is your monthly home rent?" << endl;
                            cin >> monthlyHomeRent;
                            setMonthlyHomeRent(monthlyHomeRent);
                    }
	    	    if (bp == "2") {
                            cout << "$" << getMonthlyHomeRent() << endl;
                    }
              }
              if (option == "6") {
                  cout << "Please enter your new password" << endl;
                  cin >> pass;
                  setPassword(pass);
                  cout << "Your password has been changed to " << getPassword() << endl;
              }
        }while(option != "7");
            if (option == "7") {
                logOut(ss);
		// call container logout
                cout << "You have logged out successfully" << endl;
            }
}
