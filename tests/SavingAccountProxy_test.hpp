#ifndef SAVINGACCOUNTPROXY_TEST_HPP
#define SAVINGACCOUNTPROXY_TEST_HPP
#include <fstream>
#include "../header/SavingAccountProxy.hpp"
#include "../header/SavingAccount.hpp"
#include "gtest/gtest.h"
  
    SavingAccountProxy* sap  = new SavingAccountProxy(400, 56780, "2222" , 2 , 51);
 
 
TEST(SavginAccountProxyTest, Constructor){
 
     EXPECT_EQ(sap->getBalance(),400);
     EXPECT_EQ(sap->getID(), 56780);
     EXPECT_EQ(sap->getPassword(),"2222");
     EXPECT_EQ(sap->getStockNum(), 2);
     EXPECT_EQ(sap->getStockPrice(), 51);
  }

TEST(SavingAccountProxyTest, SetBalanceNegative){
 
     sap->setBalance(-700);
     EXPECT_EQ(sap->getBalance(), -700);
}
TEST(SavingAccountProxyTest, SetBalanceZero){

     sap->setBalance(0);
     EXPECT_EQ(sap->getBalance(), 0);
}
TEST(SavingAccountProxyTest, SetBalancePositive){
 
     sap->setBalance(700);
     EXPECT_EQ(sap->getBalance(), 700);
}

TEST(SavingAccountProxyTest, SetPasswordNonEmpty){

    sap->setPassword("1111");
    EXPECT_EQ(sap->getPassword(), "1111");
}
TEST(SavingAccountProxyTest, SetPasswordEmpty){
 
    sap->setPassword("");
    EXPECT_EQ(sap->getPassword(), "");
}


TEST(SavingAccountProxyTest, SetStockNumNegative){
 
     sap->setStockNum(-5);
     EXPECT_EQ(sap->getStockNum(), -5);
}
TEST(SavingAccountProxyTest, SetStockNumZero){
 
    sap->setStockNum(0);
    EXPECT_EQ(sap->getStockNum(), 0);
}
TEST(SavingAccountProxyTest, SetStockNumPositive){
 
   sap->setStockNum(5);
   EXPECT_EQ(sap->getStockNum(), 5);
}

TEST(SavingAccountProxyTest, SetStockPriceNagative){
     sap->setStockPrice(-57);
     EXPECT_EQ(sap->getStockPrice(), -57);
 
}
TEST(SavingAccountProxyTest, SetStockPriceZero){
     sap->setStockPrice(0);
     EXPECT_EQ(sap->getStockPrice(), 0);

}
TEST(SavingAccountProxyTest, SetStockPricePositive){
     sap->setStockPrice(57);
     EXPECT_EQ(sap->getStockPrice(), 57);

}

TEST(SavingAccountProxyTest, FetchStockPrice ){

     double s1 = sap->fetchStockPrice();
     double s2 = sap->fetchStockPrice();
     EXPECT_NE(s1 , s2);
} 

TEST(SavingAccountProxyTest, calculateProfit){
   
     double p1 = sap->calculateProfit();
     double p2 = sap->calculateProfit();
     EXPECT_NE(p1 , p2); 
}
TEST(SavingAccountProxy, depositNegative){
    stringstream* ss = sap->deposit(-30);
    EXPECT_EQ(sap->getBalance(),670);
    EXPECT_NE(ss , nullptr);
}
TEST(SavingAccountProxy, depositZero){
    stringstream* ss = sap->deposit(0);
    EXPECT_EQ(sap->getBalance(),670);
    EXPECT_NE(ss , nullptr);
}
TEST(SavingAccountProxy, depositPositive){
    stringstream* ss = sap->deposit(30);
    EXPECT_EQ(sap->getBalance(),700);
    EXPECT_NE(ss , nullptr);
}

TEST(SavingAccountProxy, withdrawGTbalance){

    stringstream* ss = sap->withdraw(800);
    EXPECT_EQ(sap->getBalance(),700);
    EXPECT_EQ(ss , nullptr);
}
TEST(SavingAccountProxy, withdrawLTbalance){

    stringstream* ss = sap->withdraw(30);
    EXPECT_EQ(sap->getBalance(),670);
    EXPECT_NE(ss , nullptr);
}

TEST(SavingAccountzProxyTest, logOutWithNonEmptybuffer){
    stringstream s;
    stringstream* ss;
    fstream f;
    s << "Hello" << endl;
    ss = &s;
    sap->logOut(ss);
    f.open("histories/56780.txt");
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
 
TEST(SavingAccountProxyTest, logOutWithEmptybuffer){
    stringstream s;
    stringstream* ss;
    fstream f;
    s << "" << endl;
    ss = &s;
    sap->logOut(ss);
    f.open("histories/56780.txt");
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


TEST(SavingAccountProxyTest, accountHistory){
 
    EXPECT_EQ(sap->accountHistory(), true);
    remove("histories/56780.txt");
    EXPECT_EQ(sap->accountHistory(), false);
}


#endif
           






