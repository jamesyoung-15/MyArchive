#include <iostream>     /* File: print-label.cpp */
using namespace std;
#include "student.h"
#include "teacher.h"

void print_label_v(UPerson uperson) { uperson.print(); }
void print_label_r(const UPerson& uperson) { uperson.print(); }
void print_label_p(const UPerson* uperson) { uperson->print(); }

int main() {
    UPerson uperson("Charlie Brown", CBME);
    Student student("Edison", ECE, 3.5);
    Teacher teacher("Alan Turing", CSE, PROFESSOR, "CS Theory");
    student.add_course("COMP2012"); student.add_course("MATH1003");

    cout << "\n##### PASS BY VALUE  #####\n";
    print_label_v(uperson); print_label_v(student); print_label_v(teacher);

    cout << "\n##### PASS BY REFERENCE  #####\n"; 
    print_label_r(uperson); print_label_r(student); print_label_r(teacher);

    cout << "\n##### PASS BY POINTER  #####\n"; 
    print_label_p(&uperson); print_label_p(&student); print_label_p(&teacher);
}
