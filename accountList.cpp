AccountList::AccountList () {
// call Chloe's class to read the database file
// Chloe should call the account constructor to create the accounts and add their pointers to the list
}

AccountList::~AccountList() {
// call Chloe's class to write the account data to the database file
// delete all pointers in the hash map
// delete the AccountList and terminate the program
}


AccountList* AccountList::GetInstance() {
// check to see if an accountlist exists, if so return it
// if it doesnt exist create the object by calling the constructor
// return the pointer of the object you just created
}

void AccountList::createAccount () {
// verify admin status with an admin password
// request new password
// generate a unique ID
// create an account object
// fit the pointer into the map
}

void AccountList::deleteAccount () {
// verify admin status with an admin password
// search for id, report an error if it doesn't exist 
// delete the object and set the pointer to null
}

// a helper function to let people search the list
void AccountList::traverseDatabase () {  // Final implementation will return an account*
// this function searches the database for a given id returning it
// if none exists it will return NULL
}

Account* AccountList::logIn() {
// prompt ID & Password
// scan list for ID returning null on a fail to find and print "account not found"
// compare Password returning the account pointer on a match and null on a mismatch, in the fail case print "password incorrect" 
}


void AccountList::logOut() {
// call relevant account history proxy update functions
// unset user pointer
// re call the log in prompt  
}

