#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ATM {
private:
    double balance;

public:
    ATM() : balance(10000) {} // Initial balance

    double get_balance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance. You cannot withdraw more than " << balance << endl;
        } else {
            balance -= amount;
            cout << "Successfully withdrew: " << amount << endl;
        }
    }
};

class AtmOperations {
private:
    ATM atm;
    vector<string> mini_statement;

public:
    void view_balance() {
        cout << "Current Balance: " << atm.get_balance() << endl;
    }

    void withdraw_amount(double withdraw_amount) {
        if (withdraw_amount <= 0) {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        } else {
            atm.withdraw(withdraw_amount);
            mini_statement.push_back("Withdrawn: " + to_string(withdraw_amount));
            cout << "Updated Balance: " << atm.get_balance() << endl;
        }
    }

    void deposit_amount(double deposit_amount) {
        atm.deposit(deposit_amount);
        if (deposit_amount > 0) { // Only add to mini statement if the deposit was valid
            mini_statement.push_back("Deposited: " + to_string(deposit_amount));
            cout << "Updated Balance: " << atm.get_balance() << endl;
        }
    }

    void view_mini_statement() {
        cout << "Mini Statement:" << endl;
        for (const string &entry : mini_statement) {
            cout << entry << endl;
        }
    }
};

int main() {
    AtmOperations atm_operations;

    while (true) {
        cout << "\nATM Menu:" << endl;
        cout << "1. View Balance" << endl;
        cout << "2. Withdraw Amount" << endl;
        cout << "3. Deposit Amount" << endl;
        cout << "4. View Mini Statement" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atm_operations.view_balance();
                break;
            case 2: {
                double withdraw_amount;
                cout << "Enter amount to withdraw: ";
                cin >> withdraw_amount;
                atm_operations.withdraw_amount(withdraw_amount);
                break;
            }
            case 3: {
                double deposit_amount;
                cout << "Enter amount to deposit: ";
                cin >> deposit_amount;
                atm_operations.deposit_amount(deposit_amount);
                break;
            }
            case 4:
                atm_operations.view_mini_statement();
                break;
            case 5:
                cout << "Thank you for using the ATM." << endl;
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0; // Just in case, although it won't reach here
}