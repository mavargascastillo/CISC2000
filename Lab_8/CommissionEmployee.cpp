#include "CommissionEmployee.h"


// ToDo: implement the default constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee()
    : Employee(), sales(0.0), commission(0.0) {
    // Optionally, debug output:
    // cout << "CommissionEmployee() default constructor called.\n";
}

// ToDo: implement the constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee(const string& name, const string& SSN, double sales, double commission)
    : Employee(name, SSN), sales(sales), commission(commission) 
{
	// deliberately empty
	// cout << "CommissionEmployee(" << name << "," << SSN << "," << sales << "," << commission << ")\n"; 
}

// ToDo: implement accessor/mutators
double CommissionEmployee::get_sales() const {
	return sales;
}

double CommissionEmployee::get_commission() const {
	return commission;
}

void CommissionEmployee::set_sales(double s) {
	sales = s;
}

void CommissionEmployee::set_commission(double c) {
	commission = c;
}

// ToDo: implement virtual get_net_pay function
// Hint: compensation is commission/100 * sales
double CommissionEmployee::get_net_pay() const {
	return (commission / 100.0) * sales;
}

// ToDo: implement the virtual print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void CommissionEmployee::print_check() const
{
	Employee::print_check(); // Call base class method
	cout << "Commission Employee." << endl;
	cout << "Gross sales: " << get_sales() << "Commission: " << get_commission() << "Pay: " << get_net_pay() << endl; 
    cout << "_________________________________________________\n";
}

// ToDo: implement the virtual promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream& CommissionEmployee::promptInput(istream& in, ostream& out)
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
	Employee::promptInput(in, out);

	// ToDo: read the sales and commission.
	out << "Enter sales and commission: ";
	in >> sales >> commission;

	return in;
}