#include <iostream>     /* File: default-assign-problem2.cpp */
#include <cstring> 
using namespace std;
class Word
{  
  private: int frequency; char* str;
    void set(int f, const char* s)
        { frequency = f; str = new char [strlen(s)+1]; strcpy(str, s); }
  public:
    Word(const char* s, int k = 1)
        { set(k, s); cout << "\nImplicit const char* conversion\n"; }
    Word(const Word& w) { set(w.frequency, w.str); cout << "\nCopy\n"; }

    void print() const  // Also prints the address of object's str array
        { cout << str << " : " << frequency << " ; "
               << reinterpret_cast<void*>(str) << endl; }
};

int main()
{ 
    Word x("rat");    x.print(); // Conversion constructor
    Word y = x;       y.print(); // Copy constructor
    Word z("cat", 2); z.print(); // Conversion constructor
    z = x;            z.print(); // Default assignment operator
}
