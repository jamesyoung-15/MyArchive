class Vector {          /* File: vector-op-incr.h */
  public:
    Vector(double a = 0, double b = 0) : x(a), y(b) { }
    double operator[](int) const; // Read-only; c.f. getx() and gety()
    double& operator[](int);      // Allow read and write
    Vector& operator++();         // Pre-increment returns an l-value
    Vector operator++(int);       // Post-increment returns a r-value
  private:
    double x, y;
};

Vector& Vector::operator++() { ++x; ++y; return *this; }

// The dummy must be an int argument. Why is it needed?
Vector Vector::operator++(int)
{
    Vector temp(x,y);
    x++; y++; return temp;
}

/* Plus the operator[] function definitions not shown here */




double Vector::operator[ ](int j) const {
    switch (j) {
        case 0: return x;
        case 1: return y;
        default: std::cerr << "op[] const: invalid dimension!\n"; } }

double& Vector::operator[ ](int j) {
    switch (j) {
        case 0: return x;
        case 1: return y;
        default: std::cerr << "op[]: invalid dimension!\n"; } }
