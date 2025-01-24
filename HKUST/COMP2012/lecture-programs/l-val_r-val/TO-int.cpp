#include <iostream>     /* File: TO-int.cpp */
using namespace std;

int square(int x) { return x*x; }
void cbv(int x) { cout << "call-by-value: " << x << endl; }
void cbr(int& x) { cout << "call-by-ref: " << x << endl; }
void cbcr(const int& x) { cout << "call-by-const-ref: " << x << endl; }

int main()
{
    int a = 3;
    int& b = 4;                // Error! Why?
    const int& c = 5;          // TO1: const ref initialization
    int d = square(3);         // TO3: function returned value
    int e = a + c + d;         // TO4: result of sub-expression
    cbv(a);                    // OK: int x = a
    cbr(a);                    // OK: int& x = a
    cbr(8);                    // Error: int& x = 8
    cbcr(8); return 0;         // TO1: const int& x = 8
}
