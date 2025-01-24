#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    cout << "Lab 7 Exercise." << endl;
    cout << "Start processing binary search tree 1." << endl;
    cout << "Create the tree with Alice: (60, 2.5)" << endl;
    BinarySearchTree<int, float>* bst1 = new BinarySearchTree<int, float>("Alice", 60, 2.5);

    cout << "Insert Steven: (75, 2.0)" << endl;
    bst1->insert("Steven", 75,2.0);
    cout << "Insert Kevin: (74, 3.0)" << endl;
    bst1->insert("Kevin", 74,3.0);
    cout << "Insert Tom: (55, 1.0)" << endl;
    bst1->insert("Tom", 55,1.0);
    cout << "Insert Desmond: (90, 4.0)" << endl;
    bst1->insert("Desmond", 90,4.0);
    cout << "Insert Cecia: (90, 3.5)" << endl;
    bst1->insert("Cecia", 90,3.5);

    cout << "The size of tree 1 is " << bst1->size() << "." << endl;

    cout << endl;
    std::cout << std::boolalpha;
    cout << "Check if contains (90, 4.0): " << endl;
    bool flag1 = bst1->findByScorePair(90, 4.0);
    cout << "Result: " << flag1 << endl << endl;
    cout << "Check if contains (77, 2.0): " << endl;
    bool flag2 = bst1->findByScorePair(77, 2.0);
    cout << "Result: " << flag2 << endl << endl;
    cout << "Check if contains Kevin: " << endl;
    bool flag3 = bst1->findByName("Kevin");
    cout << "Result: " << flag3 << endl << endl;
    cout << "Check if contains Carl: " << endl;
    bool flag4 = bst1->findByName("Carl");
    cout << "Result: " << flag4 << endl << endl;

    cout << "End processing binary search tree 1." << endl << endl;
    cout << "Start processing binary search tree 2." << endl;
    cout << "Create the tree by copying tree 1." << endl;

    BinarySearchTree<int, float>* bst2 = new BinarySearchTree<int, float>(*bst1);
    cout << "Try to insert Darwin: (75, 2.0)" << endl;
    bst2->insert("Darwin", 75,2.0);
    cout << endl;
    cout << "Try to insert Tom: (85, 1.5)" << endl;
    bst2->insert("Tom", 85,1.5);
    cout << endl;
    cout << "Try to insert Grace: (70, 1.5)" << endl;
    bst2->insert("Grace", 70,1.5);
    cout << endl;
    cout << "The size of tree 2 is " << bst2->size() << "." << endl;

    cout << endl;
    cout << "Print students by ascending order." << endl;
    bst2->inorderTraversal();
    cout << "End processing binary search tree 2." << endl;
    delete bst1;
    delete bst2;
    return 0;
}
