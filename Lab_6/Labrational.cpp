/* 
CISC 2000
Programming assignment #8:
This program is a second assignment with classes. We provide two rational numbers and we carry out operations with them
Date: Mar 25, 2025
Author: Miguel Ángel Vargas
 */

#include "Labrational.h"

// Default constructor initializes rational number to 0/1
rational::rational() {
    numerator = 0;
    denominator = 1;
}

// TODO: Definitions of all member functions declared above
void rational::input() {
    char slash;
    // cout << "Enter op1 (in the format of p/q): " I moved it to the switch case 'c'
    cin >> numerator >> slash >> denominator;

    // Ensure denominator is not zero
    if (denominator == 0) {
        cout << "Error: Denominator cannot be zero. Setting to 1.\n";
        denominator = 1;
    }
}

void rational::output() {
    cout << numerator << "/" << denominator;
}

// Accessors
int rational::getNumerator() const {
    return numerator;
}

int rational::getDenominator() const {
    return denominator;
}

// Functions
void rational::Add(const rational& op1, const rational& op2) {
    numerator = (op1.numerator * op2.denominator) + (op2.numerator * op1.denominator); // least common multiple
    denominator = op1.denominator * op2.denominator;
}

void rational::Subtract(const rational& op1, const rational& op2) {
    numerator = (op1.numerator * op2.denominator) - (op2.numerator * op1.denominator);
    denominator = op1.denominator * op2.denominator;
}

void rational::Multiply(const rational& op1, const rational& op2) {
    numerator = op1.numerator * op2.numerator;
    denominator = op1.denominator * op2.denominator;
}

void rational::Divide(const rational& op1, const rational& op2) {
    if (op2.numerator == 0) {
        cout << "Error: Cannot divide by zero.\n";
        numerator = 0;
        denominator = 1;
    } else {
        numerator = op1.numerator * op2.denominator;
        denominator = op1.denominator * op2.numerator;
    }
}