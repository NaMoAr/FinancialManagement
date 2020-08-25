#ifndef SAVINGACCOUNT_TEST_HPP
#define SAVINGACCOUNT_TEST_HPP
#include <fstream>
#include "../header/SavingAccount.hpp"
#include "gtest/gtest.h"
 
SavingAccount sa = SavingAccount(400, 56780, "2222" , 2 , 51);
  
TEST(SavingAccountTest, Constructor){
 
   EXPECT_EQ(sa.getBalance(), 400);
   EXPECT_EQ(sa.getID(), 56780);
   EXPECT_EQ(sa.getPassword(),"2222");
   EXPECT_EQ(sa.getStockNum(), 2);
   EXPECT_EQ(sa.getStockPrice(), 51);
}

TEST(SavingAccountTest, SetBalance){

   sa.setBalance(600);
   EXPECT_EQ(sa.getBalance(), 600);
}

TEST(SavingAccountTest, SetPassword){

   sa.setPassword("1111");
   EXPECT_EQ(sa.getPassword(), "1111");
}
 
TEST(SavingAccountTest, SetStockNum){
 
   sa.setStockNum(5);
   EXPECT_EQ(sa.getStockNum(), 5);
}

TEST(SavingAccountTest, setStockPrice){
  
   sa.setStockPrice(57);
   EXPECT_EQ(sa.getStockPrice(), 57); 

}

 
TEST(SavingAccountTest, logOutWithNonEmptybuffer){
  stringstream s;
  stringstream* ss;
  fstream f;
  s << "Hello" << endl;
  ss = &s;
  sa.logOut(ss);
  f.open("56780.txt");
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
 

TEST(SavingAccountTest, logOutWithEmptybuffer){
   stringstream s;
   stringstream* ss;
   fstream f;
   s << "" << endl;
   ss = &s;
   sa.logOut(ss);
   f.open("56780.txt");
   string st = "";
   char str[2000];
   if (cin.get() == '\n') {
   int i = 2000;
   while (f) {
         f.getline(str, i);
         if (f) st = str; //st.push_back(str);
 
       }
         f.close();
           }
  EXPECT_EQ(st , "");
}

TEST(SavingAccountTest, accountHistory){
 
    EXPECT_EQ(sa.accountHistory(), true);
    remove("56780.txt");
    EXPECT_EQ(sa.accountHistory(), false);
}


#endif
