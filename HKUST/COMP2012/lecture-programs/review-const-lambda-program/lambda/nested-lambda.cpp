#include <iostream>     /* File : nested-lambda.cpp */
using namespace std;	

int main()	
{
    int a = 1, b = 1, c = 1;

    auto f = [a, &b, &c]() mutable
    {
        auto g = [a, b, &c]() mutable      // Nested lambda
        {
            cout << a << b << c << endl;
            a = b = c = 4;
        };

        a = b = c = 3; g();
    };

    a = b = c = 2; f();
    cout << a << b << c << endl;
    return 0;
}

