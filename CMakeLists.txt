CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(main
	header/Account.hpp
	header/CheckingAccount.hpp
	header/CheckingAccountProxy.hpp
	header/SavingAccount.hpp
	header/SavingAccountProxy.hpp
	header/accountList.hpp
	header/userInfo.hpp
	header/csvSave.hpp
	header/txtSave.hpp
	src/CheckingAccount.cpp
	src/CheckingAccountProxy.cpp
	src/SavingAccount.cpp
	src/SavingAccountProxy.cpp
	src/accountList.cpp
	src/csvSave.cpp
	src/txtSave.cpp
	src/main.cpp
)

ADD_EXECUTABLE (test
	header/Account.hpp
	header/CheckingAccount.hpp
	header/CheckingAccountProxy.hpp
	header/SavingAccount.hpp
	header/SavingAccountProxy.hpp
	header/accountList.hpp
	header/userInfo.hpp
	header/csvSave.hpp
	header/txtSave.hpp
	src/CheckingAccount.cpp
	src/CheckingAccountProxy.cpp
	src/SavingAccount.cpp
	src/SavingAccountProxy.cpp
	src/accountList.cpp
	src/csvSave.cpp
	src/txtSave.cpp
	tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
