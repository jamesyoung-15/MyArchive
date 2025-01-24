class Word              /* File: mil-const-member.h */
{
  private:
    const char lang; int freq; char* str;

  public:
    Word() : lang('E'), freq(0), str(nullptr) { };

    Word(const char* s, int f, char g) : lang(g), freq(f)
        { str = new char [strlen(s)+1]; strcpy(str, s); }

    void print() const
        { cout << str << " : " << freq << endl; }
};
