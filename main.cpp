#include <iostream>
#include <string>

using namespace std;

string userID, password;
double balance = 0.0;
bool isLoggedIn = false;

void createAccount() {
    cout << "Please enter your user id: ";
    cin >> userID;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Thank You! Your account has been created!" << endl;
}

void login() {
    string inputID, inputPassword;
    cout << "Please enter your user id: ";
    cin >> inputID;
    cout << "Please enter your password: ";
    cin >> inputPassword;

    if (inputID == userID && inputPassword == password) {
        cout << "Access Granted!" << endl;
        isLoggedIn = true;
    } else {
        cout << "*** LOGIN FAILED! ***" << endl;
        isLoggedIn = false;
    }
}

void withdrawMoney() {
    if (isLoggedIn) {
        double amount;
        cout << "Amount of withdrawal: $";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
}

void depositMoney() {
    if (isLoggedIn) {
        double amount;
        cout << "Amount of deposit: $";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful!" << endl;
    }
}

void requestBalance() {
    if (isLoggedIn) {
        cout << "Your balance is $" << balance << endl;
    }
}

int main() {
    char option;

    cout << "Hi! Welcome to the ATM Machine!" << endl;

    do {
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> option;

        switch (option) {
            case 'l':
                login();
                if (isLoggedIn) {
                    char action;
                    do {
                        cout << "d -> Deposit Money" << endl;
                        cout << "w -> Withdraw Money" << endl;
                        cout << "r -> Request Balance" << endl;
                        cout << "q -> Quit" << endl;
                        cout << "> ";
                        cin >> action;

                        switch (action) {
                            case 'd':
                                depositMoney();
                                break;
                            case 'w':
                                withdrawMoney();
                                break;
                            case 'r':
                                requestBalance();
                                break;
                            case 'q':
                                cout << "Logging out..." << endl;
                                isLoggedIn = false;
                                break;
                            default:
                                cout << "Invalid option!" << endl;
                        }
                    } while (action != 'q');
                }
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                cout << "Quitting the program..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (option != 'q');

    return 0;
}
