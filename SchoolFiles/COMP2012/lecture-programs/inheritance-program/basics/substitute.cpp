#include <iostream>     /* File: substitute.cpp */
using namespace std;
#include "student.h"

int main() {
    void dance(const UPerson& p); // Anyone can dance
    void dance(const UPerson* p); // Anyone can dance
    void study(const Student& s); // Only students study
    void study(const Student* s); // Only students study
    UPerson p("P", IELM); Student s("S", MAE, 3.3);

    // Which of the following statements can compile? 
    dance(p);
    dance(s);
    dance(&p); 
    dance(&s);
    study(s); 
    study(p);
    study(&s); 
    study(&p);
}
