#include <iostream>     /* File: mil-const-ref.cpp */
using namespace std;
int a = 5;

class Example
{
	const int const_m = 3;
	int& ref_m = a;
  public:
	Example() { }
	Example(int c, int& r) : const_m(c), ref_m(r) { }
	void print() const { cout << const_m << "\t" << ref_m << endl; }
};

int main()
{
	Example x; x.print();
	int b = 55; Example y(10, b); y.print();
}
