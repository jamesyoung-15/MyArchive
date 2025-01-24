/* File: btree-inorder.cpp
 *
 * To traverse a binary tree in the order of:
 *    left subtree, node, right subtree
 * and do some action on each node during the traversal.
 */

template <class T>
void btree_inorder(BTnode<T>* root,
     void (*action)(BTnode<T>* r)) // Expect a function on r->data
{
    if (root)
    {
        btree_inorder(root->get_left(), action);
        action(root);              // e.g. print out root->data
        btree_inorder(root->get_right(), action);
    }
}

