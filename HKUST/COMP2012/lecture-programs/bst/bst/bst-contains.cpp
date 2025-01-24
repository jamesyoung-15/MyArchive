/* Goal: To check if the BST contains the value x.
 * Return: (bool) true or false
 * Time complexity: O(height of BST)
 */

template <typename T>         /* File: bst-contains.cpp */
bool BST<T>::contains(const T& x) const
{
    if (is_empty())           // Base case #1
        return false;
    
    if (root->value == x)     // Base case #2
        return true;

    else if (x < root->value) // Recursion on the left sub-tree
        return root->left.contains(x);

    else                      // Recursion on the right sub-tree
        return root->right.contains(x);
}
