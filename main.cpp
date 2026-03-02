#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include "Account.h"

using namespace std;

int findAccount(vector<Account>& accounts, int accountNumber) {
	for (size_t i = 0; i < accounts.size(); ++i) {
		if (accounts[i].getAccountNumber() == accountNumber) {
			return i;
			}
		}
	return -1;
}

int main() {
	cout << fixed << setprecision(2);
	
	vector<Account> accounts = {
	Account(123456, 1234, 1000.00),
	Account(567890, 5678, 2000.00)
	};
	
	const double DAILY_LIMIT = 1000.0;
	bool systemRunning = true;
	
	while (systemRunning) {
	int attempts = 0;
	int activeIndex = -1;

	// ==== Login Loop ====
	while (attempts < 3) {
		
	cout << "Enter account number: ";
	int inputAcc;
	
	if (!(cin >> inputAcc)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input. Please enter numbers only.\n";
		continue;
	}
	
	cout << "Enter PIN: ";
	int inputPin;
	
	if (!(cin >> inputPin)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input. Please enter numbers only.\n";
		continue;
	}
	
	activeIndex = findAccount(accounts, inputAcc);
	
	if (activeIndex != -1 && accounts[activeIndex].authenticate(inputPin)) {
		cout << "Login successful.\n";
		break;
	}
	attempts++;
	cout << "Invalid credentials. Attempts remaining: " << (3 - attempts) << "\n";
	}
	
	if (attempts == 3) {
		cout << "Too may failed attempts. Session ended.\n";
		break;
	}
	
	/* ====== Main Menu ===== */
	
	double sessionWithdrawn = 0.0;
	bool loggedIn = true;
	
while (loggedIn) {
		cout << "\n--- Main Menu ---\n";
		cout << "1) Show Balance\n2) Deposit\n3) Withdraw\n4) Transfer Funds\n5) Exit\n";
		cout << "Enter in a number to select an option: ";
		
		int choice;
		
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Please enter whole numbers only.\n";
			continue;
		}
		
		switch (choice) {
			case 1: {
				cout << "Current balance: $" << accounts[activeIndex].getBalance() << endl;
				break;
			}
			
			case 2: {
				double amount;
				cout << "Enter deposit amount: ";
				cin >> amount;
				accounts[activeIndex].deposit(amount);
				break;
			}
			
			case 3: {
				double amount;
				cout << "Enter withdrawal amount: ";
				cin >> amount;
				
			if ((sessionWithdrawn + amount) > DAILY_LIMIT) {
				cout << "Error: Daily withdrawal limit exceeded of $" << DAILY_LIMIT << " exceeded.\n";
				}
			else if (accounts[activeIndex].withdraw(amount)) {
				sessionWithdrawn += amount;
				}
				break;
			}
			
			case 4: {
				int destAccountNumber;
				cout << "Enter destination account number: ";
				cin >> destAccountNumber;
				
				int destIndex = findAccount(accounts, destAccountNumber);
				if (destIndex == -1) {
					cout << "Error: Destination account not found.\n";
					break;
				}
				
				double transferAmount;
				cout << "Enter amount to transfer: ";
				cin >> transferAmount;
				
				if (transferAmount <= 0) {
					cout << "Error: Transfer amount must be positive.\n";
					break;
				}
				
				if ((sessionWithdrawn + transferAmount) > DAILY_LIMIT) {
					cout << "Error: Transfer exceeds your daily transaction limit of $" << DAILY_LIMIT << ".\n";
					break;
				}
				
				if (accounts[activeIndex].withdraw(transferAmount)) {
					accounts[destIndex].deposit(transferAmount);
					sessionWithdrawn += transferAmount;
					cout << "Successfully transferred $" << transferAmount << " to account #" << destAccountNumber << ".\n";
				}
				else {
					cout << "Transfer failed due to insufficient funds.\n";
					}
					break;
				}
				
				case 5: {
					loggedIn = false;
					systemRunning = false;
					cout << "Thank you for using our ATM." << endl;
					break;
				}
				default: {
				cout << "Invalid selection. Try again." << endl;
				}
			}
		}
	}
	return 0;
}
	
				
		

			
				
				
					

		
	
