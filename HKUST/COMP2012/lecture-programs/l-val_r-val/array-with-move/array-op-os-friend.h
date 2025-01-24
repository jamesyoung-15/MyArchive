template <typename T>   /* File: array-op-os-friend.h */
ostream& operator<<(ostream& os, const Array<T>& a)
{
    os << "#elements stored = " << a._size << endl;

    for (int i = 0; i < a._size; ++i)
        os << a._value[i] << endl;

    return os;
}
