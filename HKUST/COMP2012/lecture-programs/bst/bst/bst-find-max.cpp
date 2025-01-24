/* Goal: To find the max value stored in a non-empty BST.
 * Return: The max value
 * Remark: The max value is stored in the rightmost node.
 * Time complexity: O(height of BST)
 */

template <typename T>   /* File: bst-find-max.cpp */
const T& BST<T>::find_max() const
{
    const BSTnode* node = root;

    while (!node->right.is_empty()) // Look for the rightmost node
        node = node->right.root;

    return node->value;
}
