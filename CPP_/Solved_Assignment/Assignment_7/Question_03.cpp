#include <iostream>
#include <string>

using namespace std;

// Enum for account types
enum AccountType {
    saving = 1,
    Current,
    Dmat
};

// Exception class for insufficient funds
class InSufficientFundException {
public:
    string message;

    // Default constructor
    InSufficientFundException() : message("") {}

    // Parameterized constructor
    InSufficientFundException(string message) : message(message) {}

    // Display error message
    void display() {
        cout << "Error: " << message << endl;
    }
};

// Class for BankAccount
class BankAccount {
private:
    int accno;
    AccountType type;
    double balance;

public:
    // Default constructor
    BankAccount() : accno(0), balance(0.0) {}

    // Parameterized constructor
    BankAccount(int accno, AccountType type, double balance)
        : accno(accno), type(type), balance(balance) {}

    // Method to accept account details
    void accept() {
        cout << "Enter Account Number: ";
        cin >> accno;

        cout << "1. Saving\n2. Current\n3. Dmat\n";
        cout << "Enter the Choice of Account Type: ";
        int choice;
        cin >> choice;

        // Set account type based on user's choice
        type = AccountType(choice);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        // Display account created message
        cout << "Account created successfully!\n";
    }

    // Method to deposit amount
    void deposit(double amount) {
        if (amount < 0) {
            throw InSufficientFundException("Cannot deposit a negative amount.");
        }
        balance += amount;
        cout << "Deposit successful! Updated Balance: $" << balance << endl;
    }

    // Method to withdraw amount
    void withdraw(double amount) {
        if (amount > balance) {
            throw InSufficientFundException("Insufficient funds for withdrawal.");
        }
        if (amount < 0) {
            throw InSufficientFundException("Cannot withdraw a negative amount.");
        }
        balance -= amount;
        cout << "Withdrawal successful! Updated Balance: $" << balance << endl;
    }

    // Method to display account details
    void display() const {
        cout << "Account Number: " << accno << endl;
        cout << "Account Type: " << (type == saving ? "Saving" : (type == Current ? "Current" : "Dmat")) << endl;
        cout << "Balance: ₹" << balance << endl;
    }
};

// Main function
int main() {
    BankAccount account;
    bool exit = false;

    // Create account and accept details from user
    account.accept();

    // Menu-driven program
    while (!exit) {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Display Account Info\n4. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        try {
            if (choice == 1) {  // Deposit
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
            } 
            else if (choice == 2) {  // Withdraw
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
            } 
            else if (choice == 3) {  // Display Account Info
                account.display();
            } 
            else if (choice == 4) {  // Exit
                exit = true;
                cout << "Exiting program.\n";
            } 
            else {
                cout << "Invalid option. Please choose again.\n";
            }
        } 
        catch (InSufficientFundException& e) {
            e.display();  // Display custom exception message
        }
    }

    return 0;
}
