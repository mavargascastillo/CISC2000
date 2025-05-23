/* 
CISC 2000
Programming assignment #3:
This program solves a quadratic equation. This assignment in particular wanted me to debug a given starter code
by using ONLINEGDB's debugger tool 
Date: Feb 11, 2025
Author: Miguel Ángel Vargas
 */ 

#include <iostream>
#include <cmath>
using namespace std;

const int X1_INDEX = 1;
const int X2_INDEX = 0;
const int A_INDEX = 0;
const int B_INDEX = 1;
const int ROOTS = 2;
const int C_INDEX = 3;
const int COEFFS = 3;

void GetCoefficients(double& a, double& b, double& c); // Here is the first bug, we should pass parameters by reference
// Get the coefficients for the Quadratic equation.
// @param a, b, c reads the coefficients

static bool SolveQuadratic(double a, double b, double c, double *px1, double *px2);
// Solve the quadratic equation represented by a, b, c as coefficients
// @param a, b, c are the coefficients
// @param px1, px2 are the pointers to the roots
// @return true if the roots are real or false when imaginary.

static void DisplayRoots(double x1, double x2, bool isReal);
// Display the roots using isReal to determine how to print.

// There are problems with this code. Problems that may cause fatal
// errors, but probably not. Open www.opengdb.com in another window
// and follow the instructions for debugging this lab.
int main() {
	char retry;
	do {
		// Using arrays to store coeffs and solutions.
		double coeffs[COEFFS], solutions[ROOTS];
		double *px1 = &solutions[X1_INDEX];     // Use pointers in SolveQuadratic
		double *px2 = &solutions[X2_INDEX];
		bool isReal = true;

		// Read the coefficients
		GetCoefficients(coeffs[A_INDEX], coeffs[B_INDEX], coeffs[C_INDEX]);

		// Solve the equation
		isReal = SolveQuadratic(coeffs[A_INDEX], coeffs[B_INDEX], coeffs[C_INDEX],
			px1, px2);

		// Print the results.
		DisplayRoots(solutions[X1_INDEX], solutions[X2_INDEX], isReal);

		cout << "Try again? (y or Y) ";
		cin >> retry;
	} while (retry == 'Y' || retry == 'y');

	return 0;
}

// GetCoefficient reads the coefficients
// @param a, b, c reads the coefficients
void GetCoefficients(double& a, double& b, double& c)
{
	cout << "Enter coefficients a, b and c: ";
	cin >> a >> b >> c;
}

// SolveQuadratic solves the quadratic equation and returns the roots
// @param a, b, c are the coefficients
// @param px1, px2 are the pointers to the roots
// @return true if the roots are real or false when imaginary.
bool SolveQuadratic(double a, double b, double c, double* px1, double* px2)
{
	double discriminant = b * b - 4 * a*c;

	// Check if a = 0 to see if the equation is linear instead of quadratic
	if (a == 0) {
		cout << "The equation is not linear" << endl;
		return false;
	}

	// Two different roots for this equation
	if (discriminant > 0) {
		*px1 = (-b + sqrt(discriminant)) / (2 * a);
		*px2 = (-b - sqrt(discriminant)) / (2 * a);
		return true;
	}

	// One root satisfies both
	else if (discriminant == 0) {
		*(px1) = (-b + sqrt(discriminant)) / (2 * a);
		*px2 = *px1;
		return true;
	}

	// Read part in px1, imaginary part in px2.
	else {
		*px1 = -b / (2 * a);
		*px2 = sqrt(-discriminant) / (2 * a);
		return false;
	}
}

//
// DisplayRoots - display 2 roots using information of real and imaginary.
// @param x1 - always contains a root.
// @param x2 - only contains a root when different or isReal false.
// @param isReal - tells whether roots are real or imaginary.
static void DisplayRoots(double x1, double x2, bool isReal)
{
	if (isReal) {
		if (x1 != x2) {
			cout << "Roots are real and different." << endl;
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}

		else if (x1 == x2) {
			cout << "Roots are real and same." << endl;
			cout << "x1 = x2 =" << x1 << endl;
		}
	}
	else {
		cout << "Roots are complex and different." << endl;
		cout << "x1 = " << x1 << "+" << x2 << "i" << endl;
		cout << "x2 = " << x1 << "-" << x2 << "i" << endl;
	}

}