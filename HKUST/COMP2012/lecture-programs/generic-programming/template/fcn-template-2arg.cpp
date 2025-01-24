#include <iostream>     /* File: fcn-template-2arg.cpp */
using namespace std;
    
template <typename T1, typename T2> inline const T1&
    larger(const T1& a, const T2& b) { return (a < b) ? b : a; }

int main()
{
    cout << larger(4, 5.5) << endl; // T1 is int, T2 is double
    cout << larger(5.5, 4) << endl; // T1 is double, T2 is int
}
