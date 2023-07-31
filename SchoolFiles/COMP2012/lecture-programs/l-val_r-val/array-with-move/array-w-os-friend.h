template <typename T>   /* File: array-w-os-friend.h */
class Array
{
    template <typename S> 
        friend ostream& operator<<(ostream& os, const Array<S>& x);
  private:
    T* _value; int _size;

  public:
    Array(int n = 10);   // Default and conversion constructor
    Array(const Array&); // Copy constructor
    Array(Array&&);      // Move constructor
    ~Array();

    int size() const { return _size; }
    void init(const T& k);
    Array& operator=(const Array&);      // Copy assignment operator
    Array& operator=(Array&&);           // Move assignment operator
    T& operator[](int i) { return _value[i]; } // lvalue 
    const T& operator[](int i) const { return _value[i]; } // rvalue
};
