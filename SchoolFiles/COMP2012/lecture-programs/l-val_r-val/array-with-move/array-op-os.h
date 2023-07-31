template <typename T>   /* File: array-op-os.h */
ostream& operator<<(ostream& os, const Array<T>& a)
{
    os << "#elements stored = " << a.size() << endl;

    for (int j = 0; j < a.size(); ++j)
        os << a[j] << endl;

    return os;
}
