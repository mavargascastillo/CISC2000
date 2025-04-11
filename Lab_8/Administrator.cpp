/* Implement Administrator class */
#include <iostream>
#include "Administrator.h"

using namespace std;

// ToDo: implement the default constructor, remember to call base class constructor
Administrator::Administrator()
	: SalariedEmployee(), title(""), bonus(0.0) {

}

// ToDo: implement the constructor, remember to call base class constructor
Administrator::Administrator(const string& name, const string& SSN, double salary, const string& title, double bonus)
	: SalariedEmployee(name, SSN, salary), title(title), bonus(bonus)
{
	// deliberately empty
	// cout << "Adminstrator(" << name << "," << SSN << "," << salary << "," << title << ")\n"; 
}


// ToDo: implement accessor/mutators
string Administrator::get_title() const {
	return title;
}

double Administrator::get_bonus() const {
	return bonus;
}

void Administrator::set_title(const string& t) {
	title = t;
}

void Administrator::set_bonus(double b) {
	bonus = b;
}

// ToDo: implement virtual functions


// ToDo: implement virtual get_net_pay function
// Hint: compensation is salary + bonus
double Administrator::get_net_pay() const {
    return get_salary() + bonus;
}

// ToDo: implement the print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void Administrator::print_check() const {
	SalariedEmployee::print_check(); // Call base class method
	cout << "Salaried Employee. Regular Pay: " << salary << endl; 
    cout << "_________________________________________________\n";
}

// ToDo: implement the promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream & Administrator::promptInput(istream & in, ostream & out) 
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
	SalariedEmployee::promptInput(in, out);

	// ToDo: read the bonus. Use ignorespace() to skip newline.
	out << "Enter bonus amount: ";
    in >> bonus;
	ignorespace(in);

	// ToDo: read the rest of the line for the title
	out << "Enter job title: ";
    getline(in, title);  // Read full title with spaces

	return in;

}

