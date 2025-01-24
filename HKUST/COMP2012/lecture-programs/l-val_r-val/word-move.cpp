#include "word-move.h"     /* File: "word-move.cpp" */

void print_word(const Word& w) { cout << "print const Word&: "; w.print(); }
void print_word(Word&& w) { cout << "print Word&&: "; w.print(); }

int main()
{
    cout << "*** Copy Semantics ***" << endl;
    Word book {"batman"};
    Word movie(book);
    Word song("imagine");
    movie = song;
    print_word(book); cout << endl;

    cout << "*** Move Semantics ***" << endl;
    Word novel {"outliers"}; cout << endl;
    Word novel2 = novel.to_upper_case();    // move constructions
    cout << endl; novel.print(); novel2.print(); cout << endl;

    Word band = "Beatles"; cout << endl;    // move construction
    band = "Eagles"; cout << endl;          // move assignment

    cout << "*** It's all destructions now ***" << endl;
    return 0;
} /* g++ -std=c++11 -fno-elide-constructors word-move.cpp */
