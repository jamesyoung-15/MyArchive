#include <iostream>     /* File: concrete-destructors.cpp */
using namespace std;
#include "v-student.h"

int main()
{
    UPerson* p = new UPerson("Adam", ECE);
    delete p;

    Student* s = new Student("Simpson", CSE, 3.8);
    s->add_course("COMP1021");
    s->add_course("COMP2012");
    delete s;
}
