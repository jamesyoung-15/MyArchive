#include <string>       /* File: no-slicing.cpp */
using namespace std;

// class Student: protected UPerson { ... }
#include "protected-student.h"

int main()
{
    Student ug("UG", ECE, 3.0);
    UPerson p = ug;     // Allowed or not?
    UPerson* q = &ug;   // Allowed or not?
    UPerson& r = ug;    // Allowed or not?
    return 0;
}
