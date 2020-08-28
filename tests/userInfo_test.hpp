#include "../header/csvSave.hpp"
#include "../header/txtSave.hpp"
#include "gtest/gtest.h"

TEST(TestCSV, ReadList) {
	UserInfo* u = new CSVSave();
	vector<vector<string>> v = u->ReadList();
	u->SaveInfo("c", 1, "apple", 5, 10, 0);
	u->SaveInfo("s", 2, "banana", 6, 12, 2);
	u->SaveInfo("c", 3, "carrot", 6, 12, 0);
	u->SaveInfo("s", 4, "donut", 5, 10, 2);
	u->SaveInfo("s", 5, "eggtart", 7, 14, 2);
	u->PrintList();
	EXPECT_EQ(u->PrintDebug(), "1 apple 5.000000 10.000000 0\n2 banana 6.000000 12.000000 2\n3 carrot 6.000000 12.000000 0\n 4 donut 5.000000 10.000000 2\n5 eggtart 7.000000 14.000000 2");
}

TEST(TestTXT, ReadList) {
	UserInfo* u = new TXTSave();
	vector<vector<string>> v = u->ReadList();
	u->SaveInfo("c", 1, "apple", 5, 10, 0);
	u->SaveInfo("s", 2, "banana", 6, 12, 2);
	u->SaveInfo("c", 3, "carrot", 6, 12, 0);
	u->SaveInfo("s", 4, "donut", 5, 10, 2);
	u->SaveInfo("s", 5, "eggtart", 7, 14, 2);
	u->PrintList();
	EXPECT_EQ(u->PrintDebug(), "1 apple 5.00000 10.000000 0\n2 banana 6.000000 12.000000 2\n3 carrot 6.000000 12.000000 0\n4 donut 5.000000 10.000000 2\n5 eggtart 7.000000 14.000000 2");
}
