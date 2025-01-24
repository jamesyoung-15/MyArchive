#include <iostream>     /* File: test-bst.cpp */
using namespace std;
#include "bst.h"
#include "bst-contains.cpp"
#include "bst-print.cpp"
#include "bst-find-max.cpp"
#include "bst-find-min.cpp"
#include "bst-insert.cpp"
#include "bst-remove.cpp"

int main()
{
    BST<int> bst;
    while (true)
    {
        char choice; int value;
        cout << "Action: d/f/i/m/M/p/q/r/s "
             << "(deep-cp/find/insert/min/Max/print/quit/remove/shallow-cp): ";
        cin >> choice;

        switch (choice)
        {
            case 'd': // Deep copy
            {
                BST<int>* bst2 = new BST<int>(bst);
                bst2->print(); delete bst2;
            }
                break;
            case 'f': // Find a value
                cout << "Value to find: "; cin >> value;
                cout << boolalpha << bst.contains(value) << endl;
                break;
            case 'i': // Insert a value
                cout << "Value to insert: "; cin >> value;
                bst.insert(value);
                break;
            case 'm': // Find the minimum value
                if (bst.is_empty()) 
                    cerr << "Can't search an empty tree!" << endl;
                else
                    cout << bst.find_min() << endl; 
                break;
            case 'M': // Find the maximum value
                if (bst.is_empty()) 
                    cerr << "Can't search an empty tree!" << endl;
                else
                    cout << bst.find_max() << endl; 
                break;
            case 'p': // Print the whole tree
            default:
                cout << endl; bst.print(); 
                break;
            case 'q': // Quit
                return 0; 
            case 'r':
                cout << "Value to remove: "; cin >> value;
                bst.remove(value); 
                break;
            case 's': // Shallow copy
            {
                BST<int> bst3 { std::move(bst) };
                bst3.print();
                bst.print();
            }
                break;
        }
    }
}
