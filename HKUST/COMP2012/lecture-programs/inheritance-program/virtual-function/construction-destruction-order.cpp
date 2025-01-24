#include <iostream>     /* File: construction-destruction-order.cpp */
using namespace std;

class Base 
{
  public: 
    Base() { cout << "Base's constructor\n"; }
    ~Base() { cout << "Base's destructor\n"; }
};

class Derived : public Base 
{
  public: 
    Derived() { cout << "Derived's constructor\n"; }
    ~Derived() { cout << "Derived's destructor\n"; }
};

int main() 
{ 
    Base* p = new Derived; 
    delete p; 
}
