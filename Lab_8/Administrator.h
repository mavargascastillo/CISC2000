/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional members:
 *  1. a string type member variable to store the title (director, Vice President, ... )
 *  3. Constructor functions: one default one, another taking necessary info. about the administrator: name, SSN, salary, title
 *  4. redefine print_check() so that the title is printed on the check. Start with the version from 
 *  SalariedEmployee
 */
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator:public SalariedEmployee
{
  public:
	// ToDo: declare default constructor for Administrator
	Administrator();

	// ToDo: declare constructor for Administrator that takes a name, SSN, salary, title, bonus
	Administrator(const string& name, const string& SSN, double salary,
		const string& title, double bonus);

	// ToDo: declare Accessor/Mutator functions
	string get_title() const;
    double get_bonus() const;

	void set_title(const string& t);
    void set_bonus(double b);

	// ToDo: declare vitual functions to override
	virtual void print_check() const override;
    virtual istream& promptInput(istream& in, ostream& out) override;
    virtual double get_net_pay() const override;

  private: 
	// ToDo: declare a job title, bonus member
	string title;
    double bonus;

};

#endif
