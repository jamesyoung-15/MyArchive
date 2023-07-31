template <typename T>   /* File: arrayT.h */
class Array
{
  private:
    int _size; T* _value;

  public:
    Array<T>(int n = 10);   // Default and conversion constructor
    Array<T>(const Array&); // Copy constructor
    Array<T>(Array&&);      // Move constructor
    ~Array<T>();

    int size() const { return _size; }
    void init(const T& k);

    Array<T>& operator=(const Array<T>& a);// Copy assignment operator
    Array<T>& operator=(Array&&);          // Move assignment operator
    T& operator[](int i) { return _value[i]; } // lvalue 
    const T& operator[](int i) const { return _value[i]; } // rvalue
};
