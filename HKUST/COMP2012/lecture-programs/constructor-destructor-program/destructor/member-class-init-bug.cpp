#include <iostream.h>

class Word 
{
    int frequency;
    char* str;

    set(const char* s) { str = new char [strlen(s)+1]; strcpy(str, s); }

  public:
    Word() {};
    Word(const char* s, int k = 1) : frequency(k) { set(s); }
    Word(const Word& w) : frequency(w.frequency) { set(w.str); }
    ~Word() { delete [] str; }

    void address(ostream& os) { os << (void*)str << endl; }
    friend ostream& operator<<(ostream& os, const Word& w)
        { return os << w.str << endl; }
};

class Word_Pair
{
  public:
    Word word1;
    Word word2;
    
    Word_Pair(const char* x, const char* y)
        { word1 = x; word2 = y; }
};

int main()
{
    Word_Pair x("brian", "mak");
    cout << x.word1;    // -> mak
    cout << x.word2;    // -> mak
    x.word1.address(cout); // -> 0x418c8
    x.word2.address(cout); // -> 0x418c8
}
