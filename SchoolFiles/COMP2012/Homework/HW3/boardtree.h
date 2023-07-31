#ifndef __BOARDTREE_H__
#define __BOARDTREE_H__

#include <iostream>
#include "board.h"
#include "hashtable.h"

struct BoardNode;

class BoardTree {
    private:
        BoardNode* root {nullptr};

    public:
        // Default empty constructor
        BoardTree() = default;
        // Initialize root using the provided board
        BoardTree(const Board& board);
        // Destructor
        ~BoardTree();

        // We don't need to copy tree in this case
        BoardTree(const BoardTree&) = delete;
        BoardTree& operator=(BoardTree&) = delete;

        bool isEmpty() const { return root == nullptr; }

        // Return a pointer to the subtree at the given coordinates. Build the tree if it is empty.
        BoardTree* getSubTree(const BoardCoordinate& coords);

        // Calculate the best move by searching the tree up to depth moves ahead
        BoardOptimalMove getOptimalMove(const unsigned int depth);

        // Same as above but utilizes alpha-beta pruning
        BoardOptimalMove getOptimalMoveAlphaBeta(const unsigned int depth, int alpha, int beta);
};

struct BoardNode {
    const Board board; // Current board state
    BoardTree subTree[BOARD_SIZE][BOARD_SIZE]; // One sub-tree for each possible next move

    BoardNode(const Board& board): board(board) {}
    BoardNode(const BoardNode& node) = delete;
    BoardNode& operator=(const BoardNode& node) = delete;
};

#endif // __BOARDTREE_H__