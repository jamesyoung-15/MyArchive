#include <iostream>     /* File: rvalue-reference.cpp */
using namespace std;

int square(int x) { return x*x; }
string wrap(string s) { return "begin." + s + ".end";  }

int main()
{   /* rvalue reference with basic types */
    int a = 8;
    int&& b;                  // Error: rvalue ref must be initialized
    int&& c = a;              // Error: rvalue ref can't bind to lvalue
    int&& d = 5; cout << d << endl;
    int&& e = square(5); cout << e << endl;
    d = e = 10; cout << d << '\t' << e << endl << endl;
    
    /* rvalue reference with string objects */
    string s1 {"w"};
    string&& s2;              // Error: rvalue ref must be initialized
    string&& s3 = s1;         // Error: rvalue ref can't bind to lvalue
    string&& s4 = "x"; cout << s4 << endl;
    string&& s5 = wrap("x"); cout << s5 << endl;
    s4 = "z"; cout << s4 << endl;
    s5 = s1; cout << s5 << endl;
    return 0;
}
