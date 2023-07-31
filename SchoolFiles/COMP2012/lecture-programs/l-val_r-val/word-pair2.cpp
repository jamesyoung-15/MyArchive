#include "word-pair.h"     /* File: "word-pair2.cpp" */

int main()
{
    cout << "\n*** Print the synonym's info ***" << endl;
    Word_Pair synonym { Word("happy"), Word("delighted") };
    synonym.print(); 
    
    cout << "\n*** Print the const name's info ***" << endl;
    const Word first_name { "Albert" };
    const Word last_name { "Einstein" };
    Word_Pair name { first_name, last_name };
    name.print(); 
    
    cout << "\n*** It's all destructions now ***" << endl;
    return 0;
} /* g++ -std=c++11 word-pair2.cpp */ // What is the output?
