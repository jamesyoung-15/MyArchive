#include <iostream>     /* File: pg-print-label.cpp */
using namespace std;
#include "pg-student.h" // Change student.h to pg-student.h

void print_label(const UPerson& uperson) 
{
    cout << "Name: " << uperson.get_name() << endl;
    cout << "Dept: " << uperson.get_department() << endl;
}

int main()
{
    PG_Student tom("Tom", CIVL, 3.9); // Tom is now a PG Student
    print_label(tom);                 // Tom is also a UPerson
    return 0;
}
