#include <iostream>     /* File: final-class-error.cpp */
using namespace std;

class A {};
class B: public A {};
class C final: public B {};
class D: public B {};
class E: public C {};

int main()
{
    A a; B b; C c; D d; E e;
    return 0;
}
