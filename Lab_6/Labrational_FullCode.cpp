/* 
CISC 2000
Programming assignment #8:
This program is a second assignment with classes. We provide two rational numbers and we carry out operations with them
Date: Mar 25, 2025
Author: Miguel Ángel Vargas
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class rational
{
public:
	/* TODO: default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
	rational() {
		numerator = 0;
		denominator = 1;
	}

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


int main()
{
	char oper;
	// TODO: declare rational objects for result and operand.
	rational result, operand;

	cout << "Enter op1 (in the format of p/q): ";
	// TODO: Use your input function to read the first operand into result.
	result.input();

	//Test rational class member function 
	do {
		cout << "\nEnter operator [+, -, /, *, =, c(lear), a(ccessors), q(uit)]: ";
		// TODO: Read the operator into oper
		cin >> oper;

		// TODO: Test oper for binary operators
		if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
			cout << "\nEnter op2 (in the format of p/q): ";
			// TODO: Use your input function to read the operand into operand
			operand.input();
		}

		// ToDo: Implement a switch or multiway if statement with one case for each option above where
		// '+','*','/','-' inputs a rational op1 and calculates result.oper(result,op1)
		// '=' outputs the current result,
		// 'c' to clear current result, use input function to read first operand into result,
		// 'a' to test accessors, 'q' to quit.
		switch (oper) {
            case '+':
                result.Add(result, operand);
                break;
            case '-':
                result.Subtract(result, operand);
                break;
            case '*':
                result.Multiply(result, operand);
                break;
            case '/':
                result.Divide(result, operand);
                break;
            case '=':
                cout << "result: ";
                result.output();
                cout << endl;
                break;
            case 'c':
				cout << "Enter op1 (in the format of p/q): ";
                result.input();
                break;
			case 'a':
				cout << "result's numerator is: " << result.getNumerator() << endl
				<<  "result's denominator is: " << result.getDenominator() << endl;
				break;
            case 'q':
                break;
            default:
                cout << "Invalid operator. Try again.\n";
        }
	} while (oper != 'q');
	return 0;
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