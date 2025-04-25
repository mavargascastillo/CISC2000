/* 
CISC 2000
Programming assignment #10:
This program is the continuation of the Rational Lab. We will overload operators, add friend funtions, and modify some things from the main
function.
Date: Apr 24, 2025
Author: Miguel Ángel Vargas
 */

#include "Labrational.h"

// Constructor w/ default parameters
rational::rational(int num, int denom) {
    numerator = num;
    denominator = denom;
    simplify();
}

// Accessors
int rational::getNumerator() const {
    return numerator;
}

int rational::getDenominator() const {
    return denominator;
}

// gcd function
int rational::gcd(int a, int b) {
    while (a != 0 && b != 0) {
        a = a % b;
        if (a != 0)
            b = b % a;
    }
    return (a == 0) ? b : a;
}

// simplify function
void rational::simplify() {
    int divisor = gcd(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;
    // Ensure denominator is positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Arithmetic functions. Key chhange = we now use a temp variable to be able to use the simplify function
rational operator+(const rational& op1, const rational& op2) {
    rational temp;
    temp.numerator = op1.numerator * op2.denominator + op2.numerator * op1.denominator;
    temp.denominator = op1.denominator * op2.denominator;
    temp.simplify();
    return temp;
}

rational operator-(const rational& op1, const rational& op2) {
    rational temp;
    temp.numerator = op1.numerator * op2.denominator - op2.numerator * op1.denominator;
    temp.denominator = op1.denominator * op2.denominator;
    temp.simplify();
    return temp;
}

rational operator*(const rational& op1, const rational& op2) {
    rational temp;
    temp.numerator = op1.numerator * op2.numerator;
    temp.denominator = op1.denominator * op2.denominator;
    temp.simplify();
    return temp;
}

rational operator/(const rational& op1, const rational& op2) {
    rational temp;
    if (op2.numerator == 0) {
        cout << "Error: Cannot divide by zero. Returning 0/1.\n";
        return rational(0, 1);
    }
    temp.numerator = op1.numerator * op2.denominator;
    temp.denominator = op1.denominator * op2.numerator;
    temp.simplify();
    return temp;
}

// Stream operators
istream& operator>>(istream& in, rational& r) {
    char slash;
    int num, denom;

    in >> num >> slash >> denom;
    if (!in || slash != '/' || denom == 0) {
        in.setstate(ios::failbit); // mark stream as failed. Ios is part of the iostream library
        cout << "Invalid rational format!" << endl;
        return in;
    }

    r.numerator = num;
    r.denominator = denom;
    r.simplify();
    return in;
}

ostream& operator<<(ostream& out, const rational& r) {
    out << r.numerator << "/" << r.denominator;
    return out;
}

// Relational operators
bool operator==(const rational& op1, const rational& op2) {
    // Cross multiply to avoid floating point comparisons
    return (op1.numerator * op2.denominator) == (op2.numerator * op1.denominator);
}

bool operator<(const rational& op1, const rational& op2) {
    return (op1.numerator * op2.denominator) < (op2.numerator * op1.denominator);
}

bool operator>(const rational& op1, const rational& op2) {
    return (op1.numerator * op2.denominator) > (op2.numerator * op1.denominator);
}

// Set function
void rational::set(int newNumerator, int newDenominator) {
    if (newDenominator == 0) {
        cout << "Error: Denominator cannot be zero. Setting to 1.\n";
        newDenominator = 1;
    }
    numerator = newNumerator;
    denominator = newDenominator;
    simplify();
}