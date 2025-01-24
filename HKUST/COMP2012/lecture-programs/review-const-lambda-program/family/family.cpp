#include "person.h"     /* File: family.cpp */

int main()
{
    Person arthur("Arthur", 65, nullptr, nullptr, nullptr);
    Person becky("Becky", 63, nullptr, nullptr, nullptr);
    Person claire("Claire", 32, &arthur, &becky, nullptr);
    Person eddy("Eddy", 4, nullptr, &claire, nullptr);

    arthur.have_child(&claire);
    becky.have_child(&claire);
    claire.have_child(&eddy);

    arthur.print_family(); cout << endl;
    becky.print_family();  cout << endl; 
    claire.print_family(); cout << endl; 
    eddy.print_family();   cout << endl; 
    return 0;
}
