#ifndef LISTNODE_H      /* File: listnode.h */
#define LISTNODE_H

template <typename T> 
class List_Node
{
  public:
    List_Node(const T& x) : data(x) { }

    List_Node* next {nullptr};
    List_Node* prev {nullptr};
    T data;
};

#endif
