#include <iostream>
using namespace std;
#include "mil-word.h"
#include "mil-word-pair.h"

int main() 
{
    Word movie("Titanic");
    Word director = "James Cameron";
    Word ship = movie;
    Word cartoon(movie);

    movie.print();
    director.print();
    ship.print();
    cartoon.print();

    Word_Pair wp("brian", "mak");
    wp.print();
}
