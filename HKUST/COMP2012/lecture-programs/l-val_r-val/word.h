#include <iostream>     /* File: word.h */
#include <cstring> 
using namespace std;

class Word
{
  private:
    int freq = 0;
    char* str = nullptr;

  public:
    Word() { cout << "default constructor" << endl; }

    Word(const char* s, int f = 1) : freq(f), str(new char [strlen(s)+1])
        { strcpy(str, s); cout << "conversion: "; print(); }

    Word(const Word& w) : freq(w.freq), str(new char [strlen(w.str)+1])
        { strcpy(str, w.str); cout << "copy: "; print(); }

    ~Word() { cout << "destructor: "; print(); delete [] str; }

    void print() const
        { cout << (str ? str : "null") << " ; " << freq << endl; }

    Word operator+(const Word& w) const
    {
        cout << "\n~~~ " << str << " + " << w.str << " ~~~\n";
        Word x;         // Which constructor?

        x.freq = freq + w.freq;
        x.str = new char [strlen(str) + strlen(w.str) + 1];
        strcpy(x.str, str);
        strcat(x.str, w.str);

        return x;       // How is x returned?
    }

    Word to_upper_case() const
    {
        Word x(*this);  // Which constructor?

        for (char* p = x.str; *p != '\0'; p++)
            *p += 'A' - 'a';

        return x;       // How is x returned?
    }
};
