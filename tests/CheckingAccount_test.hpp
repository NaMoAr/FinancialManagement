#ifndef CHECKINGACCOUNT_TEST_HPP
#define CHECKINGACCOUNT_TEST_HPP
#include <fstream>
#include "../header/CheckingAccount.hpp"
#include "gtest/gtest.h"

CheckingAccount ca = CheckingAccount(200, 12340, "1111",350);

TEST(CheckingAccountTest, Constructor){

  EXPECT_EQ(ca.getBalance(), 200);
  EXPECT_EQ(ca.getID(), 12340);
  EXPECT_EQ(ca.getPassword(),"1111");
  EXPECT_EQ(ca.getMonthlyHomeRent(), 350);
}

TEST(CheckingAccountTest, setBalancePositive){

  ca.setBalance(600);
  EXPECT_EQ(ca.getBalance(), 600);
}
TEST(CheckingAccountTest, setBalanceZero){
 
  ca.setBalance(0);
  EXPECT_EQ(ca.getBalance(), 0);
}
TEST(CheckingAccountTest, setBalanceNegative){
 
  ca.setBalance(-2);
  EXPECT_EQ(ca.getBalance(), -2);
}

TEST(CheckingAccountTest, SetPassword){

  ca.setPassword("2222");
  EXPECT_EQ(ca.getPassword(), "2222");
}
TEST(CheckingAccountTest, SetPasswordNonEmpty){
 
  ca.setPassword("2222");
  EXPECT_EQ(ca.getPassword(), "2222");
}
TEST(CheckingAccountTest, SetPasswordEmpty){

  ca.setPassword("");
  EXPECT_EQ(ca.getPassword(), "");
}

TEST(CheckingAccountTest, SetMonthlyHomeRentPositive){
 
  ca.setMonthlyHomeRent(450);
  EXPECT_EQ(ca.getMonthlyHomeRent(), 450);
}
TEST(CheckingAccountTest, SetMonthlyHomeRentNegative){

  ca.setMonthlyHomeRent(-30);
  EXPECT_EQ(ca.getMonthlyHomeRent(), -30);
}
TEST(CheckingAccountTest, SetMonthlyHomeRentZero){
 
  ca.setMonthlyHomeRent(0);
  EXPECT_EQ(ca.getMonthlyHomeRent(), 0);
}


TEST(CheckingAccountTest, logOutWithNonEmptybuffer){
 stringstream s;
 stringstream* ss;
 fstream f;
 s << "Hello" << endl;
 ss = &s;
 ca.logOut(ss);
 f.open("histories/12340.txt");
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
  EXPECT_EQ(st , "Hello");
}


TEST(CheckingAccountTest, logOutWithEmptybuffer){
  stringstream s;
  stringstream* ss;
  fstream f;
  s << "" << endl;
  ss = &s;
  ca.logOut(ss);
  f.open("histories/12340.txt");
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

TEST(CheckingAccountTest, accountHistory){

  EXPECT_EQ(ca.accountHistory(), true);
  remove("histories/12340.txt");
  EXPECT_EQ(ca.accountHistory(), false);
   
}


#endif
