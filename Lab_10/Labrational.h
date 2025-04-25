// Author: Miguel Ángel Vargas

#ifndef LABRATIONAL_H
#define LABRATIONAL_H

#include <iostream>
using namespace std;

class rational
{
public:
	// Default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
	rational(int num = 0, int denom = 1);

	// Accessors
	int getNumerator() const; // change to const. It allows to not modify the objects, which improves flexibility. 
	int getDenominator() const; // change to const too

	// New set function that takes newNum and newDen
	void set(int newNumerator, int newDenominator);

	// Friend arithmetic operators following instructions:
	friend rational operator+(const rational& op1, const rational& op2); // parameters remain the same
    friend rational operator-(const rational& op1, const rational& op2);
    friend rational operator*(const rational& op1, const rational& op2);
    friend rational operator/(const rational& op1, const rational& op2);

	// Friend relational operators following instructions
	friend bool operator==(const rational& op1, const rational& op2);
    friend bool operator<(const rational& op1, const rational& op2);
    friend bool operator>(const rational& op1, const rational& op2);

	// Friend stream operators
    friend istream& operator>>(istream& in, rational& r);
    friend ostream& operator<<(ostream& out, const rational& r);

private:
	// Declare data members for rational object 
	int numerator;
	int denominator;

	// Simplify function
	void simplify();
	int gcd(int a, int b);
};

#endif // LABRATIONAL_H