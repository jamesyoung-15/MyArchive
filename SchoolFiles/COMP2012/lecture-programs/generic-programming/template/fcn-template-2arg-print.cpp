#include <iostream>     /* File: fcn-template-2arg-print.cpp */
using namespace std;
    
template <typename T1, typename T2>
void print_larger(const T1& a, const T2& b)
{
    if (a > b)
        cout << a << endl;
    else
        cout << b << endl;
}

int main()
{ 
    print_larger(4, 5.5);
    print_larger(5.5, 4);
    return 0;
}
