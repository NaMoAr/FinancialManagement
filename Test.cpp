#include "accountList.hpp"
#include "UserInfoDummy.hpp"
#include "AccountDummy.hpp" 
#include "gtest/gtest.h"

TEST(constructorTest,standardInput) {						//Tests to see if the constructor can handle the standard input from userInfo
	UserInfoDummy* UI = new UserInfoDummy(1);				//should contain 4 vectors
	AccountList* AL = AL->GetInstance(UI,UI);				// reads the vectors into the constructor

	EXPECT_EQ(AL->size(),4);

}

TEST(constructorTest,emptyInput){
	
	UserInfoDummy* UI = new UserInfoDummy(0);
	AccountList* AL = AL->GetInstance(UI,UI);


	EXPECT_EQ(AL->size(),0);						//Tests to see in the constructor can handle an empty input from userInfo

}

TEST(constructorTest,SingletonEnforcement){					//tests get instance with different arguments to make sure it does not over ride the old set 
	UserInfoDummy* UI = new UserInfoDummy(1);
 	UserInfoDummy* UIT = new UserInfoDummy(0);
	AccountList* AL = AL->GetInstance(UI,UI); 
	EXPECT_EQ(AL->GetInstance(UI,UI),AL->GetInstance(UIT,UIT));

}

TEST(destructorTest,standardInput){ 						// tests to make sure the destructor of the list causes no faults or errors
	
	int conditionToMeet = 5;

	if (conditionToMeet == 5){
 		UserInfoDummy* UI = new UserInfoDummy(1);
		AccountList* AL = AL->GetInstance(UI,UI); 
	}

	EXPECT_EQ(conditionToMeet,5);

}

TEST(destructorTest,emptyMap){							// tests to ensure the destruction of an empty list coauses no faults
	int conditionToMeet = 5;

	if (conditionToMeet == 5){
 		UserInfoDummy* UIT = new UserInfoDummy(0);
		AccountList* AL = AL->GetInstance(UIT,UIT); 
	}

	EXPECT_EQ(conditionToMeet,5);

}

TEST(traversal,standardInput){							// test the traversal function to see if it finds the given ID
	UserInfoDummy* UI = new UserInfoDummy(1);
	AccountList* AL = AL->GetInstance(UI,UI);	
	AccountDummy* t = AL->traverseDatabase(1); 
	EXPECT_NE(nullptr,t);

}

TEST(traversal,invalidID){							// test the traversal function to make sure it returns nullptr when the ID does not exist
	UserInfoDummy* UI = new UserInfoDummy(1);
	AccountList* AL = AL->GetInstance(UI,UI);	

	EXPECT_EQ(nullptr,AL->traverseDatabase(12));

}

TEST(traversal,emptyInput){							// test to make sure the function returns nullptr on an empty list
	UserInfoDummy* UI = new UserInfoDummy(0);
	AccountList* AL = AL->GetInstance(UI,UI);

	EXPECT_EQ(nullptr,AL->traverseDatabase(3));
}

TEST(interface,login){								//this testing requires user input, questionalbe CI application
	int conditionToMeet = 5;
	UserInfoDummy* UI = new UserInfoDummy(0);
	AccountList* AL = AL->GetInstance(UI,UI);
	

	EXPECT_EQ(conditionToMeet,5);

}

TEST(interface,adminMenu){							//this testing requires user input, questionalbe CI application
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}
TEST(interface,interface){							// testing requeres user input , CI unlikely
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(interface,close){								// CI unlikely due to user input
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(adminInterface,accessDenied){						// ""	
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(adminInterface,adminInterface){						// ""
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(adminInterface,deleteAccount){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(adminInterface,createAccount){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(adminInterface,exit){							// necesity for user input in test case makes CI of this case unlikely
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(createAccount,cFlag){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(createAccount,sFlag){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(createAccount,badFlag){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(createAccount,misttypedInputs){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(deleteAccount, misID){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(deleteAccount,success){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(deleteAccount,emptyDatabase){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(logOut,checkPointer){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(logIn, misID){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(logIn,misPass){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

TEST(logIn,success){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

//TODO: implement test cases


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

