#include "gtest/gtest.h"
#include "csvSave.hpp"
#include "txtSave.hpp"

TEST(TestCSV, ReadList) {
	UserInfo* u = new CSVSave();
	vector<vector<string>> v = u->ReadList();
	u->SaveInfo("c", 1, "apple", 12345, 5);
	u->SaveInfo("s", 2, "banana", 123456, 6, 3);
	u->SaveInfo("c", 3, "carrot", 123456, 6);
	u->SaveInfo("c", 4, "donut", 12345, 5);
	u->SaveInfo("s", 5, "eggtart", 1234567, 7, 5);
	u->PrintList();
	EXPECT_EQ(u->PrintDebug(), 
		"1 apple 12345.000000 5.000000\n2 banana 123456.000000 6.000000 3.000000\n3 carrot 123456.000000 6.000000\n4 donut 12345.000000 5.000000\n5 eggtart 1234567.000000 7.000000 5.000000\n");
}

TEST(TestTXT, ReadList) {
	UserInfo* u = new TXTSave();
	vector<vector<string>> v = u->ReadList();
	u->SaveInfo("s", 1, "apple", 12345, 5, 4);	
	u->SaveInfo("c", 2, "banana", 123456, 6);
	u->SaveInfo("s", 3, "carrot", 123456, 6, 3);
	u->SaveInfo("c", 4, "donut", 12345, 5);
	u->SaveInfo("c", 5, "eggtart", 1234567, 7);
	u->PrintList();
	EXPECT_EQ(u->PrintDebug(), 
		"1 apple 12345.000000 5.000000 4.000000\n2 banana 123456.000000 6.000000\n3 carrot 123456.000000 6.000000 3.000000\n4 donut 12345.000000 5.000000\n5 eggtart 1234567.000000 7.000000\n");
}
