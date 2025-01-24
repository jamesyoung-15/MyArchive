#include <iostream>     /* file: default-member-init.cpp */
using namespace std;

class A
{
    int a;
  public:
    A(int z) : a(z) { cout << "call A's constructor: " << a << endl; }
    ~A() { cout << "call A's destructor: " << a << endl; }
    int get() const { return a; }
};

class B
{
    int b1 = 999;       // Remember: can't initialize by ( )
    A b2 = 10;          // Call A's conversion constructor
    A b3 {100};         // Call A's conversion constructor
  public:
    B() { cout << "call B's default constructor" << endl << endl; }
    ~B() { cout << "call B's destructor: " << b1 << "\t"
                << b2.get() << "\t" << b3.get() << endl; }
};

int main() { B x; return 0; }
