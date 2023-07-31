#include <iostream>     /* File: array-size-by-template.cpp */
using namespace std;

// Here, x is a reference to an array of N objects of type T 
template <typename T, int N>
int f(T (&x) [N]) { return N; }

int main()
{
    int a[] = {10, 11, 12, 13};
    double b[] = {0.0, 0.1, 0.2};
    bool c[] = {true, false};
    
    cout << f(a) << endl;
    cout << f(b) << endl;
    cout << f(c) << endl;
    return 0;
}
