#ifndef __TXTSAVE_HPP__
#define __TXTSAVE_HPP__

#include "userInfo.hpp"

class TXTSave : public UserInfo {
	public:
		TXTSave() : UserInfo() {};
		void PrintList();
};
