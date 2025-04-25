// Author: Miguel Ángel Vargas

#include "Labrational.h"

int main()
{
	char oper;
	// TODO: declare rational objects for result and operand.
	rational result, operand;

	cout << "Enter op1 (in the format of p/q): ";
	// TODO: Use your input function to read the first operand into result.
	cin >> result;

	//Test rational class member function 
	do {
		cout << "\nEnter operator [+, -, /, *, =, ?(==), <(less), >(greater), c(lear), a(ccessors), q(uit)]: ";
		cin >> oper;

		// We now include the relational operators
		if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '?' || oper == '<' || oper == '>') {
			cout << "\nEnter op2 (in the format of p/q): ";
			// We are now able to just use cin
			cin >> operand;
		}

		// ToDo: Implement a switch or multiway if statement with one case for each option above where.
		// We now apply the overloaded operators
		switch (oper) {
            case '+':
                result = result + operand;
                break;
            case '-':
                result = result - operand;
                break;
            case '*':
                result = result * operand;
                break;
            case '/':
                result = result / operand;
                break;
            case '=':
                cout << "result = " << result << endl;
                break;
            case '?':
                cout << ((result == operand) ? "Correct! Good job!" : "Oh no! Good try!") << endl;
                break;
            case '<':
                cout << ((result < operand) ? "True, great!" : "False, try again!") << endl;
                break;
            case '>':
                cout << ((result > operand) ? "True, great!" : "False, try again!") << endl;
                break;
            case 'c':
                cout << "\nEnter op1 (in the format of p/q): ";
                cin >> result;
                break;
            case 'a':
                cout << "\nresult's numerator is: " << result.getNumerator() << endl
                     << "result's denominator is: " << result.getDenominator() << endl;
                break;
            case 'q':
                break;
            default:
                cout << "\n";
        }

		// Handle invalid input (e.g., bad rational format)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
	} while (oper != 'q');
	return 0;
}