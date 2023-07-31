template <typename T>           /* File: bst-remove.cpp */
void BST<T>::remove(const T& x) // leftmost item of its right subtree
{
    if (is_empty())             // Item is not found; do nothing
        return;
    
    if (x < root->value)        // Remove from the left subtree
        root->left.remove(x);
    else if (x > root->value)   // Remove from the right subtree
        root->right.remove(x);
    else if (root->left.root && root->right.root) // Found node has 2 children
    {
        root->value = root->right.find_min(); // operator= defined?
        root->right.remove(root->value); // min is copied; can be deleted now 
    }
    else                        // Found node has 0 or 1 child
    {
        BSTnode* deleting_node = root; // Save the root to delete first
        root = (root->left.is_empty()) ? root->right.root : root->left.root;

        // Set subtrees to nullptr before removal due to recursive destructor
        deleting_node->left.root = deleting_node->right.root = nullptr;
        delete deleting_node;
    }
}
