//#pragma once
#include <iostream>
#include "Employee.h"

#ifndef _COMMISSION_H
#define _COMMISSION_H

using namespace std;

class CommissionEmployee : public Employee
{
public:
	// ToDo: declare default constructor for CommissionEmployee
	CommissionEmployee();

	// ToDo: declare constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
	CommissionEmployee(const string& name, const string& ssn, double sales, double commission);

	// ToDo: declare Accessor/Mutator functions
	double get_sales() const;
    double get_commission() const;

	void set_sales(double s);
    void set_commission(double c);

	// ToDo: declare vitual functions to override
	virtual void print_check() const override;
    virtual istream& promptInput(istream& in, ostream& out) override;
    virtual double get_net_pay() const override;

private:
	// ToDo: declare a sales, commission percent member
	double sales;
    double commission;

};
#endif // _COMMISSION_H

