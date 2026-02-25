# Secure Bank ATM Simulation 

## Project Overview
This project is a text-based ATM simulation built in C++. It demonstrates fundamental programming concepts including control structures, vectors, and object-oriented programming (classes and encapsulation). A core focus of this project is addressing ethical considerations regarding personal privacy and the secure handling of sensitive financial data.

## Team Members & Roles

* **Ahmed Lotfey:** Backend Data & Security (`Account` Class)
* **Tyler Carpenter:** Transaction Logic & Routing (Menus & Operations)
* **Riley Erickson:** User Interface & Error Management (Input Validation & Formatting)

---

## Task Assignments & Implementation Details

### 1. Ahmed: Backend Data & Security (`Account` Class)
**Objective:** Design the core data structure that holds user information and enforces security protocols. This directly addresses the project's ethical and privacy requirements.



**Key Responsibilities:**
* **Encapsulation:** Ensure all sensitive data variables (`accountNumber`, `pin`, `balance`) are marked as `private`. 
* **Authentication:** Implement the `authenticate(int enteredPin)` method to verify user identity before granting access to the balance.
* **Core Functions:** Write the `deposit(double amount)` and `withdraw(double amount)` methods. Ensure `withdraw` checks for sufficient funds and returns a boolean (`true` if successful, `false` if not).
* **Security Enhancement (Bonus):** Add an `int failedAttempts` variable to the class. If a user fails to authenticate 3 times, set a `bool isLocked` to `true` and prevent further login attempts for that account.

### 2. Tyler: Transaction Logic & Routing (Menus & Operations)
**Objective:** Build the main application loop and handle the business logic of moving money around, specifically focusing on inter-account transfers.

**Key Responsibilities:**
* **Main Menu Loop:** Construct the `while` loop and `switch` statement that drives the user session after a successful login.
* **Transfer Logic:** Implement the "Transfer Funds" feature. This requires:
    1.  Prompting for a destination account number.
    2.  Using a search function to find the target account in the `vector<Account>`.
    3.  Withdrawing from the active user and depositing into the target user *only* if the withdrawal is successful.
* **Business Rules (Bonus):** Implement daily transaction limits (e.g., preventing a user from withdrawing more than $1,000 in a single session).

### 3. Riley: User Interface & Error Management
**Objective:** Ensure the application is user-friendly, visually clean in the console, and robust against bad user input (preventing crashes).

**Key Responsibilities:**
* **Input Validation:** Use `cin.fail()` to handle situations where a user types a letter instead of a number. You will need to use `cin.clear()` and `cin.ignore()` to flush the input buffer so the program doesn't enter an infinite loop.
* **Output Formatting:** Include the `<iomanip>` library to ensure all dollar amounts are formatted strictly to two decimal places (e.g., `$50.00` instead of `$50`). 
    * *Hint: Use `cout << fixed << setprecision(2);`*
* **UI Polish:** Design clear, easy-to-read console headers, spacing, and error messages. Ensure the user clearly understands what inputs are expected at all times.

---

## How to Run
1. Clone this repository.
2. Compile the `main.cpp` file using standard C++11 (or higher).
3. Run the executable in your terminal. 

