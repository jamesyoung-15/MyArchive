#include "listnode.h"   /* File: nontype-list.h */
template <typename T, int max_num_items> 
class List
{
  public:
    bool append(const T& item) {
        if (num_items == max_num_items) 
           { cerr << "List is full\n"; return false; }
        else 
           { /* incomplete */ return true; }
    }
    // ... Other member functions

  private:
    int num_items {0};
    List_Node<T>* head {nullptr};
    List_Node<T>* tail {nullptr};
};
