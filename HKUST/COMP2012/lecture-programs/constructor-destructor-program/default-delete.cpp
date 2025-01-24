#include <iostream>     /* File: default-delete.cpp */
#include <cstring> 
using namespace std;
class Word
{
  private:
    int frequency {0}; char* str {nullptr};
  public:
    Word() = default; // Still want the simple default constructor
    Word(const Word& w) = delete;  // Words can't be copied
    Word(const char* s, int k) : frequency(k)
        { str = new char [strlen(s)+1]; strcpy(str, s); }
    void print() const
        { cout << ((str == nullptr) ? "not-a-word" : str)
               << " : " << frequency << endl; }
};
int main()
{
    Word x; x.print();
    Word y("good", 3); y.print();
    Word z(y);      // Error: call to deleted constructor of 'Word'
}

