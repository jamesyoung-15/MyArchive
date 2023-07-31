#include "word.h"       /* File: temp-word.cpp */
//void print_word(const Word& w) { cout << "print const Word&: "; w.print(); }
void print_word(Word&& w) { cout << "print Word&&: "; w.print(); }

int main()
{
    /* Use const Word& to hold a temporary Word object */
    Word song("imagine"); cout << endl;
    const Word& w1 = song.to_upper_case(); cout << endl;
    song.print(); w1.print(); cout << "\n**********" << endl;

    /* Use Word&& to hold a temporary Word object */
    Word movie("batman", 2); cout << endl;
    Word&& w2 = movie.to_upper_case(); cout << endl;
    movie.print(); w2.print(); cout << endl;

    print_word(song); print_word(movie);
    print_word(w1); print_word(w2); cout << "\n**********" << endl;
    
    /* Directly pass a temporary Word object to a function */
    print_word(movie.to_upper_case()); cout << endl;
    print_word("Beatles"); cout << "\n**********" << endl; return 0;
} /* g++ -std=c++11 -fno-elide-constructors temp-word.cpp */
