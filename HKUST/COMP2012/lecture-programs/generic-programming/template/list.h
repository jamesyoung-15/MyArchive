#ifndef LIST_H          /* File: list.h */
#define LIST_H

#include "listnode.h"
template <typename T> class List
{
  public:
    List() = default;
    void append(const T& item) {
        List_Node<T>* new_node = new List_Node<T>(item);
        if (!tail)
            head = tail = new_node;
        else
        { /* incomplete */ }
    }
    void print() const {
        for (const List_Node<T>* p = head; p; p = p->next)
            cout << p->data << endl;
    }
    // ... Other member functions
  private:
    List_Node<T>* head {nullptr};
    List_Node<T>* tail {nullptr};
};
#endif
