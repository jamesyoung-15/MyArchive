#include <iostream> /* File: v-print-label.cpp */
using namespace std;
#include "v-student.h"
#include "v-teacher.h"

void print_label_pbv(UPerson uperson) { uperson.print(); }
void print_label_pbr(const UPerson& uperson) { uperson.print(); }
void print_label_pbp(const UPerson* uperson) { uperson->print(); }

int main( )
{
    UPerson uperson("Charlie Brown", CBME);
    Student student("Edison", ECE, 3.5);
    Teacher teacher("Alan Turing", CSE, PROFESSOR, "CS Theory");
	student.add_course("COMP2012"); student.add_course("MATH1003");

    cout << "\n#####  VIRTUAL FUNCTION & PASS BY VALUE  #####\n";
    print_label_pbv(uperson);
    print_label_pbv(student); 
    print_label_pbv(teacher);

    cout << "\n#####  VIRTUAL FUNCTION & PASS BY REFERENCE  #####\n"; 
    print_label_pbr(uperson);
    print_label_pbr(student); 
    print_label_pbr(teacher);

    cout << "\n#####  VIRTUAL FUNCTION & PASS BY POINTER  #####\n"; 
    print_label_pbp(&uperson);
    print_label_pbp(&student); 
    print_label_pbp(&teacher);
}
