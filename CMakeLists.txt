CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
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
	src/CheckingAccount.cpp
	src/CheckingAccountProxy.cpp
	src/SavingAccount.cpp
	src/SavingAccountProxy.cpp
	src/accountList.cpp
	src/csvSave.cpp
	src/txtSave.cpp
	test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
