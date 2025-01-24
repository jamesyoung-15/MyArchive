#include "vector-op-add.h" /* File: vector-op-add-fix.cpp */
using namespace std;

ostream& operator<<(ostream& os, const Vector& a)
    { return (os << '('  << a.getx() << " , " << a.gety() << ')'); }

Vector operator+(double a, const Vector& b) { return b + a; }
    
int main()
{
    Vector a(1.1, 2.2);
    cout << "scalar + vector: 5 + a = " << 5 + a << endl;
}
