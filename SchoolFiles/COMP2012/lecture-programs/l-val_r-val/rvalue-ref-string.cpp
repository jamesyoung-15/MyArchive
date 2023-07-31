#include <iostream>     /* File: rvalue-ref-string.cpp */
using namespace std;

string wrap(string s) { return "begin." + s + ".end";  }

int main()
{
    /* rvalue reference with user-defined objects */
    string s1 {"w"};
    string&& s2;        // Error: rvalue ref must be initialized
    string&& s3 = s1;   // Error: rvalue ref can't bind to lvalue

    string&& s4 = "x"; cout << s4 << endl;
    string&& s5 = wrap("x"); cout << s5 << endl;

    s4 = "z";           // s4 used as lvalue
    cout << s4 << endl; // s4 used as rvalue
    s5 = s1;            // s5 used as lvalue
    cout << s5 << endl; // s4 used as rvalue
    return 0;
}
