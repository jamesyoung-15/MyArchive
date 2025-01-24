#include <iostream>
#include "Contract.h"

using namespace std;

// TODO: Complete the constructor of Contract. Remember to call the constructor of base class.
Contract::Contract(const char* name, double base_salary, int working_hours, double hourly_rate) 
: Employee(name, base_salary), working_hours(working_hours), hourly_rate(hourly_rate)
{}


Contract::~Contract(){
    cout << "Call destructor of Contract" << endl;
}

// TODO: Complete Contract::get_working_hours
int Contract::get_working_hours() const {
    return  working_hours;
}

// TODO: Complete Contract::get_hourly_rate
double Contract::get_hourly_rate() const{
    return hourly_rate;
}

// TODO: Complete Contract::get_salary. Salary = base_salary + hourly_rate * working_hours.
double Contract::get_salary() const{
    return get_base_salary() + hourly_rate * working_hours;
}

void Contract::print() const{
    cout << "Contract worker: " << get_name() << endl;
    cout << "Salary: " << get_salary() << endl;
}

void Contract::info() const{
    cout << "This is a contract worker." << endl;
}