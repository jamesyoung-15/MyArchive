#include <iostream>
#include "string.h"
using namespace std;


class A{
    private:
        int size;
        char* data;
    public:
        A(): size(0){
            data = nullptr; 
            cout<<"default"<<endl;
        }
        ~A(){
            cout<<"destructor"<<endl; 
            delete[] data;
        }
        A(const char* d){
            size = strlen(d); 
            data = new char[size]; 
            memcpy(data, d,size); 
            cout<<"conversion"<<endl;
        }
        A(const A& a){
            size = a.size;
            data = new char[size]; 
            memcpy(data, a.data,size); 
            cout<<"copy"<<endl;
        }
        A(A&& a){
            data = a.data; 
            size = a.size; 
            a.data = nullptr; 
            a.size = 0; 
            cout<<"move"<<endl;
        }
        A& operator=(A&&a){
            if(this!=&a){
                delete [] data; 
                data = a.data; 
                size = a.size; 
                
                a.data = nullptr; 
                a.size = 0;
            } 
            return *this;
        }
        void print() const {
            cout<< data << endl;
        }
};


int main()
{
    A a;
    A b = "hello";

    A c = std::move(b);
    A d = a;

    c.print();

    int && j = 5;
    

    
    

    return 0;
}
