#include <iostream>
#include <ostream>
using namespace std;

class Vector
{
    private:
        double x, y;

    public:
        Vector(double x=0, double y=0): x(x), y(y){}

        void print() const {cout<<x<<" "<<y << endl;}
        double getx() const {return x;}
        double gety() const {return y;}
        
};

ostream& operator<<(ostream& os,const Vector &a)
{
    return (os << a.getx() << a.gety() <<endl);
}


int main()
{
    Vector a(2,2);
    Vector b(3,3);
    cout<< a;
    return 0;
}
