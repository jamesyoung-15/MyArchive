#include <iostream>     /* File: convert-reference-err.cpp */
using namespace std;
    
int main()
{
    double x = 5.6;
    int& ip = x;
    cout << ip << endl;
    return 0;
}
