/* Goal: To find the min value stored in a non-empty BST.
 * Return: The min value
 * Remark: The min value is stored in the leftmost node.
 * Time complexity: O(height of BST)
 */

template <typename T>   /* File: bst-find-min.cpp */
const T& BST<T>::find_min() const
{
    const BSTnode* node = root;

    while (!node->left.is_empty()) // Look for the leftmost node
        node = node->left.root;

    return node->value;
}
