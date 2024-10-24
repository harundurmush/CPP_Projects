#include <iostream>
#include <conio.h>

using namespace std;

class bank {
    char name[100], address[100], y;
    int balance;
    float withdraw;
    bool account_exists;

public:
    bank() : balance(0), withdraw(0), account_exists(false) {}

    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
};

void bank::open_account() {
    cout << "Enter your full name: ";
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.getline(address, 100);
    cout << "What type of account you want to open: saving (s) or current (c) ";
    cin >> y;
    cout << "Enter amount for deposit: ";
    cin >> balance;
    account_exists = true;
    cout << "\033[32mYour account is created\033[0m\n";  // Green message only for "Your account is created"
}

void bank::deposit_money() {
    if (account_exists) {
        cout << "Enter how much you deposit: ";
        cin >> balance;
        cout << "Total balance:\t" << balance;
    } else {
        cout << "\033[1;31mYou should create an account first.\033[0m\n";  // Red error message
    }
}

void bank::withdraw_money() {
    if (account_exists) {
        cout << "Enter amount to withdraw: ";
        cin >> withdraw;
        if (withdraw <= balance) {
            balance -= withdraw;
            cout << "Now total amount is left:\t" << balance;
        } else {
            cout << "\033[1;31mYour withdraw demand is too high for your balance. Your balance:\t" << balance << "\033[0m\n";  // Red error message
        }
    } else {
        cout << "\033[1;31mYou should create an account first.\033[0m\n";  // Red error message
    }
}

void bank::display_account() {
    if (account_exists) {
        cout << "Your full name:\t" << name;
        cout << "\nYour address:\t" << address;
        cout << "\nType of account:\t" << y;
        cout << "\nAmount of your balance:\t" << balance;
    } else {
        cout << "\033[1;31mYou should create an account first.\033[0m\n";  // Red error message
    }
}

int main() {
    int selection;
    char x;
    bank obj;

    do {
        cout << "1) Open Account\n";
        cout << "2) Deposit Money\n";
        cout << "3) Withdraw Money\n";
        cout << "4) Display Account\n";
        cout << "5) Exit\n";
        cout << "Select the option from above\n";
        cin >> selection;

        switch (selection) {
        case 1:
            obj.open_account();
            break;
        case 2:
            obj.deposit_money();
            break;
        case 3:
            obj.withdraw_money();
            break;
        case 4:
            obj.display_account();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\033[1;31mThis is not exist, try again\033[0m\n";  // Red error message
        }

        cout << "\nDo you want to select next option, then press: y\n";
        cout << "If you want to exit, then press: N\n";
        x = getch();
    } while (x == 'y' || x == 'Y');

    return 0;
}
