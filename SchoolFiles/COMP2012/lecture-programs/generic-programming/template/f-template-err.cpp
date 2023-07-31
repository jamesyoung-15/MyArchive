#include <iostream>     /* File: f-template-err.cpp */
using namespace std;
template <class T> T* create() { return new T; };
template <class T> void f() { T a; cout << a << endl; }
int main() { create(); f(); }
