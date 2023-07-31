#include <iostream>     /* File: print-label.cpp */
using namespace std;
#include "student.h"
#include "teacher.h"

void print_label(const UPerson& uperson) 
{
    cout << "Name: " << uperson.get_name() << endl;
    cout << "Dept: " << uperson.get_department() << endl;
}

int main()
{
    Student tom("Tom", CIVL, 3.9);
    print_label(tom);   // Tom is also a UPerson

    Teacher alan("Alan Turing", CSE, PROFESSOR, "AI");
    print_label(alan);  // Alan is also a UPerson
    return 0;
}
