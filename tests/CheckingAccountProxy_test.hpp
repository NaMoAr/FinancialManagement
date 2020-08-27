#ifndef CHECKINGACCOUNTPROXY_TEST_HPP
#define CHECKINGACCOUNTPROXY_TEST_HPP
#include <fstream>
#include "../header/CheckingAccountProxy.hpp"
#include "../header/CheckingAccount.hpp"
#include "gtest/gtest.h"
 
  CheckingAccountProxy* cap  = new CheckingAccountProxy(500, 12340, "1111",350);


TEST(CheckingAccountProxyTest, Constructor){

   EXPECT_EQ(cap->getBalance(), 500);
   EXPECT_EQ(cap->getID(), 12340);
   EXPECT_EQ(cap->getPassword(),"1111");
   EXPECT_EQ(cap->getMonthlyHomeRent(), 350);
}
TEST(CheckingAccountProxyTest , setBalanceNegative){
 
  cap->setBalance(-700);
  EXPECT_EQ(cap->getBalance() , -700);
}
TEST(CheckingAccountProxyTest , setBalanceZero){
 
  cap->setBalance(0);
  EXPECT_EQ(cap->getBalance() , 0);
}
TEST(CheckingAccountProxyTest , setBalancePositive){

  cap->setBalance(700);
  EXPECT_EQ(cap->getBalance() , 700);
}


TEST(CheckingAccountProxyTest, SetPasswordNonEmpty){
 
  cap->setPassword("2222");
  EXPECT_EQ(cap->getPassword(), "2222");
}
TEST(CheckingAccountProxyTest, SetPasswordEmpty){
 
  cap->setPassword("");
  EXPECT_EQ(cap->getPassword(), "");
}

TEST(CheckingAccountProxyTest, SetMonthlyHomeRentPositive){
 
  cap->setMonthlyHomeRent(450);
  EXPECT_EQ(cap->getMonthlyHomeRent(), 450);
}
TEST(CheckingAccountProxyTest, SetMonthlyHomeRentNegative){
 
  cap->setMonthlyHomeRent(-450);
  EXPECT_EQ(cap->getMonthlyHomeRent(), -450);
}
TEST(CheckingAccountProxyTest, SetMonthlyHomeRentZero){
 
  cap->setMonthlyHomeRent(0);
  EXPECT_EQ(cap->getMonthlyHomeRent(), 0);
}
TEST(CheckingAccountProxy, depositPositive){

  stringstream* ss = cap->deposit(30);   
  EXPECT_EQ(cap->getBalance(),730);
  EXPECT_NE(ss , nullptr);
}
TEST(CheckingAccountProxy, depositNegative){

  stringstream* ss = cap->deposit(-30);
  EXPECT_EQ(cap->getBalance(),700);
  EXPECT_NE(ss , nullptr);
}
TEST(CheckingAccountProxy, depositZero){

  stringstream* ss = cap->deposit(0);
  EXPECT_EQ(cap->getBalance(),700);
  EXPECT_NE(ss , nullptr);
}
TEST(CheckingAccountProxy, withdrawPositiveLTbalance){

  stringstream* ss = cap->withdraw(30);
  EXPECT_EQ(cap->getBalance(),670);
  EXPECT_NE(ss , nullptr);

}
TEST(CheckingAccountProxy, withdrawPositiveGTbalance){
 
   stringstream* ss = cap->withdraw(900);
   EXPECT_EQ(cap->getBalance(),670);
   EXPECT_EQ(ss , nullptr);

}

TEST(CheckingAccountProxy, withdrawNegative){

  stringstream* ss = cap->withdraw(30);
  EXPECT_EQ(cap->getBalance(),640);
  EXPECT_NE(ss , nullptr);

}
TEST(CheckingAccountProxy, withdrawZero){
 
  stringstream* ss = cap->withdraw(0);
  EXPECT_EQ(cap->getBalance(),640);
  EXPECT_NE(ss , nullptr);

}

 
TEST(CheckingAccountzProxyTest, logOutWithNonEmptybuffer){
   stringstream s;
   stringstream* ss;
   fstream f;
   s << "Hello" << endl;
   ss = &s;
   cap->logOut(ss);
   f.open("histories/12340.txt");
   string st = "";
   char str[2000];
   if (cin.get() == '\n') {
   int i = 2000;
 
   while (f) {
          f.getline(str, i);
          if (f) st = str;
}
          f.close();
          }
    EXPECT_EQ(st , "Hello");
}
 

TEST(CheckingAccountProxyTest, logOutWithEmptybuffer){
   stringstream s;
   stringstream* ss;
   fstream f;
   s << "" << endl;
   ss = &s;
   cap->logOut(ss);
   f.open("histories/12340.txt");
   string st = "";
   char str[2000];
   if (cin.get() == '\n') {
   int i = 2000;
   while (f) {
           f.getline(str, i);
          if (f) st = str; 
 
           }
           f.close();
           }
     EXPECT_EQ(st , "");
}


TEST(CheckingAccountProxyTest, accountHistory){
 
    EXPECT_EQ(cap->accountHistory(), true);
    remove("histories/12340.txt");
    EXPECT_EQ(cap->accountHistory(), false);
}


#endif
