#include "boardtree.h"
#include "hashtable.h"

BoardTree::BoardTree(const Board& board)
{
    root = new BoardNode{board};
}

BoardTree::~BoardTree()
{
    delete root; // recursive
}

BoardTree *BoardTree::getSubTree(const BoardCoordinate &coords)
{
    // If subtree is empty, try to build it
    if (root->subTree[coords.row][coords.col].isEmpty()) {
        Board nextBoard = Board(root->board);
        if (nextBoard.play(BoardCoordinate(coords.row, coords.col))) {
            root->subTree[coords.row][coords.col].root = new BoardNode(nextBoard);
        }
    }
    return &(root->subTree[coords.row][coords.col]);
}

BoardOptimalMove BoardTree::getOptimalMove(const unsigned int depth)
{
    // If tree is empty, returns an illegal move
    if (isEmpty()) {
        return BoardOptimalMove();
    }

    BoardOptimalMove optimalMove;

    // Check current board score
    int boardScore = root->board.getBoardScore();

    // If depth = 0 or game already ended, returns current board's score
    // Coords don't matter because we cannot look further to determine the move
    if (depth == 0 || root->board.isFinished()) {
        return BoardOptimalMove{boardScore, BoardCoordinate(-1, -1)};
    }

    // Else, first check if this board state has already been calculated to the current depth
    BoardOptimalMove hashedMove = BoardHashTable::getInstance().getHashedMove(root->board.getID(), depth);
    if (hashedMove.score != ILLEGAL) {
        return hashedMove;
    }

    // Otherwise, get the score of all children subtrees
    int optimalScore = root->board.getCurPlayer() == X ? -WIN_SCORE - 1 : WIN_SCORE + 1;

    for (int i=0; i<BOARD_SIZE; ++i) {
        for (int j=0; j<BOARD_SIZE; ++j) {
            // If subtree is empty, try to build it
            if (root->subTree[i][j].isEmpty()) {
                Board nextBoard = Board(root->board);
                if (nextBoard.play(BoardCoordinate(i, j))) {
                    root->subTree[i][j].root = new BoardNode(nextBoard);
                }
            }

            // Get the subtree's score
            BoardOptimalMove childOpt = root->subTree[i][j].getOptimalMove(depth - 1);

            // Ignore illegal subtree
            if (childOpt.score == ILLEGAL) continue;

            // Found a subtree with better result (more "promising")
            if (root->board.getCurPlayer() == X ? childOpt.score > optimalScore : childOpt.score < optimalScore) {
                optimalScore = childOpt.score;
                optimalMove = BoardOptimalMove{optimalScore, BoardCoordinate{i, j}};
            }
        }
    }
    // Add the optimal move to the hash table
    BoardHashTable::getInstance().updateTable(root->board.getID(), depth, optimalMove);
    return optimalMove;
}

BoardOptimalMove BoardTree::getOptimalMoveAlphaBeta(const unsigned int depth, int alpha, int beta)
{
    // If tree is empty, returns an illegal move
    if (isEmpty()) {
        return BoardOptimalMove();
    }

    BoardOptimalMove optimalMove;

    // Check current board score
    int boardScore = root->board.getBoardScore();

    // If depth = 0 or game already ended, returns current board's score
    // Coords don't matter because we cannot look further to determine the move
    if (depth == 0 || root->board.isFinished()) {
        return BoardOptimalMove{boardScore, BoardCoordinate(-1, -1)};
    }

    // Otherwise, get the score of all children subtrees
    int optimalScore = root->board.getCurPlayer() == X ? -WIN_SCORE - 1 : WIN_SCORE + 1;
    int i = 0, j = 0;

    for (i = 0; i<BOARD_SIZE; ++i) {
        bool exit = false;
        for (j = 0; j<BOARD_SIZE; ++j) {
            // If subtree is empty, try to build it
            if (root->subTree[i][j].isEmpty()) {
                Board nextBoard = Board(root->board);
                if (nextBoard.play(BoardCoordinate(i, j))) {
                    root->subTree[i][j].root = new BoardNode(nextBoard);
                }
            }

            // Get the subtree's score
            BoardOptimalMove childOpt = root->subTree[i][j].getOptimalMoveAlphaBeta(depth - 1, alpha, beta);

            // Ignore illegal subtree
            if (childOpt.score == ILLEGAL) continue;

            // Found a subtree with better result (more "promising")
            if (root->board.getCurPlayer() == X ? childOpt.score > optimalScore : childOpt.score < optimalScore) {
                optimalScore = childOpt.score;
                optimalMove = BoardOptimalMove{optimalScore, BoardCoordinate{i, j}};
            }

            // Alpha-beta pruning
            if (root->board.getCurPlayer() == X) {
                // Maximizing player
                if (optimalScore > beta) {
                    exit = true;
                    break;
                }
                alpha = optimalScore > alpha ? optimalScore : alpha;
            }
            else {
                // Minimizing player
                if (optimalScore < alpha) {
                    exit = true;
                    break;
                }
                beta = optimalScore < beta ? optimalScore : beta;
            }
        }
        if (exit) break;
    }

    return optimalMove;
}
