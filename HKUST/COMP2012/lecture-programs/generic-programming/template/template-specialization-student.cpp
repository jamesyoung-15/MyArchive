#include <iostream>     /* File: template-specialization-student.cpp */
using namespace std;
#include "student.h"

/* General case  */
template <typename T>
const T& larger(const T& a, const T& b)
    { cout << "general case: "; return (a < b) ? b : a; }

/* Exceptional case  */
template <>
const Student& larger(const Student& a, const Student& b)
    { cout << "special case: "; return (a.get_GPA() < b.get_GPA()) ? b : a; }

int main()
{
    Student a("Amy", ECE, 3.2);
    Student b("Bob", CSE, 4.2);

    cout << larger(a, b).get_name() << " is better!" << endl;
    cout << larger(b, a).get_name() << " is better!" << endl;
    cout << larger(22, 88) << " is greater!" << endl;
    return 0;
}
