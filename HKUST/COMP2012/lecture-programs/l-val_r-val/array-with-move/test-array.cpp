#include <iostream>     /* File: array-test.cpp */
using namespace std;
#include "array.h"
#include "array-constructors.h"
#include "array-op=.h"
#include "array-op-os.h"

int main() 
{
    Array<int> a(3); a.init(98); cout << a << endl;
    a = a; a[2] = 17; cout << a << endl;

    Array<char> b(4);
    b.init('g'); b[0] = a[1]; cout << b << endl;

    const Array<char> c = b;
    // c[2] = 5; // Error: assignment of read-only location
    cout << c << endl;

    Array<int> d(std::move(a));
    cout << d << endl;
    cout << "a after move: " << a << endl;
    return 0;
}

