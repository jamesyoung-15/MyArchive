#include <iostream>     /* File: rvalue-ref-int.cpp */
using namespace std;

int square(int x) { return x*x; }

int main()
{
    /* rvalue reference with values of basic types */
    int a = 8;
    int&& b;            // Error: rvalue ref must be initialized
    int&& c = a;        // Error: rvalue ref can't bind to lvalue

    int&& d = 5; cout << d << endl;
    int&& e = square(5); cout << e << endl;

    d = e = 10;                             // d, e used as lvalues
    cout << d << '\t' << e << endl << endl; // d, e used as rvalues
    return 0;
}
