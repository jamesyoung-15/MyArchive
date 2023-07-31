template <typename T>          /* File: bst-insert.cpp */
void BST<T>::insert(const T& x)
{
    if (is_empty())            // Find the spot
        root = new BSTnode(x);

    else if (x < root->value)
        root->left.insert(x);  // Recursion on the left sub-tree

    else if (x > root->value)
        root->right.insert(x); // Recursion on the right sub-tree

    else // This line is optional; just for illustration
        ;                      // x == root->value; do nothing
}
