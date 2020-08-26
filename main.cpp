#include <iostream>
#include <fstream>
#include <string>
#include "header/Account.hpp"
#include "header/CheckingAccount.hpp"
#include "header/CheckingAccountProxy.hpp"
#include "header/SavingAccount.hpp"
#include "header/SavingAccountProxy.hpp"


using namespace std;


int main(){

 SavingAccountProxy user1_s(400, 5678, "2222" , 2 , 51);
    CheckingAccountProxy user1_c(200, 1234, "1111",350 );
   

    string option = "";
    double dep = 0.0;
    double with = 0.0;
    stringstream* ss = nullptr;
    string accountType = "";
    string pass = "";

    cout << "********Welcome to financial managment system********" << endl;
    cout << "Please choose your account type: " << endl;
    cout << "1.Saving Account" << endl;
    cout << "2.Checking Account" << endl;
    cin >> accountType;
    

    if (accountType == "1") {
        do {



            
            cout << "1.Balance" << endl;
            cout << "2.deposit" << endl;
            cout << "3.withdraw" << endl;
            cout << "4.Account History" << endl;
            cout << "5.My Stock Shares" << endl;
            cout << "6.See My Current Profit" << endl;
            cout << "7.Sell Stock Share" << endl;
            cout << "8.Buy Stock Share" << endl;
            cout << "9.Change Password" << endl;
            cout << "10.logout" << endl;
            cin >> option;
            if (option == "1") {
                cout << "$" << user1_s.getBalance() << endl;
            }
            if (option == "2") {
                cout << "How much do you want to deposit?" << endl;
                cin >> dep;
                ss = user1_s.deposit(dep);

            }
            if (option == "3") {
                cout << "How much do you want to withdraw?" << endl;

                cin >> with;
                ss = user1_s.withdraw(with);


            }
            if (option == "4") {
                user1_s.accountHistory();
            }
            if (option == "5") {
                cout << user1_s.getStockNum() << " stock share/shares of $" << user1_s.getStockPrice() << endl;
            }
            if (option == "6") {
		 cout << "$" << user1_s.calculateProfit() << endl;
            }
            if (option == "7") {
                ss = user1_s.sellStock();
            }
            if (option == "8") {
                ss = user1_s.buyStock();
            }
            if (option == "9") {
                cout << "Please enter your new password" << endl;
                cin >> pass;
                user1_s.setPassword(pass);
                cout << "Your password has been changed to " << user1_s.getPassword() << endl;

            }


        } while (option != "10");

            if (option == "10") {


                user1_s.logOut(ss);
                cout << "You have logged out successfully" << endl;
               
            }

    }
      
    if (accountType == "2") {
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
                     cout << "$" << user1_c.getBalance() << endl;
              }
              if (option == "2") {
              cout << "How much do you want to deposit?" << endl;
              cin >> dep;
              ss = user1_c.deposit(dep);
              }
              if (option == "3") {
                  cout << "How much do you want to withdraw?" << endl;
                  cin >> with;
                  ss = user1_c.withdraw(with);
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
                            cout << "$" << user1_c.getMonthlyHomeRent() << endl;
                    }
              }
              if (option == "6") {
                  cout << "Please enter your new password" << endl;
                  cin >> pass;
                  user1_c.setPassword(pass);
                  cout << "Your password has been changed to " << user1_c.getPassword() << endl;

              }

        }while(option != "7");

            if (option == "7") {


                user1_c.logOut(ss);
                cout << "You have logged out successfully" << endl;
            }


    }

    return 0;
}
