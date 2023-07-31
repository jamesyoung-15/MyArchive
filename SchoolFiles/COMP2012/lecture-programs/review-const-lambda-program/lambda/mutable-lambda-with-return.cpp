#include <iostream>     /* File : mutable-lambda-with-return.cpp */
using namespace std;	

int main()	
{
    float a = 1.6, b = 2.7, c = 3.8;

    // [&, a] means all except a are captured by reference; a by value
    auto f = [&, a](int x) mutable ->int { a *= x; b += x; return c = a+b; };
    
    for (int k = 1; k < 3; ++k)
        cout << "a = " << a << "\tb = " << b << "\tc = " << c
             << "\tf(" << k << ") = " << f(k) << endl;

    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;
    return 0;
}

