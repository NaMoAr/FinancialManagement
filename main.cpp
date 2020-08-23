#include <iostream>
#include <fstream>
#include <string>
#include "header/Account.hpp"
#include "header/CheckingAccount.hpp"
#include "header/CheckingAccountProxy.hpp"
#include "header/SavingAccount.hpp"
#include "header/SavingAccountProxy.hpp"


using namespace std;


int main()
{
    CheckingAccountProxy user1_c(200, 1234);
    
    string option = "";
    double dep = 0.0;
    double with = 0.0;
    stringstream* ss = nullptr;
    string accountType = "";
 
    cout << "********Welcome to financial managment system********" << endl;
    cout << "Please choose your account type: " << endl;
    cout << "1.Saving Account" << endl;
    cout << "2.Checking Account" << endl;
    cin >> accountType;
    do {
       
        
        if (accountType == "1") {
            
            
        }
        if (accountType == "2") {
            cout << "1.Balance"<<endl;
            cout << "2.deposit" << endl;
            cout << "3.withdraw" << endl;
            cout << "4.Account History" << endl;
            cout << "5.budget planning" << endl;
            cout << "6.logout" << endl;
            cin >> option;
            if (option == "1") {
                cout << "$" << user1_c.getBalance() << endl;
            }
            if (option == "2") {
                cout << "How much do you want to deposit?" << endl;
                cin >> dep;
                ss = user1_c.deposit(dep, nullptr);
                
            }
            if (option == "3") {
                cout << "How much do you want to withdraw?" << endl;

                cin >> with;
                ss = user1_c.withdraw(with, nullptr);
                

            }
            if (option == "4") {
                user1_c.accountHistory();
                
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
                    user1_c.setMonthlyHomeRent(monthlyHomeRent);
                }
                if (bp == "2") {
                    cout <<"$"<< user1_c.getMonthlyHomeRent() << endl;
                }
                
            }
        }
    } while (option != "6");

    if (option == "6") {

        
        user1_c.logOut("deposit", dep, ss);
        user1_c.logOut("withdraw", with, ss);
        cout << "You have logged out successfully" << endl;
    }

    


   




    return 0;
}