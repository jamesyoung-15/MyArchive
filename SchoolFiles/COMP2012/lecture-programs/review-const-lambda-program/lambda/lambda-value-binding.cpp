#include <iostream>     /* File : lambda-value-binding.cpp */
using namespace std;	

int main()	
{
    int a = 1, b = 2, c = 3;
    auto f = [=](int x) { return a*x*x + b*x + c; };
    
    for (int k = 0; k < 4; ++k)
        cout << f(k) << endl;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;

    a = 11, b = 12, c = 13;
    for (int k = 0; k < 4; ++k)
        cout << f(k) << endl; // Will f use the new a, b, c?
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;

    return 0;
}

