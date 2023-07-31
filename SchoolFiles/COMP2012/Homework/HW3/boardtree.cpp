#include "boardtree.h"
#include "board.h"
#include "const.h"

// The constructor initializes the root BoardNode with the provided board. 
BoardTree::BoardTree(const Board& board)
{
    root = new BoardNode(board);
}
// Free any dynamic memory accordingly. Hint: BoardTree is similar to BT/BST introduced in the course materials. 
BoardTree::~BoardTree()
{
    delete root;
}

// Returns a pointer to the sub-tree indicated by the given coordinates. This represents the child node corresponding to the move with the given coordinates. 
// If the sub-tree is empty, you should try to build the sub-tree first
BoardTree* BoardTree::getSubTree(const BoardCoordinate &coords)
{
    Board newBoard = root->board;
    if(!coords.isValid())
        return nullptr;
    if(root->subTree[coords.row][coords.col].isEmpty())
    {
        if(newBoard.play(coords))
        {
            root->subTree[coords.row][coords.col].root = new BoardNode(newBoard);
        }
        else 
        {
            return nullptr;
        }
    }
    return &root->subTree[coords.row][coords.col];
}

// Calculate the best move by searching the tree up to depth moves ahead
BoardOptimalMove BoardTree::getOptimalMove(const unsigned int depth)
{
    // return a dummy illegal move
    if(root==nullptr)
        return BoardOptimalMove();
    
    // return score and random coordinate if game finished or 0 depth
    if(depth==0 || root->board.isFinished())
        return BoardOptimalMove(root->board.getBoardScore(),BoardCoordinate(1,1));


    // if move exists in the hash table
   if(BoardHashTable::getInstance().getHashedMove(root->board.getID(),depth).score!=ILLEGAL)
        return BoardHashTable::getInstance().getHashedMove(root->board.getID(),depth);

    // Else, we find the estimated score and optimal move of this node by calculating the score of each children node
    // Player X is trying to maximize the score, so the estimated score is the maximum of children scores
    // Vice versa, player O is trying to minimize the score
    int estimatedScore=0;
    if(root->board.getCurPlayer()==X)
        estimatedScore=-WIN_SCORE-1000;
    else if(root->board.getCurPlayer()==O)
        estimatedScore=WIN_SCORE+1000;
    BoardOptimalMove bestMove;


   // otherwise do as usual
        // for each subtree, build tree if empty, if move illegal subtree move to next subtree
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            BoardCoordinate coords = BoardCoordinate(i,j);;
            // build the subtree if it is empty
            if(root->subTree[i][j].isEmpty())
            {
                getSubTree(coords);
            }
            BoardOptimalMove childMove = root->subTree[i][j].getOptimalMove(depth-1);
            if (childMove.score == ILLEGAL) 
            {
                // If the move is illegal, the subtree corresponds to an invalid move/board, simply skip to the next subtree
                continue;
            }
            if((root->board.getCurPlayer()==X && childMove.score>estimatedScore) || (root->board.getCurPlayer()==O && childMove.score<estimatedScore))
            {
                estimatedScore = childMove.score;
                bestMove = BoardOptimalMove(estimatedScore,coords);
            }

        }
    }
    // update hash table
    BoardHashTable::getInstance().updateTable(root->board.getID(),depth,bestMove);
    return bestMove;
}

// Same as above but utilizes alpha-beta pruning, currently says do not use transposition table
BoardOptimalMove BoardTree::getOptimalMoveAlphaBeta(const unsigned int depth, int alpha, int beta)
{
    // return a dummy illegal move
    if(root==nullptr)
        return BoardOptimalMove();
    
    // return score and random coordinate if game finished or 0 depth
    if(depth==0 || root->board.isFinished())
        return BoardOptimalMove(root->board.getBoardScore(),BoardCoordinate(1,1));

//     // if move exists in the hash table
//    if(BoardHashTable::getInstance().getHashedMove(root->board.getID(),depth).score!=ILLEGAL)
//         return BoardHashTable::getInstance().getHashedMove(root->board.getID(),depth);


    // Else, we find the estimated score and optimal move of this node by calculating the score of each children node
    // Player X is trying to maximize the score, so the estimated score is the maximum of children scores
    // Vice versa, player O is trying to minimize the score
    int estimatedScore=0;
    if(root->board.getCurPlayer()==X)
        estimatedScore=-WIN_SCORE-1000;
    else if(root->board.getCurPlayer()==O)
        estimatedScore=WIN_SCORE+1000;
    BoardOptimalMove bestMove;
    bool breakEarly = false;

    // for each subtree, build tree if empty, if move illegal subtree move to next subtree
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            BoardCoordinate coords = BoardCoordinate(i,j);;
            // build the subtree if it is empty
            if(root->subTree[i][j].isEmpty())
            {
                getSubTree(coords);
            }
            BoardOptimalMove childMove = root->subTree[i][j].getOptimalMoveAlphaBeta(depth-1,alpha,beta);
            if (childMove.score == ILLEGAL) 
            {
                // If the move is illegal, the subtree corresponds to an invalid move/board, simply skip to the next subtree
                continue;
            }
            if((root->board.getCurPlayer()==X && childMove.score>estimatedScore) || (root->board.getCurPlayer()==O && childMove.score<estimatedScore))
            {
                estimatedScore = childMove.score;
                bestMove = BoardOptimalMove(estimatedScore,coords);
            }
            int optimalScore = bestMove.score;
            // ADDED: Update alpha and beta according to newest child score found
            if (root->board.getCurPlayer()==X) 
            {
                if (optimalScore >= beta) 
                {
                    // Found a move that would be worse for O, so O will not consider this subtree
                    // exit loop;
                    i = BOARD_SIZE;
                    j = BOARD_SIZE;
                    breakEarly = true;
                }
                // Update the best move found by X
                alpha = fmax(optimalScore, alpha);
            }
            else 
            {
                // Same logic but for current player O
                if (optimalScore <=alpha) 
                {
                    // exit loop;
                    i = BOARD_SIZE;
                    j = BOARD_SIZE;
                    breakEarly = true;
                }
                beta = fmin(optimalScore, beta);
            }
        }
    }

    // // only update hashtable if all subtrees explored, don't update if loop exited early
    // if(!breakEarly)
    // {
    //     BoardHashTable::getInstance().updateTable(root->board.getID(),depth,bestMove);
    // }
    return bestMove;
}