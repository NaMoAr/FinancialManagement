CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE-CXX-STANDARD 11)


ADD_EXECUTABLE(demo
        main.cpp
        src/CheckingAccount.cpp
        src/CheckingAccountProxy.cpp
        src/SavingAccount.cpp
        src/SavingAccountProxy.cpp
  )


 ADD_EXECUTABLE(test
        test.cpp
        src/CheckingAccount.cpp
        src/CheckingAccountProxy.cpp
        src/SavingAccount.cpp
        src/SavingAccountProxy.cpp

)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
