#include <iostream>     /* File: const-object-date.cpp */
using namespace std;
#include "const-object-date.h"

int main()   // There are problems with this code; what are they?
{
    const Date WW2(1945, 9, 2); // World War II ending date
    Date today;
    WW2.print();
    today.print();

    // How long has it been since World War II?
    cout << "Today is " << today.difference(WW2)
         << " days after WW2" << endl;
    
    // What about next month?
    WW2.add_month();    // Error; do you mean today.add_month()??
    cout << today.difference(WW2) << " days by next month.\n";

    return 0;
}
