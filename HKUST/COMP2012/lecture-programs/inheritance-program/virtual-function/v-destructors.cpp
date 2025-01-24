#include <iostream>     /* File: v-destructors.cpp */
using namespace std;
#include "v-student2.h" // With virtual destructor

int main()
{
    Student* s = new Student("Simpson", CSE, 3.8);
    s->add_course("COMP1021");
    s->add_course("COMP2012");

    UPerson* p = s;
    delete p;           // Actually call Student's destructor
}
