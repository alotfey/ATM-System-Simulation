#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    // test code for the Account class
    Account myAccount(123456, 1234, 1000.00);
    cout << "Account Number: " << myAccount.getAccountNumber() << endl;
    
    return 0;
}