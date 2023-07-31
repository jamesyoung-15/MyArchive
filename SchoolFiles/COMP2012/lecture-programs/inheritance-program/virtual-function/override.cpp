#include <iostream>     /* File: override.cpp */
using namespace std;

class Base
{
  public:
    virtual void f(int a) const { cout << a << endl; }
};

class Derived: public Base
{
    int x {25};
  public:
    void f(int) const override;
};
    
// Don't repeat the keyword override here
void Derived::f(int b) const { cout << x+b << endl; } 

int main() { Derived d; Base& b = d; b.f(5); return 0; }
