// Author: Miguel Ángel Vargas

#include "Labrational.h"

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