#include <iostream>     /* File: vector-os-nonfriend.h */

class Vector 
{
  public:
    Vector(double a = 0, double b = 0) : x(a), y(b) { }
    double getx() const { return x; }
    double gety() const { return y; }
    ostream& operator<<(ostream& os);

  private:
    double x, y;
};

ostream& Vector::operator<<(ostream& os)
{
    return (os << '('  << x << " , " << y << ')');
}
