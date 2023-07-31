#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstring>
#include <iostream>

using namespace std;

class Employee {
    private:
        char* name;
        double base_salary;
		
    public:
    /* TODO: Complete the member function declaration of the Employee class. 
	   Please refer to the figure on the lab website, use a virtual function
	   when there is an override, and remember to make the destructor virtual.
    */

    // constructor
    Employee(const char* name, double base_salary);

    // destructor
    virtual ~Employee();
    // copy
    Employee(const Employee & employee);

    // accessor
    string get_name() const;
    double get_base_salary() const;
    virtual double get_salary() const;
    virtual void print() const;
};

#endif