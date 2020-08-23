# Financial Management Application

 > Authors: \<[Jeffrey McDaniel (Instructor)](https://github.com/jmcda001)\> \<[David Chang](https://github.com/dchan066-862012834)\> \<[Najmeh Mohammadi Arani](https://github.com/NaMoAr)\> \<[Chloe Truong](https://github.com/loveechloee)\>
 
## Project Description

This Financial Management Application is intended to help users keep track of their money, be it in a checking or savings account. Upon logging in, existing users have the option to view their balnace, deposit or withdraw funds, and create a projected savings goal.  
 
Raison D'etre:
Finance management is an essential part of life for everyone. This app helps users to practice and plan their financial life by providing money management features that are consistent with their account balance.  Moreover, it helps users to see their stock profit at a specific period of time (customizable by themselves).

Languages and tools:
This project will be written in C++.

Tools:
* Tool to fetch the most current stock market prices

Input and output:

The input of our application would be the user's information such as first and last name, the value of money that they want to deposit, withdraw, or transfer, and the value of money they want to keep in the saving account in order to invest on Nasdaq Composite stock market with the price at that time. (The type and numbers of stock market could expand)
The output of our application would be the account of the holder's balance, account history, profit for a customized period of time, a budget planning based on checking account's balance. 
This Financial Management Application is intended to help users keep track of their money, be it in a checking or savings account. Upon logging in, existing users have the option to view their balnace, deposit or withdraw funds, and create a projected savings goal. New users will also have access to these options after creating an account. 

Design Patterns:

Proxy Design Pattern: Used to minimize the amount of communication needed for the application to update account history. An ostream proxy will store information as needed and will update the history file when the user closes the program.

Singleton Design Pattern: Used to store accounts in a list that can be accessed by customers and changed by the administrators.

Strategy Design Pattern: Used to save the information of each account into a variety of files. One will be a .csv file that loads all account information into the program upon launch, and the other will be a .txt file written in a way that makes it easier for an administrator to read.

## Class Diagram

![FinalVersionOMT](https://user-images.githubusercontent.com/59351131/90815522-af02c480-e2df-11ea-977e-b885bd6c2b9f.png)



 > ## Phase III
 > You will need to schedule two check-in's with the TA (during lab hours or office hours) where your entire group will meet with them and discuss:
 > * What you have each done up to this point
 > * What you plan to do until the next meeting (or until the final demo)
 > * If there is anything that is getting in your way
 
 > You may notice that this is effectively a "standup" meeting. We suggest that as a team you have a daily (or every other day) standup, but this will be a bit more formal with the TA. 
 
 > **Your meetings cannot be in the same week of the session so plan ahead**

 > ## Final deliverable
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
