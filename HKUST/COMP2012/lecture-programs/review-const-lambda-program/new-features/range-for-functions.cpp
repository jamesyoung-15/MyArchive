#include <iostream>     /* File : range-for-functions.cpp */
using namespace std;	

int square(int x) { return x*x; }
int cube(int x) { return x*x*x; }
int twice(int x) { return 2*x; }


int main()	
{
    for (auto f : { twice, square, cube })
        cout << f(4) << endl;
    
    auto g = { twice, square, cube };
    
    for (auto f : g)
        cout << f(5) << endl;
    return 0;
}

