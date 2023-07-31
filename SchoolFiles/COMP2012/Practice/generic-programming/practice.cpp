#include<iostream>
using namespace std;

template<typename T>
class Test{
    private:
        T data;
    public:
        Test(): data(0){};
        Test(T data) : data(data){cout<<data<<endl;};
};


int main()
{
    Test<int> t1;
    Test<double> t2{2.5};
    return 0;
}
