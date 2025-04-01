//Implementation of the class CheckingAccount.
#include <iostream>
#include <cmath>
using namespace std;

// To Do: include necessary header files
#include "CheckingAccount.h"


// To Do: Please write comments and code to implement CheckingAccount here

// Constructor with full parameters
CheckingAccount::CheckingAccount(int dollars, int cents, double fee) 
    : BankAccount(dollars, cents), check_fee(fee) {}

// Constructor with whole dollars only
CheckingAccount::CheckingAccount(int dollars, double fee) 
    : BankAccount(dollars, 0), check_fee(fee) {}

// Default constructor
CheckingAccount::CheckingAccount() 
    : BankAccount(), check_fee(0.00) {} // important to not forget the fee here

// Accessor for check fee
double CheckingAccount::getCheckFee() const {
    return check_fee;
}

// Output function override
void CheckingAccount::output(ostream &outs) const {
    BankAccount::output(outs); 
    outs << "Check Fee: $" << round(check_fee * 100) / 100 << endl; // Ensures proper rounding
}

// Input function override
void CheckingAccount::input(istream &ins) {
    BankAccount::input(ins);
    cout << "Enter check fee: ";
    ins >> check_fee;
    check_fee = round(check_fee * 100) / 100; // Ensures only two decimal places
}

// Check function (withdraw + check fee)
void CheckingAccount::check(int dollars, int cents) {
    double amount = dollars + (cents / 100.0);
    double totalAmount = amount + check_fee;

    // Round to two decimal places for accuracy
    totalAmount = round(totalAmount * 100) / 100;

    if (totalAmount <= getBalance()) {
        withdraw(dollars, cents);
        withdraw(0, static_cast<int>(round(check_fee * 100))); // Deduct check fee
    } else {
        cout << "Insufficient funds for this transaction.\n";
    }
}