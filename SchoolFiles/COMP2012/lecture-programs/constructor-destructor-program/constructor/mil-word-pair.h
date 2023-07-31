class Word_Pair         /* File: mil-word-pair.h */
{
  private:
    Word w1; Word w2;
  public:
    Word_Pair(const char* s1, const char* s2) : w1(s1,5), w2(s2) { }
    void print() const
    { 
        cout << "word1 = "; w1.print(); 
        cout << "word2 = "; w2.print();
    }
};
