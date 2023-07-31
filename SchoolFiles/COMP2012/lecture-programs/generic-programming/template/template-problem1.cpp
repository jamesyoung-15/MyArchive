#include <iostream>     /* File: template-problem.cpp */
using namespace std;

template <typename T> const T&
larger(const T& a, const T& b) { return (a < b) ? b : a; }

int main()
{
    char a[16], b[16];
    cin >> a >> m;

    cout << larger(a, b) << " is better!" << endl;
    return 0;
}

// 1st trial, enter: apple microsoft. What is the result?
// 2nd trial, enter: microsoft apple. What is the result?
