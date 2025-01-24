#include "iostream"
using namespace std;


template<typename T> class BST
{
    private:
        struct BSTNode{
            T data;
            BST left;
            BST right;
            BSTNode(const T& x) : data(x){}
            BSTNode(const BSTNode& other) {
                data = other.data;
                left = other.left;
                right = other.right;
            }
        };
        BSTNode * root;
    public:
        BST():root(nullptr){}
        ~BST(){delete root;}
        BST(const BST& bst)
        {
            if(isEmpty())
            {
                return;
            }
            root = new BSTNode(*bst.root);
        }
        
        bool isEmpty() const {return root == nullptr;}

        bool contains(const T& x) const {
            if(root==nullptr)
                return false;
            if(root->value == x)
                return true;
            else if (x.data < root->data)
                return root->left.contains(x);
            else if(x>root->data)
                return root->right.contains(x);
        }

        void print() const{
            if(root == nullptr)
                return;
            root->right.print();
            cout<< root->data << " ";
            root->left.print();
        }

        const T& findMax() const{
            BSTNode* temp = root;
            while(root->right!=nullptr)
                temp = temp->right.root;

            return temp->data;
        }

        const T& findMin() const{
            BSTNode* temp = root;
            while(root->left!=nullptr)
                temp = temp->left.root;

            return temp->data;
        }


        void insert(const T& d){
            if(root==nullptr)
                root = new BSTNode(d);
            else if(d>root->data)
                root->right.insert(d);
            else
                root->left.insert(d);
        }

        void remove(const T& d){
            // check if item is found
            if(root==nullptr)
                return;
            // go left subtree if smaller than root
            if(d < root->data){
                root->left.remove(d);
            }
            // go right if larger than root
            else if(d>root->data){
                root->right.remove(d);
            }
            // if has two children, replace node with the min of the right subtree then can remove
            else if(root->left.root && root->right.root){
                root->value = root->right.findMin();
                root->right.remove(root->value);
            }
            // remove node
            else{
                BSTNode * deleteNode = root;
                if(root->left.isEmpty())
                    root = root->right.root;
                else if(root->right.isEmpty())
                    root = root->left.root;
                delete deleteNode;
            }
        }


};


int main()
{
    

    
    return 0;
}