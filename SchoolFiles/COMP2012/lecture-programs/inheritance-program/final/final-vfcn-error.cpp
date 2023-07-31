#include <iostream>     /* File: final-vfcn-error.cpp */
using namespace std;

class UPerson { 
  public: /* Other data and functions */
    virtual void print() const { /* incomplete */ }
};

class Student : public UPerson {
  public: /* Other data and functions */
    virtual void print() const override final { /* incomplete */ }
};

class PG_Student : public Student {
  public: /* Other data and functions */
    virtual void print() const override { /* incomplete */ }
};

int main() { PG_Student jane("Jane", CSE, 4.0); jane.print(); }
