#include<iostream>
using namespace std;

class Base
{
    private:
        string name;

    public:
        Base() = default;
        Base(string name) : name(name){cout<<"constructor \n";};
        ~Base(){cout<< "destructor \n";};

        string get_name() const {cout << name <<endl; return name;};
        virtual void print() const{cout<<name<<endl;};
};


class Derived : public Base
{
    private:
        int age;
    
    public:
        Derived(int age, string name) : Base(name), age(age){cout<<"derived constructor \n";};

        int get_age() const {return age;};
        virtual void print() const{cout<<age<<endl;};
};

int main()
{
    Base *p;
    Derived j(10,"Bob");
    Base a("Ca");
    p = &j;
    p->get_name();
    p->print();
    j.print();
    a.print();
    return 0;
}
