#include <cstring>
#include <iostream>
#include "Employee.h"
#include "Full_time.h"

using namespace std;

// TODO: Complete the constructor of Full_time class. 
//       Remember to call the constructor of base class, use new to initialize char*position.
Full_time::Full_time(const char* name, double base_salary, const char* position, int seniority, double bonus)
: Employee(name, base_salary)
{
    this->position = new char [strlen(position)+1];
    strcpy(this->position,position);
    this->seniority = seniority;
    this->bonus = bonus;
}


Full_time::~Full_time() {
    cout << "Call destructor of Full_time" << endl;
// TODO: dynamic memory deallocation
    if(position!=nullptr)
    {
        delete [] position;
    }
}

// TODO: Complete Full_time::get_position
string Full_time::get_position() const{
    return position;
}

// TODO: Complete Full_time::get_seniority
int Full_time::get_seniority() const{
    return seniority;
}

// TODO: Complete Full_time::get_bonus
double Full_time::get_bonus() const{
   return bonus;
}

// TODO: Complete Full_time::get_salary. Salary = base_salary + 0.1 * base_salary * seniority + bonus
double Full_time::get_salary() const{
    return get_base_salary() + 0.1 * get_base_salary() * seniority + bonus;
}

void Full_time::print() const{
    cout << "Full_time employee: " << get_name() << ", position: " << get_position() << endl;
    cout << "Salary: " << get_salary() << endl;
}