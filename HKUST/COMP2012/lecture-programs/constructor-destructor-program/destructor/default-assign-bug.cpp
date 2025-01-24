#include <cstring>      /* File: default-assign-bug.cpp */

class Word 
{ 
  private:
    int frequency; char* str; 

  public:
    Word() : frequency(0), str(nullptr) { }
    Word(const char* s, int k = 0): frequency(k) 
	    { str = new char [strlen(s)+1]; strcpy(str, s); }
    ~Word() { delete [] str; }
};

void Bug(Word& x) { Word bug("bug", 4); x = bug; }

int main() { Word movie {"Titanic"}; Bug(movie); return 0; }
