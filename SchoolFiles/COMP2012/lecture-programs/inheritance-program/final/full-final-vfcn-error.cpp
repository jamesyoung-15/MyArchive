#include <iostream>     /* File: final-vfcn-error.cpp */
using namespace std;
#include "v-student2.h"
#include "v-pg-student.h"

int main()
{
    Student tom("Tom", CIVL, 3.0);
    tom.print();
    PG_Student jane("Jane", CSE, 4.0);
    jane.print();
    return 0;
}
