#include <iostream>
using namespace std;

template <class T> class Bnode
{
    private:
        T data;
        Bnode* left;
        Bnode* right;

    public:
        Bnode(const T& x, Bnode* l = nullptr, Bnode* r = nullptr):data(x),left(l),right(r){}
        ~Bnode()
        {
            cout << "delete node with data: " << data << endl;
            delete left;
            delete right;
        }
        
};


int main()
{
    return 0;
}