#include <iostream>
using namespace std;

class j{};
class z{
    j** z;
};

class A{
    public:
        A(){cout<<"A con\n";}
        ~A(){cout<<"~A\n";}

};

class B{
    A a;
    public:
        B(){cout<<"B con\n";}
        ~B(){cout<<"~B\n";}
};

class C{
    public:
        C(){cout<<"C con\n";}
};

class D:private C{
    public:
        D(){cout<<"D con\n";}
        ~D(){cout<<"~D\n";}
};

class E:private D{
    D b;
    public:
        E(){cout<<"E con\n";}
        ~E(){cout<<"~E\n";}
};

int main ()
{
  E e;
  return 0;
}
