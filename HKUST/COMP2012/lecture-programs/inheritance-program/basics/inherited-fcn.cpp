#include <iostream>     /* File: inherited-fcn.cpp */
using namespace std;
#include "student.h"

void some_func(UPerson& uperson, Student& student) {
    cout << uperson.get_name() << endl;
    Department dept = uperson.get_department();
    // Error! Base class object can't call derived class's function
    uperson.enroll_course("COMP1001");

    // Derived class object may call base class's member function
    cout << student.get_name() << endl;
    // Derived class object calls its own member functions
    cout << student.get_GPA() << endl;
    student.enroll_course("COMP2012");
}

int main() {
    UPerson abby("Abby", CBME);
    Student bob("Bob", CIVL, 3.0);
    some_func(abby, bob);
}
