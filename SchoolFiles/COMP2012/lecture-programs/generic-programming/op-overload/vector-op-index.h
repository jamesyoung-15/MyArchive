#include <iostream>     /* File: vector-op-index.h */
using namespace std;
class Vector {
  public:
    Vector(double a = 0, double b = 0) : x(a), y(b) { }
    double operator[](int) const; // Read-only; c.f. getx() and gety()
    double& operator[](int);      // Allow read and write
  private:
    double x, y;
};
double Vector::operator[](int j) const {
    switch (j) {
        case 0: return x;
        case 1: return y;
        default: cerr << "op[] const: invalid dimension!\n"; } }

double& Vector::operator[](int j) {
    switch (j) {
        case 0: return x;
        case 1: return y;
        default: cerr << "op[]: invalid dimension!\n"; } }
