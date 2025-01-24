class Word  /* File: default-copy-constructor.cpp */
{
  private: ...
  public: Word(const char* s, int k = 0) { ... }; 
};
int main()
{
    Word movie {"Titanic"};  // which constructor?
    Word song {movie};       // which constructor?
    Word song = movie;       // which constructor?
}
