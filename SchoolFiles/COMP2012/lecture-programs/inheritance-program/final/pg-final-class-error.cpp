#include <iostream>     /* File: pg-final-error.cpp */
using namespace std;

class UPerson { /* incomplete */ };
class Student final : public UPerson { /* incomplete */ };
class PG_Student : public Student { /* incomplete */ };

int main()
{
    UPerson abby("Abby", CBME);
    Student bob("Bob", CIVL, 3.0);
    PG_Student matt("Matt", CSE, 3.8);
}
