#include <iostream>
using namespace std;


class A{
  int a;
  public:
    A(int a){
      this->a=a;
      cout<<"const"<<endl;
    }
    void getA(){cout<<a;}
};



int main ()
{
  const int b = 20;
  A a =A(1) ;
  return 0;
}
