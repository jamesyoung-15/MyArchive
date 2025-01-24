#include <iostream> /* File: name-conflict.cpp */
class B {
  private: int x, y;
  public:
    B( ) : x(1), y(2) { std::cout << "Base class constructor\n"; }
    void f( ) { std::cout << "Base class: " << x << ", " << y << "\n"; }
};

class D : public B { 
  private: float x, y;
  public:
    D( ) : x(10.0), y(20.0) { std::cout << "Derived class constructor\n"; }
    void f( ) { std::cout << "Derived class: " << x << ", " << y << '\t'; B::f( ); }
};

void smart(B* z) { std::cout << "Inside smart( ): "; z->f( ); } 

int main( ) {
    B base; B* b = &base;
    D derive; D* d = &derive;
    base.f( ); derive.f( );
    b = &derive; b->f( );
    smart(b); smart(d);
}
