class Word              /* File: overload-constructor.cpp */
{
  private:
    int frequency;
    char* str; 

  public:
    Word();                         // Default constructor
    Word(const char* s, int k = 1); // Conversion constructor
    Word(const Word& w);            // Copy constructor
};
