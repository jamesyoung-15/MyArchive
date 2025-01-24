template <typename T>   /* File: array-constructors.h */
Array<T>::Array(int n) : _value( new T [n] ), _size(n) { }

template <typename T> Array<T>::Array(const Array<T>& a)
    : _size(a._size), _value(new T [a._size])
{
    for (int i = 0; i < _size; ++i) _value[i] = a._value[i];
}

template <typename T> 
Array<T>::Array(Array<T>&& a) : _size(a._size), _value(a._value)
{
    a._size = 0; a._value = nullptr;
}

template <typename T> Array<T>::~Array() { delete [] _value; }

template <typename T> void Array<T>::init(const T& k)
{
    for (int i = 0; i < _size; ++i) _value[i] = k;
}
