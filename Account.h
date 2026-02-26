#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    // Private member variables
    int accountNumber;
    int pin;
    double balance;

public:
    //  Public member methods
    Account(int newAccountNumber, int newPin, double startingBalance);
    int getAccountNumber();
    bool authenticate(int enteredPin);
    double getBalance();
    void deposit(double amount);
    bool withdraw(double amount);
};

#endif