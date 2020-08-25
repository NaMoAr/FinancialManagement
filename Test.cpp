#include "accountList.hpp"
#include "UserInfoDummy.hpp"
#include "AccountDummy.hpp" 
#include "gtest/gtest.h"

TEST(TestSuite,TestName){
	int conditionToMeet = 5;

	EXPECT_EQ(conditionToMeet,5);

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

