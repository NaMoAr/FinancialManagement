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
 
TEST(CheckingAccountProxyTest , setBalance){

  cap->setBalance(700);
  EXPECT_EQ(cap->getBalance() , 700);
}

TEST(CheckingAccountProxyTest, SetPassword){
 
  cap->setPassword("2222");
  EXPECT_EQ(cap->getPassword(), "2222");
}


TEST(CheckingAccountProxyTest, SetMonthlyHomeRent){
 
  cap->setMonthlyHomeRent(450);
  EXPECT_EQ(cap->getMonthlyHomeRent(), 450);
}

 
TEST(CheckingAccountzProxyTest, logOutWithNonEmptybuffer){
   stringstream s;
   stringstream* ss;
   fstream f;
   s << "Hello" << endl;
   ss = &s;
   cap->logOut(ss);
   f.open("12340.txt");
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
   f.open("12340.txt");
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

TEST(CheckingAccountProxy, deposit){
    
  stringstream* ss = cap->deposit(30);
  EXPECT_EQ(cap->getBalance(),730);
  EXPECT_NE(ss , nullptr);
}

TEST(CheckingAccountProxy, withdraw){
  cap->setBalance(730);
  stringstream* ss = cap->withdraw(30);
  EXPECT_EQ(cap->getBalance(),700);
  EXPECT_NE(ss , nullptr);

}

TEST(CheckingAccountProxyTest, accountHistory){
 
    EXPECT_EQ(cap->accountHistory(), true);
    remove("12340.txt");
    EXPECT_EQ(cap->accountHistory(), false);
}


#endif
