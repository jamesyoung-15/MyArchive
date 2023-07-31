#include <iostream>     /* File: btree.h */
using namespace std;

template <class T> class BTnode
{
  public:
    BTnode(const T& x, BTnode* L = nullptr, BTnode* R = nullptr)
      : data(x), left(L), right(R) { } 

    ~BTnode() 
    {
        delete left;
        delete right;
        cout << "delete the node with data = " << data << endl;
    }

    const T& get_data() const { return data; }
    BTnode* get_left()  const { return left; }
    BTnode* get_right() const { return right; }
    
  private:
    T data;             // Stored information
    BTnode* left;       // Left child
    BTnode* right;      // Right child
};
