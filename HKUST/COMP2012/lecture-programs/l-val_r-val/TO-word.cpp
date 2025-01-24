#include "word.h"       /* File: TO-word.cpp */

void print_word(const Word& x)
{
    cout << "<<<\n"; x.print(); cout << ">>>\n";
}

int main()
{ 
    const Word& w1 = "batman";    // TO1: const ref initialization
    w1.print();
    print_word("superman");       // TO2: argument passing

    Word w2 = w1.to_upper_case(); // TO3: function returned value
    w2.print(); 
    ((w1 + " or ") + w2).print();   // TO4: result of sub-expression

    cout << "\n*** It's all destructions now ***" << endl;
    return 0;
} /* g++ -std=c++11 -fno-elide-constructors TO-word.cpp */
