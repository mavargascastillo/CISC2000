//#pragma once
#include <iostream>
#include "Employee.h"

#ifndef _COMMISSION_H
#define _COMMISSION_H

class CommissionEmployee : public Employee
{
public:
	// ToDo: declare default constructor for CommissionEmployee
	ComissionEmployee();

	// ToDo: declare constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
	ComissionEmployee(const std::string& name, int id, double sales, double commission);

	// ToDo: declare Accessor/Mutator functions
	double get_sales() const;
    double get_commission() const;

	void set_sales(double s);
    void set_commission(double c);

	// ToDo: declare vitual functions to override
	virtual void print_check() const override;
    virtual std::istream& promptInput(std::istream& in, std::ostream& out) override;
    virtual double get_net_pay() const override;

private:
	// ToDo: declare a sales, commission percent member
	double sales;
    double commission;

};
#endif // _COMMISSION_H

