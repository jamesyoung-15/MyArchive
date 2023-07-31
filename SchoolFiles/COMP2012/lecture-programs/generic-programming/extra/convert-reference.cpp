#include <iostream>     /* File: convert-reference.cpp */
using namespace std;
    
int main()
{
    double x = 5.6;
    const int& ip = x;
    cout << ip << endl;
    return 0;
}
