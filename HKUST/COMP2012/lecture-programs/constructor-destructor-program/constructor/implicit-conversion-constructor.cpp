#include <cstring>    /* File: implicit-conversion-constructor.cpp */
class Word
{ 
  private: int frequency; char* str;
  public:
    Word(char c)
        { frequency = 1; str = new char[2]; str[0] = c; str[1] = '\0'; }
    Word(const char* s) // Assumption: s != nullptr
        { frequency = 1; str = new char [strlen(s)+1]; strcpy(str, s); }
};

int main() 
{
    Word movie("Titanic");              // Explicit conversion
    Word movie2 {'A'};                  // Explicit conversion
    Word movie3 = 'B';                  // Implicit conversion
    Word director = "James Cameron";    // Implicit conversion
}
