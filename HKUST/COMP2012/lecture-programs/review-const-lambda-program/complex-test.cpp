#include <iostream>     /* File: complex-test.cpp */
using namespace std;
#include "complex.h"

void f(const Complex a) { a.print(); }   // const Complex a  = u
void g(const Complex* a) { a->print(); } // const Complex* a = &u
void h(const Complex& a) { a.print(); }  // const Complex& a = u

int main()
{
    // Check the parameter passing methods
    Complex u(4, 5); f(u); g(&u); h(u);
    
    // Check the parameter returning methods
    Complex w(10, 10); cout << endl << endl;
    Complex x(4, 5); (x.add1(w)).print();    // Complex  temp = *this = x
    Complex y(4, 5); (y.add2(w))->print();   // Complex* temp =  this = &y
    Complex z(4, 5); (z.add3(w)).print();    // Complex& temp = *this = z

    cout << endl << endl;          // What is the output now?
    Complex a(4, 5); a.add1(w).add1(w).print();   a.print(); cout << endl;
    Complex b(4, 5); b.add2(w)->add2(w)->print(); b.print(); cout << endl;
    Complex c(4, 5); c.add3(w).add3(w).print();   c.print();
    return 0;
}
