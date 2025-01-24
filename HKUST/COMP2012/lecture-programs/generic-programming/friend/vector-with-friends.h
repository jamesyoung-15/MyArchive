#include <iostream>     /* File: vector-with-friends.h */
using namespace std;

class Vector 
{
    friend ostream& operator<<(ostream& os, const Vector& a);
    friend Vector operator+(const Vector& a, const Vector& b);

  public:
    Vector(double a = 0, double b = 0) : x(a), y(b) { }

  private:
    double x, y;
};

ostream& operator<<(ostream& os, const Vector& a)
    { return (os << '('  << a.x << " , " << a.y << ')'); }
    
Vector operator+(const Vector& a, const Vector& b)
    { return Vector(a.x + b.x, a.y + b.y); }

