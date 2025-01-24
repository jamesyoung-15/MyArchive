/* File: btree-postorder.cpp
 *
 * To traverse a binary tree in the order of:
 *    left subtree, right subtree, node
 * and do some action on each node during the traversal.
 */

template <class T>
void btree_postorder(BTnode<T>* root,
     void (*action)(BTnode<T>* r)) // Expect a function on r->data
{
    if (root)
    {
        btree_postorder(root->get_left(), action);
        btree_postorder(root->get_right(), action);
        action(root);              // e.g. print out root->data
    }
}

