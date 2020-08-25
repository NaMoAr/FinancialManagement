#include "gtest/gtest.h"
#include "header/CheckingAccount.hpp"
#include "header/CheckingAccountProxy.hpp"
#include "header/SavingAccount.hpp"
#include "header/SavingAccountProxy.hpp"
#include "tests/CheckingAccount_test.hpp"
#include "tests/CheckingAccountProxy_test.hpp"
#include "tests/SavingAccount_test.hpp"
#include "tests/SavingAccountProxy_test.hpp"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
