template <typename T>   /* File: list.cpp */
List<T>::List() : head(0), tail(0) { }

template <typename T>
void List<T>::append(const T& item)
{
    List_Node<T>* new_node = new List_Node<T>(item);
    if (!tail)
        head = tail = new_node;
    else
        ; // ...
}
