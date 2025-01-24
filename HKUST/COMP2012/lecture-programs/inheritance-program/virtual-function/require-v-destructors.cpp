#include <iostream>     /* File: require-v-destructors.cpp */
using namespace std;
#include "v-student.h"

int main()
{
    Student* s = new Student("Simpson", CSE, 3.8);
    s->add_course("COMP1021");
    s->add_course("COMP2012");

    UPerson* p = s;
    delete p; // Can we call UPerson's destructor on a Student?
}
