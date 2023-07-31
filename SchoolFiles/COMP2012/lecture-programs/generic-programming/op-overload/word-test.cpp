#include <iostream>     /* File: word-test.cpp */
using namespace std;
#include "word.h"

int main()
{
    Word ship("Titanic");      // Which constructor?
    Word movie(ship);          // Which constructor?
    Word song("My heart will go on"); // Which constructor?

    song = song;               // Call assignment operator
    song = movie;              // Call assignment operator
}
