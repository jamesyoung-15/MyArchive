#include<iostream>
using namespace std;

class practice
{
    private:
        int num;
    public:
        practice(){cout<<"hi"<<endl;};
        practice(int num) {this->num =num;};
        practice(const practice &a){cout<<"copy"<<endl;};
        int get_num () const {return num;};
        
};

int main()
{
    practice p{10};
    practice c;
    practice j = c;
    printf("%d\n", p.get_num());
    return 0;
}
