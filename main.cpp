#include <iostream>
#include <fstream>
#include <string>
#include "header/Account.hpp"
#include "header/CheckingAccount.hpp"
#include "header/CheckingAccountProxy.hpp"
#include "header/SavingAccount.hpp"
#include "header/SavingAccountProxy.hpp"
#include <vector>

using namespace std;


int main()
{
    SavingAccountProxy user1_p(200, 5678);
    
   
    string option = "";
    double dep = 0.0;
    double with = 0.0;
    stringstream* ss = nullptr;
 

    do {
        cout << "1.deposit" << endl;
        cout << "2.withdraw" << endl;
        cout << "3.Account History" << endl;
        cout << "4.logout" << endl;
        cin >> option;
        if (option == "1") {
            cout << "How much do you want to deposit?"<<endl;
            cin >> dep;
            ss = user1_p.deposit(dep,nullptr);
            
            
        }
        if (option == "2") {
            cout << "How much do you want to withdraw?" << endl;

            cin >> with;
            ss = user1_p.withdraw(with, nullptr);
            
            

        }
        if (option == "3") {
            user1_p.accountHistory();
        }
    } while (option != "4");

    if (option == "4") {
        
            user1_p.logOut("deposit" , dep, ss);
            user1_p.logOut("withdraw", with, ss);
          
       cout<<"You have logged out successfully"<< endl;
    }
    
    


   




    return 0;
}

