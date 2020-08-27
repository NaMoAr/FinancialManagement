# Financial Management Application

 > Authors: \<[Jeffrey McDaniel (Instructor)](https://github.com/jmcda001)\> \<[David Chang](https://github.com/dchan066-862012834)\> \<[Najmeh Mohammadi Arani](https://github.com/NaMoAr)\> \<[Chloe Truong](https://github.com/loveechloee)\>
 
## Project Description

This Financial Management Application is intended to help users keep track of their money, be it in a checking or savings account. Upon logging in, existing users have the option to view their balance, deposit or withdraw funds, create a projected savings goal for a checking account, and make a profit from the stock market using a saving account.
To project savings goal for a checking account, the app would ask the user to confirm the transaction when he wants to withdraw money that makes the balance less than his monthly home rent. 
 
Raison D'etre:
Finance management is an essential part of life for everyone. This app helps users to practice and plan their financial life by providing money management features that are consistent with their account balance.  Moreover, users are able to buy and sell the stock share and see their stock profit at any time. 

Languages and tools:
This project will be written in C++.

Tools:
* Tool to fetch the most current stock market prices (We were not able to apply this tool at the short time that we had, however, we pretend fetching current market prices by using a method that generates a random number in a specific range)

Input and output:

Upon the user's logging in by providing the right id and password, the input of our application initially comes from a database that holds the information about each account (saving/checking). Then the user can insert the value of money that he wants to deposit, withdraw. Also, update the monthly home rent(for checking account) or update the number of stock shares (for saving account)
The output of our application would be the balance of the account, account history (showing transactions from the opening of an account up until now), the profit that has been made at each moment(for saving account).


Design Patterns:

Proxy Design Pattern: 
Used to prevent many write operations to the file (since information on account history will be stored on text documents) we will use a proxy ostream t store all changes to the account history when the user is finished using the program. Our design resembling a proxy design pattern by making a delay to show transactions in the account history in order to receive confirmation from admin(Bank). The user would interact with proxy classes and the changes to an account would happen in the real classes uopn admin confirmation. 

Singleton Design Pattern:
Used to ensure that only one list object is created. This is done to consolidate all users to one list and avoid the need to traverse multiple incomplete list objects.

Strategy Design Pattern: 
Used to save the information of each account into a variety of files. One will be a .csv file that loads all account information into the program upon launch, and the other will be a .txt file written in a way that makes it easier for an administrator to read.

## Class Diagram

![Final_OMT](https://user-images.githubusercontent.com/56089475/91478566-f398dd80-e854-11ea-99cc-6cdc4fab1813.png)

![Proxy](https://user-images.githubusercontent.com/59351131/91477564-60ab7380-e853-11ea-84f1-8e6d1f8764c0.png)

![Singleton](https://github.com/dchan066-862012834/CS100_Final_Project/blob/main/UMLF.PNG)

![Strategy OMT](https://user-images.githubusercontent.com/56089475/91478564-f1cf1a00-e854-11ea-80d7-b76214e9a9dc.png)

 
 > ## Final deliverable
 ## Screenshots
At this time the project cannot change the input/output file, coming sprints are geared to fixing file IO so this section can be filled in
 ## Installation/Usage
 Copy Code from the repository. Run cmake and make to compile the program. To use the program run the executable and follow the instructions in the interface provided
 ## Testing
 Integrated testing is not yet finished. Once the program works completely from a UI perspective time will be spent integrating and re-verifying the individual test suites which can be found in branches dchan066/devtesting NaMoAr/development and loveechloee/development.
