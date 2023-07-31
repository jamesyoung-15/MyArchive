#include <iostream>     /* File: name-conflict.cpp */
using namespace std;

void print(int x, int y) { cout << x << " , " << y << '\n'; }

class B
{
  private:
    int x, y;
  public:
    B(int p = 1, int q = 2) : x(p), y(q)
        { cout << "Base class constructor: "; print(x, y); }
    void f() const { cout << "Base class: "; print(x, y); } 
};

class D : public B 
{ 
  private: 
    float x, y;
  public:
    D() : x(10.2), y(20.6) { cout << "Derived class constructor\n"; }
    void f() const { cout << "Derived class: "; print(x, y); B::f(); }
};

void smart(const B* p) { cout << "Inside smart(): "; p->f(); } 

int main()
{
    B base(5, 6); cout << endl; 
    D derive; cout << endl;

    B* bp = &base; bp->f(); cout << endl;
    D* dp = &derive; dp->f(); cout << endl;

    bp = &derive; bp->f(); cout << endl;

    smart(bp); cout << endl; 
    smart(dp); cout << endl;
    return 0;
}
