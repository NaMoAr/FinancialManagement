#include "accountList.hpp"
#include "UserInfoDummy.hpp"
#include "AccountDummy.hpp" 

int main () {

UserInfoDummy* UI = new UserInfoDummy(1);
AccountList* AL = AL->GetInstance(UI,UI);

cout << AL->size();

AL->interface();


}
