#include <cstddef>
template<typename T1, typename T2>
BinarySearchTree<T1, T2>::BinarySearchTree(const string& name, const T1& x, const T2& y):
    name(name), score{x, y}, left_sub_tree(nullptr), right_sub_tree(nullptr) {}

template<typename T1, typename T2>
BinarySearchTree<T1, T2>::BinarySearchTree(const BinarySearchTree<T1, T2>& other_tree):
    // TODO 1: copy the members of this node and two subtrees
name(other_tree.name), score(other_tree.score)
{
    // allocate memory accordingly
    if(other_tree.left_sub_tree != nullptr)
        left_sub_tree = new BinarySearchTree(*other_tree.left_sub_tree);
    
    else 
        left_sub_tree = nullptr;

    if(other_tree.right_sub_tree != nullptr)
        right_sub_tree = new BinarySearchTree(*other_tree.right_sub_tree);
    else 
        right_sub_tree = nullptr;
}

template<typename T1, typename T2>
BinarySearchTree<T1, T2>::~BinarySearchTree() {
    // TODO 2: release the resources occupied by the two subtrees

    if(left_sub_tree!=nullptr)
        delete left_sub_tree;
    if(right_sub_tree!=nullptr)
        delete right_sub_tree;
    left_sub_tree = nullptr;
    right_sub_tree = nullptr;
};

template<typename T1, typename T2>
int BinarySearchTree<T1, T2>::size() const {
    // TODO 3: return the size of the tree by recursively compute the size
    
    // base case
    if(this==nullptr)
    {
        return 0;
    }


    return 1+this->left_sub_tree->size() + this->right_sub_tree->size();


}

template<typename T1, typename T2>
bool BinarySearchTree<T1, T2>::findByScorePair(const T1 &x, const T2 &y) const {
    // TODO 4: find the name of the node by the score.
    // If the score exists, call printName(), and return true
    // If the score does not exist, do nothing and return false
    // Hint: call the function recursively
    // **Note**: You are expected to search either left or right tree and compare the value to get the node contains target ScorePair.
    
    // base case, does not exit or couldn't find
    if(this == nullptr)
        return false;
    // if found, print and return true
    if(this->score.baseScore == x && this->score.bonusScore == y)
    {    
        printName();
        return true;
    }
    
    // recursively find left and right
    return left_sub_tree->findByScorePair(x,y) || right_sub_tree->findByScorePair(x,y);

    
}

template<typename T1, typename T2>
bool BinarySearchTree<T1, T2>::findByName(const string& name) const {
    // TODO 5: find the score of the node by the name.
    // If the score exists, call printPoint(), and return true
    // If the score does not exist, do nothing and return false
    // Hint: use 'a.compare(b)' or 'a == b' to do the string comparison.
    
    // base case, if not found
    if(this == nullptr)
        return false;
    // if found, print and return true
    if(this->name==name)
    {
        printPoint();
        return true;
    }
    bool testLeft = false;
    bool testRight = false;
    // find name recursively
    if(this->left_sub_tree!=nullptr)
        testLeft = this->left_sub_tree->findByName(name);
    if(this->right_sub_tree!=nullptr)
        testRight = this->right_sub_tree->findByName(name);
    // if either side has name, return true
    if(testLeft || testRight)
    {
        return true;
    }
    return false;
}


template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::insert(const string& name, const T1 &x, const T2 &y) {
    if (findByName(name) || findByScorePair(x, y)) {
        cout << "The data exists." << endl;
        return;
    }
    // TODO 6: Insert a node to the tree. Do nothing if any of name or score exists. (Which is given)
    // implement the remaining code below

    // left side, if base score larger than score to be inserted or scores equal and bonus larger
    if(this->score.baseScore > x || (this->score.baseScore == x && this->score.bonusScore > y) )
    {
        if(!left_sub_tree)
            left_sub_tree = new BinarySearchTree(name,x,y);
        else
            left_sub_tree->insert(name,x,y);
    }



    // right side if base score smaller than score to be inserted or scores equal and bonus smaller
    else if(this->score.baseScore < x || (this->score.baseScore == x && this->score.bonusScore < y) )
    {
        if(!right_sub_tree)
            right_sub_tree = new BinarySearchTree(name,x,y);
        else
            right_sub_tree->insert(name,x,y);
    }
    return;
}

template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::inorderTraversal() const {
    // TODO 7: run printAll() by in order traversal
    if(this!=nullptr)
    {
        left_sub_tree->inorderTraversal();
        this->printAll();
        right_sub_tree->inorderTraversal();
    }
}

template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printName() const {
    cout << "The name is " << name << "." << endl;
}

template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printPoint() const {
    cout << "The score is " << "(" << score.baseScore << ", " << score.bonusScore << ")." << endl;
}

template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printAll() const {
    cout << "Name: " << name << ", " << "Point: (" << score.baseScore << ", " << score.bonusScore << ")." << endl;
}

