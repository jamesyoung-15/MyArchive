#include <iostream>     /* File: larger-match-arg.cpp */
using namespace std;
template <typename T> inline const T&
    larger(const T& a, const T& b) { return (a < b) ? b : a; }

int main() 
{
    cout << larger(3, 5) << endl;        // T is int;
    cout << larger(4.3, 5.6) << endl;    // T is double
}
