#include <iostream>     /* File: temp-word.h */
#include <cstring> 
using namespace std;

class Word
{
  private:
    int freq; char* str;

  public:
    Word(const char* s) : freq(0), str(new char [strlen(s)+1])
        { cout << "conversion\t"; strcpy(str, s); }
    Word(const Word& w) : freq(w.freq), str(new char [strlen(w.str)+1])
        { cout << "copy\t"; strcpy(str, w.str); }
    ~Word() { delete [] str; }

    Word to_upper_case() const
    {
        Word x(*this);
        for (char* p = x.str; *p != '\0'; p++) *p += 'A' - 'a';
        return (x);
    }
    void print() const { cout << str << " : " << freq << endl; }
};
