#include <iostream>     /* File: list-example.cpp */
using namespace std;
#include "list.h"
#include "student.h"

int main() 
{
    List<char> letters; letters.append('a'); 
    cout << "*** print char list *** \n"; letters.print();
    
    List<int> primes; primes.append(2);
    cout << "### print int list ###\n"; primes.print();

    List<Student> students; 
    students.append(Student("James", CSE, 4.0));
    // Why don't we call students.print() ?
}
