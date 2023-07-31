template <typename T> /* File: listnode.cpp */
List_Node<T>::List_Node(const T& x)
        : data(data), next(0), prev(0) { }

template <typename T>
List_Node<T>* List_Node<T>::nextnode() { return next; }
