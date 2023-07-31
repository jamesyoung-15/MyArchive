#include "btree.h"      /* File: test-btree.cpp */
#include "btree-preorder.cpp"      
#include "btree-inorder.cpp"      
#include "btree-postorder.cpp"      

template <typename T>
void print(BTnode<T>* root) { cout << root->get_data() << endl; }

int main() // Build the tree from bottom up
{   // Create the left subtree
    BTnode<int>* node5 = new BTnode<int>(5);
    BTnode<int>* node9 = new BTnode<int>(9);
    BTnode<int>* node8 = new BTnode<int>(8, node5, node9);
    // Create the right subtree
    BTnode<int>* node12 = new BTnode<int>(12);
    BTnode<int>* node17 = new BTnode<int>(17);
    BTnode<int>* node15 = new BTnode<int>(15, node12, node17);
    // Create the root node
    BTnode<int>* root = new BTnode<int>(10, node8, node15);

    cout << "\nInorder traversal result:\n"; btree_inorder(root, print);
    cout << "\nPreorder traversal result:\n"; btree_preorder(root, print);
    cout << "\nPostorder traversal result:\n"; btree_postorder(root, print);
    cout << "\nDeleting the binary tree ...\n"; delete root; return 0;
}
