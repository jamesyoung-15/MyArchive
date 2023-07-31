/* File: name-conflict.h */
void print(int x, int y) { cout << x << " , " << y << endl; }

class B
{
  private:
    int x, y;
  public:
    B(int p = 1, int q = 2) : x(p), y(q)
        { cout << "Base class constructor: "; print(x, y); }
    void f() const { cout << "Base class: "; print(x, y); } 
};

class D : public B 
{ 
  private: 
    float x, y;
  public:
    D() : x(10.2), y(20.6) { cout << "Derived class constructor\n"; }
    void f() const { cout << "Derived class: "; print(x, y); B::f(); }
};
