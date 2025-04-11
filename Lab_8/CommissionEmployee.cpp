#include "CommissionEmployee.h"


// ToDo: implement the default constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee()
    : Employee(), sales(0.0), commission(0.0) {
    // Optionally, debug output:
    // cout << "CommissionEmployee() default constructor called.\n";
}

// ToDo: implement the constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee(string name, string SSN, double sales, double commission)

{
	// deliberately empty
	// cout << "CommissionEmployee(" << name << "," << SSN << "," << sales << "," << commission << ")\n"; 
}

// ToDo: implement accessor/mutators
double ComissionEmployee::get_sales() const {
	return sales;
}

double ComissionEmployee::get_commission() const {
	return comission;
}

void ComissionEmployee::set_sales(double s) {
	sales = s;
}

void ComissionEmployee::set_commission(double c) {
	comission = c;
}

// ToDo: implement virtual get_net_pay function
// Hint: compensation is commission/100 * sales
double ComissionEmployee::get_net_pay() const {
	return (comission / 100.0) * sales;
}

// ToDo: implement the virtual print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void CommissionEmployee::print_check() const
{
	Employee::print_check(); // Call base class method
	cout << "Salaried Employee. Regular Pay: " << salary << endl; 
    cout << "_________________________________________________\n";
}

// ToDo: implement the virtual promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream& CommissionEmployee::promptInput(istream& in, ostream& out)
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
	Employee::promptInput(in, out);

	// ToDo: read the sales and commission.
	out << "Enter sales and cmmission: ";
	in >> sales, comission;

	return in;
}



