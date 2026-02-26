#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(int newAccountNumber, int newPin, double startingBalance) {
    accountNumber = newAccountNumber;
    pin = newPin;
    balance = startingBalance;
}

int Account::getAccountNumber() {
    return accountNumber;
}

bool Account::authenticate(int enteredPin) {
    return pin == enteredPin;
}

double Account::getBalance() {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Successfully deposited $" << amount << endl;
    } else {
        cout << "Error: Deposit amount must be positive." << endl;
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Please take your cash: $" << amount << endl;
        return true; 
    } else {
        cout << "Error: Insufficient funds or invalid amount." << endl;
        return false; 
    }
}