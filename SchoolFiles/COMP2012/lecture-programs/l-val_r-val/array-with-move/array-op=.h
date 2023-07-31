template <typename T>     /* File: array-op=.h */
Array<T>& Array<T>::operator=(const Array<T>& a) // Deep copy
{
    if (&a != this)       // Avoid self-assignment: e.g., a = a
    {
        delete [] _value; // First remove the old data
        _size = a._size; _value = new T [_size]; // Re-allocate memory 

        for (int j = 0; j <_size; ++j)           // Copy the new data
            _value[j] = a[j];
    }
    return (*this);
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& a) // Shallow copy
{
    if (&a != this)       // Avoid self-assignment: e.g., a = a
    {
        delete [] _value; // First remove the old data
        _size = a._size; _value = a._value; // Move data from temp object
        a._size = 0; a._value = nullptr;    // Reset the temp object
    }
    return (*this);
}
        
