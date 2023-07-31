#include <iostream>     /* File: name-conflict.cpp */
using namespace std;
#include "name-conflict.h"

void smart(const B* p) { cout << "Inside smart(): "; p->f(); } 

int main()
{
    B base(5, 6); cout << endl; 
    D derive; cout << endl;

    B* bp = &base; bp->f(); cout << endl;
    D* dp = &derive; dp->f(); cout << endl;

    bp = &derive; bp->f(); cout << endl;

    cout << "Call smart(bp): "; smart(bp);
    cout << "Call smart(dp): "; smart(dp);
    return 0;
}
