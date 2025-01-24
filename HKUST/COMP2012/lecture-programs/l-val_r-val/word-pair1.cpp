#include "word-pair.h"     /* File: "word-pair1.cpp" */

int main()
{
    cout << "\n*** Print the book's info ***" << endl;
    Word author { "Stephen Hawking" };
    Word title { "Brief History of Time" };
    Word_Pair book { author, title };
    book.print(); 

    cout << "\n*** Print the book2's info ***" << endl;
    Word_Pair book2 { book }; // Really memberwise copy
    book2.print(); 

    cout << "\n*** Print the couple's info ***" << endl;
    Word husband { "Mr. C++" };
    Word wife { "Mrs. C++" };
    Word_Pair couple { std::move(husband), std::move(wife) };
    couple.print(); 
    
    cout << "\n*** It's all destructions now ***" << endl;
    return 0;
} /* g++ -std=c++11 word-pair1.cpp */ // What is the output?
