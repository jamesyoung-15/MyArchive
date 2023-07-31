#include <iostream>     /* File : range-for.cpp */
using namespace std;	

int main()	
{
    cout << "Square some numbers in a list" << endl;
    for (int k : {0, 1, 2, 3, 4})
        cout << k*k << endl;

    int range[] { 2, 5, 27, 40 };
         
    cout << "Square the numbers in range" << endl;
    for (int k : range)  // Won't change the numbers in range
        cout << k*k << endl;
    
    cout << "Print the numbers in range" << endl;
    for (int v : range) cout << v << endl;

    for (int& x : range) // Double the numbers in range in situ
        x *= 2;
    
    cout << "Again print the numbers in range" << endl;
    for (int v : range) cout << v << endl;
    return 0;
}

