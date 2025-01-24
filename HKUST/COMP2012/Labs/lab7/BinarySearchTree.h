#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
struct ScorePair {
    T1 baseScore;
    T2 bonusScore;
};

template<typename T1, typename T2>
class BinarySearchTree
{
private:
    BinarySearchTree *left_sub_tree;
    BinarySearchTree *right_sub_tree;
    string name;
    ScorePair<T1, T2> score;

public:
    BinarySearchTree() = delete;
    BinarySearchTree(const string&, const T1&, const T2&);

    // TODO
    BinarySearchTree(const BinarySearchTree&);
    ~BinarySearchTree();

    int size() const;
    bool findByScorePair(const T1&, const T2&) const;
    bool findByName(const string&) const;
    void insert(const string&, const T1&, const T2&);
    void inorderTraversal() const;

    //given
    void printName() const;
    void printPoint() const;
    void printAll() const;

};



#include "BinarySearchTree.tpp"

#endif