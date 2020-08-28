# Financial Management Application

 > Authors: \<[Jeffrey McDaniel (Instructor)](https://github.com/jmcda001)\> \<[David Chang](https://github.com/dchan066-862012834)\> \<[Najmeh Mohammadi Arani](https://github.com/NaMoAr)\> \<[Chloe Truong](https://github.com/loveechloee)\>
 
## Project Description

This Financial Management Application is intended to help users keep track of their money, be it in a checking or savings account. Upon logging in, existing users have the option to view their balance, deposit or withdraw funds, create a projected savings goal for a checking account, and make a profit from the stock market using a saving account.
To project savings goal for a checking account, the app would ask the user to confirm the transaction when he wants to withdraw money that makes the balance less than his monthly home rent. 

**Raison D'etre:**
Finance management is an essential part of life for everyone. This app helps users to practice and plan their financial life by providing money management features that are consistent with their account balance.  Moreover, users are able to buy and sell the stock share and see their stock profit at any time. 

**Language:**
This project will be written in C++.

**Tools:**
* Tool to fetch the most current stock market prices (We were not able to apply this tool at the short time that we had, however, we pretend fetching current market prices by using a method that generates a random number in a specific range)

**Input and output:**
Upon the user's logging in by providing the correct id and password, the input of our application initially comes from a database that holds the information about each account (saving/checking). Then the user can insert the value of money that he wants to deposit, withdraw. Also, update the monthly home rent(for checking account) or update the number of stock shares (for saving account).
The output of our application would be the balance of the account, account history (showing transactions from the opening of an account up until now), and the profit that has been made at each moment(for saving account).


**Design Patterns:**

Proxy Design Pattern: 
 * Used to prevent many write operations to the file (since information on account history will be stored on text documents) we will use a proxy ostream to store all changes to the account history when the user is finished using the program. Our design resembling a proxy design pattern by making a delay to show transactions in the account history in order to receive confirmation froNajmeh Mohammadi Aranm admin(Bank). The user would interact with proxy classes and the changes to an account would happen in the real classes uopn admin confirmation. (by Najmeh Mohammadi Arani)

Singleton Design Pattern:
 * Used to ensure that only one list object is created. This is done to consolidate all users to one list and avoid the need to traverse multiple incomplete list objects. (by David Chang)

Strategy Design Pattern: 
 * Used to save the information of each account into a variety of files. One will be a .csv file that loads all account information into the program upon launch, and the other will be a .txt file written in a way that makes it easier for an administrator to read. (by Chloe Truong)

## Class Diagram

![Final_OMT](https://user-images.githubusercontent.com/56089475/91478566-f398dd80-e854-11ea-99cc-6cdc4fab1813.png)

![Proxy](https://user-images.githubusercontent.com/59351131/91477564-60ab7380-e853-11ea-84f1-8e6d1f8764c0.png)

![Singleton](https://github.com/dchan066-862012834/CS100_Final_Project/blob/main/UMLF.PNG)
<<<<<<< HEAD

![Strategy OMT](https://user-images.githubusercontent.com/56089475/91478564-f1cf1a00-e854-11ea-80d7-b76214e9a9dc.png)


 > ## Final deliverable
 ## Screenshots
![Screenshot (326)](https://user-images.githubusercontent.com/56089475/91605275-0d095a80-e925-11ea-9618-6bb2d776e427.png)
This first image depicts how an administrator would sign in and create an account. 

![Screenshot (327)](https://user-images.githubusercontent.com/56089475/91605277-0da1f100-e925-11ea-9b3b-01e29cf7f85e.png)
![Screenshot (329)](https://user-images.githubusercontent.com/56089475/91605278-0e3a8780-e925-11ea-88d9-d5635ba36b22.png)
![accounthistory](https://user-images.githubusercontent.com/59351131/91610782-bf91eb00-e92e-11ea-823f-0765ea9c90d7.JPG)
These next three images are an example of how a customer could sign in, view balance, deposit, and view stocks and account history.

As of now, the administrator is able to create an account and that account will be saved in the next entry of its designated text file. However, there is a segmentation fault every time the user enters ‘3’ to quit the program that has yet to be resolved. In addition, the administrator can only remove the last account generated on the list. Selecting an account otherwise throws an out of range error and as you can see from the screenshots, the accountList destructor gets called twice followed by a segmentation fault. The next sprint will be dedicated to resolving these errors.
 ## Installation/Usage
 Copy Code from the repository. Run cmake and make to compile the program. To use the program run the executable and follow the instructions in the interface provided. If logging in as a user, use one of the existing IDs and password found in the one of the text files in the folder "files." To log in as an administrator, use the special admin access code found inside accountList.hpp.
 ## Testing
 Integrated testing is not yet finished. Once the program works completely from a UI perspective time will be spent integrating and re-verifying the individual test suites which can be found in branches dchan066/devtesting NaMoAr/development and loveechloee/development. Eventually, once the bugs have been resolved, we would like to create a YAML file to conducted continuous integration.
 ## Further Development Opportunities
 Currently, the fetch functionality for the stock share price is a method that generates a random number in a specific range, and each time that the user buys stock shares, they app would find the mean of current stock shares price of the user and the recently bought stock share price by the user. One can develop this application by adding a fetch functionality to inquiry a live stock share price for different stock markets and also save them in a vector (or any preferred list) the number of each stock share, its corresponding price, and the stock market's name.  
