#include "word-move.h"  /* File: word-pair.h */
class Word_Pair
{
  private:
    Word w1; Word w2;

  public:
    // Pass by const&, construct by copying
    Word_Pair(const Word& a, const Word& b) : w1(a), w2(b)
        { cout << "-- Copy inputs --\n"; a.print(); b.print(); }

    // Pass by &, construct by moving
    Word_Pair(Word& a, Word& b) : w1(std::move(a)), w2(std::move(b))
        { cout << "-- Move with inputs --\n"; a.print(); b.print(); }

    // Pass by rvalue reference &&, construct by moving
    Word_Pair(Word&& a, Word&& b) : w1(std::move(a)), w2(std::move(b))
        { cout << "-- Another move with inputs --\n"; a.print(); b.print(); }

    void print() const
    { 
        cout << "word1 = "; w1.print(); 
        cout << "word2 = "; w2.print();
    }
};
