#include <iostream>     /* File : lambda-capture.cpp */
using namespace std;	
int main()	
{
    int sum = 0, a = 1, b = 2, c = 3;

    for (int k = 0; k < 4; ++k) // Evaluate a quadratic polynomial
        cout << [=](int x) { return a*x*x + b*x + c; } (k) << endl;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;

    for (int k = 0; k < 4; ++k) // a and b are used as accumulators
        cout << [&](int x) { a += x*x; return b += x; } (k) << endl;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;

    for (int v : { 2, 5, 7, 10 }) // Only variable sum is captured
        cout << [&sum](int x) { return sum += a*x; } (v) << endl; // Error!
    cout << "sum = " << sum << endl;

    return 0;
}

