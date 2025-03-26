// Author: Miguel Ángel Vargas

#ifndef LABRATIONAL_H
#define LABRATIONAL_H

#include <iostream>
using namespace std;

class rational
{
public:
	/* TODO: default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
	rational();

	/* TODO: define input to set the calling object's value from user input */
	void input();

	/* TODO: define output to display calling object's value in the standard output, in the form of numerator/denominator */
	void output();

	/* TODO: declare the accessor to return the calling object's numerator */
	int getNumerator() {
		return numerator;
	}
	
	/* TODO: declare the accessor to return the calling object's denominator */
	int getDenominator() {
		return denominator;
	}

	/* TODO: declare Add to set the calling object to be the sum of op1 and op2 */
	void Add(const rational& op1, const rational& op2);

	/* TODO: declare Subtract to set the calling object to the difference of op1 and op2 */
	void Subtract(const rational& op1, const rational& op2);

	/* TODO: declare Multiply to set the calling object to the product of op1 and op2 */
	void Multiply(const rational& op1, const rational& op2);

	/* TODO: declare Divide to set the calling object to the Quotient of op1 and op2 */
	void Divide(const rational& op1, const rational& op2);

private:
	/* TODO: declare data members for rational object */
	int numerator;
	int denominator;
};

#endif // LABRATIONAL_H