class Complex
{
  private:
    float real = 1.3;   // Note: not allowed before C++11
    float imag {0.5};   // Use either = or { } initializer
  public:
    ...
};
