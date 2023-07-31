#include <iostream>     /* File: const-basic-types.cpp */
#include <cstdlib>      // Needed for calling rand() etc.
using namespace std;

int main()  // To generate 5 random integers in [0, 100] inclusive
{
    const int N = 5;         // Number of integers to generate
    const int MAX_NUM = 100; // Max integer

    // Seed the random number generator by current time
    srand(time(0));

    for (int j = 0; j < N; ++j)
        cout << rand() % (MAX_NUM+1) << endl;

    return 0;
}
