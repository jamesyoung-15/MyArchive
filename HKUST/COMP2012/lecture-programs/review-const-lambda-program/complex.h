class Complex           /* File: complex.h */
{
  private:
    float real; float imag;

  public:
    Complex(float r, float i) { real = r; imag = i; }
    void print() const { cout << "(" << real << " , " << imag << ")" << endl; }

    Complex add1(const Complex& x)  // Return by value
    {
        real += x.real; imag += x.imag;
        return (*this);
    }
    Complex* add2(const Complex& x) // Return by value using pointer
    {
        real += x.real; imag += x.imag;
        return this;
    }
    Complex& add3(const Complex& x) // Return by reference
    {
        real += x.real; imag += x.imag;
        return (*this);
    }
};
