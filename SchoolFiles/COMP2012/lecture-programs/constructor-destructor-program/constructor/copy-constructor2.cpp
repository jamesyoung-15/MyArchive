#include <iostream>     /* File: copy-constructor2.cpp */
#include <cstring> 
using namespace std;

class Word
{
  private:
    int frequency; char* str;
    void set(int f, const char* s) // Private utility function
        { frequency = f; str = new char [strlen(s)+1]; strcpy(str,s); }
  public:
    Word(const char* s, int k = 1)
        { set(k, s); cout << "conversion\n"; }
    Word(const Word& w) 
        { set(w.frequency, w.str); cout << "copy\n"; }
};
