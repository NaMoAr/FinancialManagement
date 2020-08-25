#include "gtest/gtest.h"
//#include "userInfo.hpp"
#include "csvSave.hpp"
#include "txtSave.hpp"

TEST(TestCSV, ReadList) {
	UserInfo* u = new CSVSave();
	vector<vector<string>> v = u->ReadList();
	u->SaveInfo("c", 808, "csc", 1995, 1);
	u->SaveInfo("s", 1004, "yjh", 1995, 2, 1);
	u->SaveInfo("c", 1230, "hjs", 1995, 3); 
	u->SaveInfo("s", 610, "mjh", 1996, 4, 1);
	u->SaveInfo("c", 615, "ksy", 1996, 5);
	u->PrintList();
	EXPECT_EQ(u->PrintDebug(), 
		"808 csc 1995.000000 1.000000\n1004 yjh 1995.000000 2.000000 1.000000\n1230 hjs 1995.000000 3.000000\n610 mjh 1996.000000 4.000000 1.000000\n615 ksy 1996.000000 5.000000\n");
	delete u;
} 

TEST(TestTXT, ReadList) {
	UserInfo* u = new TXTSave();
	vector<vector<string>> v = u->ReadList();
	u->SaveInfo("c", 808, "csc", 1995, 1);
	u->SaveInfo("s", 1004, "yjh", 1995, 2, 1);
	u->SaveInfo("c", 1230, "hjs", 1995, 3);
	u->PrintList();
	EXPECT_EQ(u->PrintDebug(),
		"808 csc 1995.000000 1.000000\n1004 yjh 1995.000000 2.000000 1.000000\n1230 hjs 1995.000000 3.000000\n");
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
