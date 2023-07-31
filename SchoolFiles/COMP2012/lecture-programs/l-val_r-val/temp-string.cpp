#include <iostream>     /* File: temp-string.cpp */
using namespace std;

void cbv(string x) { cout << "call-by-value: " << x << endl; }
void cbr(string& x) { cout << "call-by-ref: " << x << endl; }
void cbcr(const string& x) { cout << "call-by-const-ref: " << x << endl; }
string complete(string s) { return "begin." + s + ".end";  }

int main()
{
    string a {"Hello"}; cout << endl;
    cbv("Brian");   cout << endl; // Call by value
    cbr(a);         cout << endl; // Call by reference requires lvalue
    cbr("Desmond"); cout << endl; // Error: Call by reference, no conversion
    cbcr("Gary");   cout << endl; // Call by const reference accepts rvalue
    return 0;
}
