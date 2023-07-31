#include "vector-op-index.h" /* File: vector-op-index-test.cpp */

// Replace getx(), gety() by op[]
ostream& operator<<(ostream& os, const Vector& a) // Which op[]?
{
    return (os << '('  << a[0] << " , " << a[1] << ')');
}
    
int main()
{
    Vector a(1.2, 3.4);
    cout << "Before assignment: " << a << endl;

    a[0] = 5.6; a[1] = 7.8;   // Which op[]? // uses value op
    cout << "After assignment:  " << a << endl;

    a[2] = 9;                 // Which op[]? Error! // uses reference op
    return 0;
}
