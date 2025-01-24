#include <iostream>     /* File: word-move.h */
#include <cstring> 
using namespace std;

class Word
{
  private:
    int freq = 0; char* str = nullptr;
  public:
    Word() { cout << "default constructor" << endl; }
    Word(const char* s, int f = 1) : freq(f), str(new char [strlen(s)+1])
        { strcpy(str, s); cout << "conversion: "; print(); }
    Word(const Word& w) : freq(w.freq), str(new char [strlen(w.str)+1])
        { strcpy(str, w.str); cout << "copy: "; print(); }
    Word(Word&& w) : freq(w.freq), str(w.str)    // Move constructor
        { w.freq = 0; w.str = nullptr; cout << "move: "; print(); }
    ~Word() { cout << "destructor: "; print(); delete [] str; }
    Word to_upper_case() const
    {
        Word x(*this);
        for (char* p = x.str; *p != '\0'; p++) *p += 'A' - 'a';
        return (x);  // If there is no move constructor, RBV is done by copying,
                     // Now is done by move!
    }                // (Actually another requirement is that x is not global)

    void print() const
        { cout << (str ? str : "null") << " ; " << freq << endl; }
    
    Word& operator=(const Word& w) { // Copy assignment
        if (this != &w) {            // No assignment for the same Word
            delete [] str;
            str = new char [strlen(w.str)+1];
            freq = w.freq; strcpy(str, w.str);
            cout << "copy assignment: "; print();
        }
        return *this;
    }

    Word& operator=(Word&& w) {   // Move assignment
        if (this != &w) {         // No assignment for the same Word
            delete [] str;
            freq = w.freq; str = w.str;
            w.freq = 0; w.str = nullptr;
            cout << "move assignment: "; print();
        }
	    return *this;
    }
};
