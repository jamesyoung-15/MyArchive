#include <cstring>    /* File: explicit-conversion-constructor.cpp */
class Word
{
  private:
    int frequency; char* str;
  public:
    explicit Word(const char* s)
        { frequency = 1; str = new char [strlen(s)+1]; strcpy(str,s); }
};

int main() 
{
    Word *p = new Word("action");    // Explicit conversion
    Word movie("Titanic");           // Explicit conversion
    Word director = "James Cameron"; // Bug: implicit conversion
}
