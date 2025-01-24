#include <iostream>     /* File: bad-friend.cpp */
using namespace std;

#include "v-student.h"
#include "hacker.h"

int main()
{
    Student freshman("Naive", CIVL, 4.0);
    Hacker cool_guy("$#%&");

    freshman.print();
    freshman.add_course("COMP2012");
    freshman.print();

    cool_guy.add_course(freshman);
    freshman.print();
    return 0;
} 
