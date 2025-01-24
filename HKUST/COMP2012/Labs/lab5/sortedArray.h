#ifndef _SORTED_ARRAY_H  /* File: sortedArray.h */
#define _SORTED_ARRAY_H

// Class Tempalte with a type parameter, T,
// and two non-type parameters, namely, MAX_SIZE and ASCENDING 
template <typename T, int MAX_SIZE = 10, bool ASCENDING = true>
class SortedArray {
  public:
    /* Constructors */
    // Default constructor
    SortedArray();
    // Copy constructor
    SortedArray(const SortedArray& other) = default;
    // Conversion constructor
    SortedArray(int x);
    // Another constructor 
    SortedArray(const T arr[], int n);

    /* Accessors */
    // Checks whether the array is full or not
    bool full() const;
    // Checks whether the array is empty or not
    bool empty() const; 
    // Returns the number of elements
    int size() const;
    // Returns the maximum possible number of elements
    int max_size() const;

    /* Mutators */
    // Inserts an element in the appropriate position
    void insert(const T& value);

    /* Operators */
    // subscription operator: to return an element at the given index
    T operator[](int index) const;
    // equal-to operator: to compare two SortedArray objects
    bool operator==(const SortedArray& other) const;

  private:
    T data[MAX_SIZE];
    int num_elements;
};

// Default constructor: constructs an empty SortedArray
template <class T, int MAX_SIZE, bool ASCENDING>
SortedArray<T, MAX_SIZE, ASCENDING>::SortedArray() { 
    num_elements = 0; 
}

// Conversion constructor: constructs a SortedArray with 1 element
template <class T, int MAX_SIZE, bool ASCENDING>
SortedArray<T, MAX_SIZE, ASCENDING>::SortedArray(int x): SortedArray<T, MAX_SIZE, ASCENDING>() {
    insert(x); 
}

// Another constructor: constructs a SortedArray 
// by adding each element from the given array
template <class T, int MAX_SIZE, bool ASCENDING>
SortedArray<T, MAX_SIZE, ASCENDING>::SortedArray(const T arr[], int n): SortedArray<T, MAX_SIZE, ASCENDING>() {
    if (n <= MAX_SIZE) {
        for (int i=0; i<n; i++) {
            insert(arr[i]);
        }
    } 
}

// Checks whether the array is full or not
template <class T, int MAX_SIZE, bool ASCENDING>
bool SortedArray<T, MAX_SIZE, ASCENDING>::full() const { 
    if (num_elements == MAX_SIZE)
        return true; 
    return false;
}

// Checks whether the array is empty or not
template <class T, int MAX_SIZE, bool ASCENDING>
bool SortedArray<T, MAX_SIZE, ASCENDING>::empty() const {
    if (num_elements == 0) 
        return true;
    return false;
}

// Returns the number of elements
template <class T, int MAX_SIZE, bool ASCENDING>
int SortedArray<T, MAX_SIZE, ASCENDING>::size() const { 
    return num_elements; 
}

// Returns the maximum possible number of elements
template <class T, int MAX_SIZE, bool ASCENDING>
int SortedArray<T, MAX_SIZE, ASCENDING>::max_size() const { 
    return MAX_SIZE; 
}

// Inserts an element in the appropriate position
template <class T, int MAX_SIZE, bool ASCENDING>
void SortedArray<T, MAX_SIZE, ASCENDING>::insert(const T& value) { 
    if (!full()) {
        int p = num_elements - 1;
        if (ASCENDING) {
            while (p >= 0 && value < data[p]) {
                data[p + 1] = data[p];
                p--;
            }
            data[p + 1] = value;
        } else {
            while (p >= 0 && value > data[p]) {
                data[p + 1] = data[p];
                p--;
            }
            data[p + 1] = value;
        }
        num_elements++;
    }
} 

// Global output operator
template <class T, int MAX_SIZE, bool ASCENDING>
ostream& operator<<(ostream& os, const SortedArray<T, MAX_SIZE, ASCENDING>& a) {
    if (!a.empty()) {
        int i = 0;
        os << "{";
        for (; i < (a.size() - 1); ++i) 
            os << a[i] << ", ";
        os << a[i] << "}";
    }
    return os;
}


/*** DO NOT MODIFY THE CODE ABOVE ***/
/*** ADD YOUR CODE BELOW ***/


// TODO #1: Implement the Subscription Operator []
// subscription operator: to return an element at the given index
// op[]: for read only
template <class T, int MAX_SIZE, bool ASCENDING>
T SortedArray<T, MAX_SIZE, ASCENDING>::operator[](int index) const
{
    return data[index];
}

// TODO #2: Implement the Equal-To Operator ==
// equal-to operator: to compare two SortedArray objects
template <class T, int MAX_SIZE, bool ASCENDING>
bool SortedArray<T, MAX_SIZE, ASCENDING>::operator==(const SortedArray& other) const
{
    // if both empty
    if(other.empty() && this->empty())
        return true;

    // if both different size
    if(other.size()!=this->size())
        return false;

    // compare elements, return false if one element not equal to each other
    for(int i=0;i<this->size();i++)
    {
        if(this->data[i]!=other.data[i])
        {
            return false;
        }
    }
    
    // else return true
    return true;
}


// TODO #3: Implement the Global Addition Operator +
// Global addition operator, op+
template <class T, int MAX_SIZE, bool ASCENDING>
SortedArray<T,MAX_SIZE,ASCENDING> operator+(const SortedArray<T,MAX_SIZE,ASCENDING> &a,const SortedArray<T,MAX_SIZE,ASCENDING> &b)
{
    //create sorted array c
    SortedArray<T,MAX_SIZE,ASCENDING> c;
    // copy elements a to c
    for(int i = 0; i<a.size();i++)
    {
        c.insert(a[i]);
    }    
    int j = 0; // track index for array b
    int cur_size = c.size(); // size of c after adding a
    // copy elements b to c by ascending
    for(int i=0;i<MAX_SIZE;i++)
    {
        // if c array is not full and have leftover elements of b not added to c
        if(i>c.size() && j<MAX_SIZE-cur_size && j<b.size())
        {
            c.insert(b[j]);
            j++;
        }
        // insert elements of b if they are smaller than c[i]
        else if(j<MAX_SIZE-cur_size && j<b.size())
        {
            if(b[j]<c[i])
            {
                c.insert(b[j]);
                j++;
            }
        }
    }
    return c;

}


#endif
