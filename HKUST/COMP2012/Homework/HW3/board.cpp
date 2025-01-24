#include "board.h"
#include "const.h"

/* Task 1: Implement the game */


// Initialize cells as all empty, score with the given parameter, curPlayer as X and id as 0.
Board::Board(const int score[][BOARD_SIZE])
{
    for (int i=0;i<BOARD_SIZE;i++)
    {
        for (int j=0;j<BOARD_SIZE;j++)
        {
            this->score[i][j] = score[i][j];
            this->cells[i][j] = EMPTY;
        }
    }
    this->curPlayer = X;
    this->id = 0;
}

//  Returns true if all cells of the board are non-empty, and false otherwise. 
bool Board::isFull() const
{
    for (int i=0;i<BOARD_SIZE;i++)
    {
        for (int j=0;j<BOARD_SIZE;j++)
        {
            if(cells[i][j]==EMPTY)
                return false;
        }
    }

    

    return true;
}

//  Returns true if all cells of the board are non-empty or a player has gotten a match. 
bool Board::isFinished() const
{
    // check for full
    if(isFull())
    {
        return true;
    }

    // check for match vertically
    for(int row=0;row<BOARD_SIZE;row++)
    {
        int rowCounter=0;
        Cell previousCell = cells[row][0];
        if(previousCell!=EMPTY)
            rowCounter=1;
        for (int column=1;column<BOARD_SIZE;column++)
        {
            if(previousCell==cells[row][column] && cells[row][column]!=EMPTY)
                rowCounter++;
            previousCell = cells[row][column];
        }
        if(rowCounter==BOARD_SIZE)
            return true;
    }

    // check for match horizontally
    for(int column=0;column<BOARD_SIZE;column++)
    {
        int columnCounter=0;
        Cell previousCell = cells[0][column];
        if(previousCell!=EMPTY)
            columnCounter=1;
        for (int row=1;row<BOARD_SIZE;row++)
        {
            if(previousCell==cells[row][column] && cells[row][column]!=EMPTY)
                columnCounter++;
            previousCell = cells[row][column];
        }
        if(columnCounter==BOARD_SIZE)
            return true;
    }

    // check for match diagonal left to right
    int leftRightCheck =0;
    Cell firstCell = cells[0][0];
    if(firstCell!=EMPTY)
        leftRightCheck++;
    for(int i=1;i<BOARD_SIZE;i++)
    {
        if(firstCell==cells[i][i] && cells[i][i]!=EMPTY)
            leftRightCheck++;
    }
    if(leftRightCheck==BOARD_SIZE)
        return true;

    int rightLeftCheck =0;
    Cell lastCell = cells[0][BOARD_SIZE-1];
    if(lastCell!=EMPTY)
        rightLeftCheck++;
    for(int i=1;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            if(i+j==BOARD_SIZE-1)
            {
                if(cells[i][j]==lastCell)
                {
                    rightLeftCheck++;
                }
            }
        }
    }
    if(rightLeftCheck==BOARD_SIZE)
        return true;

    return false;
}


// Returns the board's score. First check if any player has gotten a match: a row, column or diagonal with all cells of that player. 
// If yes, return WIN_SCORE if player X has a match, or -WIN_SCORE if player O has a match. 
// Otherwise, calculate the score based on the current cells on the board. 
int Board::getBoardScore() const
{
    // check for match for player x
    if(curPlayer==O)
    {
        // check for match vertically
        for(int row=0;row<BOARD_SIZE;row++)
        {
            int rowCounter=0;
            Cell previousCell = cells[row][0];
            if(previousCell==X)
                rowCounter=1;
            for (int column=1;column<BOARD_SIZE;column++)
            {
                if(previousCell==cells[row][column])
                    rowCounter++;
            }
            // printf("Row counter: %i\n", rowCounter);
            if(rowCounter==BOARD_SIZE)
                return WIN_SCORE;
        }

        // check for match horizontally
        for(int column=0;column<BOARD_SIZE;column++)
        {
            int columnCounter=0;
            Cell previousCell = cells[0][column];
            if(previousCell==X)
                columnCounter=1;
            for (int row=1;row<BOARD_SIZE;row++)
            {
                if(previousCell==cells[row][column])
                    columnCounter++;
            }
            if(columnCounter==BOARD_SIZE)
                return WIN_SCORE;
        }

        // check for match diagonal left to right
        int leftRightCheck =0;
        Cell firstCell = cells[0][0];
        if(firstCell==X)
            leftRightCheck++;
        for(int i=1;i<BOARD_SIZE;i++)
        {
            if(firstCell==cells[i][i] && cells[i][i]!=EMPTY)
                leftRightCheck++;
        }
        if(leftRightCheck==BOARD_SIZE)
            return WIN_SCORE;

        int rightLeftCheck =0;
        Cell lastCell = cells[0][BOARD_SIZE-1];
        if(lastCell==X)
            rightLeftCheck++;
        for(int i=1;i<BOARD_SIZE;i++)
        {
            for(int j=0;j<BOARD_SIZE;j++)
            {
                if(i+j==BOARD_SIZE-1)
                {
                    if(cells[i][j]==lastCell)
                    {
                        rightLeftCheck++;
                    }
                }
            }
        }
        if(rightLeftCheck==BOARD_SIZE)
            return WIN_SCORE;
    }
    // check for match for player O
    else if(curPlayer==X)
    {
        // check for match vertically
        for(int row=0;row<BOARD_SIZE;row++)
        {
            int rowCounter=0;
            Cell previousCell = cells[row][0];
            if(previousCell==O)
                rowCounter=1;
            for (int column=1;column<BOARD_SIZE;column++)
            {
                if(previousCell==cells[row][column] && cells[row][column]!=EMPTY)
                    rowCounter++;
            }
            if(rowCounter==BOARD_SIZE)
                return -WIN_SCORE;
        }

        // check for match horizontally
        for(int column=0;column<BOARD_SIZE;column++)
        {
            int columnCounter=0;
            Cell previousCell = cells[0][column];
            if(previousCell==O)
                columnCounter=1;
            for (int row=1;row<BOARD_SIZE;row++)
            {
                if(previousCell==cells[row][column] && cells[row][column]!=EMPTY)
                    columnCounter++;
            }
            if(columnCounter==BOARD_SIZE)
                return -WIN_SCORE;
        }

        // check for match diagonal left to right
        int leftRightCheck =0;
        Cell firstCell = cells[0][0];
        if(firstCell==O)
            leftRightCheck++;
        for(int i=1;i<BOARD_SIZE;i++)
        {
            if(firstCell==cells[i][i] && cells[i][i]!=EMPTY)
                leftRightCheck++;
        }
        if(leftRightCheck==BOARD_SIZE)
            return -WIN_SCORE;

        int rightLeftCheck =0;
        Cell lastCell = cells[0][BOARD_SIZE-1];
        if(lastCell==O)
            rightLeftCheck++;
        for(int i=1;i<BOARD_SIZE;i++)
        {
            for(int j=0;j<BOARD_SIZE;j++)
            {
                if(i+j==BOARD_SIZE-1)
                {
                    if(cells[i][j]==lastCell)
                    {
                        rightLeftCheck++;
                    }
                }
            }
        }
        if(rightLeftCheck==BOARD_SIZE)
            return -WIN_SCORE;

    }
    // if no match, then update current score according to score matrix 
    int cur_score =0;
    int totalMoves = BOARD_SIZE*BOARD_SIZE;
    int moves_x =0;
    int moves_o =0;
    if(totalMoves%2!=0)
    {
        moves_x = totalMoves/2+1;
        moves_o = totalMoves/2;
    }
    else
    {
        moves_x = totalMoves/2;
        moves_o = totalMoves/2;
    }
    for (int row=0;row<BOARD_SIZE;row++)
    {
        for(int col=0;col<BOARD_SIZE;col++)
        {
            if(cells[row][col]==X)
            {
                // printf("Row: %i Column: %i Score: %i\n",row,col,score[row][col]);
                cur_score+=score[row][col]*(moves_o);
            }
            else if(cells[row][col]==O)
            {
                // printf("Row: %i Column: %i Score: %i\n",row,col,score[row][col]);
                cur_score-=score[row][col]*(moves_x);
            }
        }
    }
    
    return cur_score;
}

// If the move is not valid (out of bounds or the cell is filled), return false. 
// Otherwise, update the corresponding cells array element, change curPlayer to the other player and update id according to the algorithm.
bool Board::play(const BoardCoordinate& coords)
{
    // if coordinates not valid
    if(coords.isValid()!=1)
        return false;

    // if cell filled
    if(cells[coords.row][coords.col]!=EMPTY)
        return false;

    // if no players
    if(curPlayer==EMPTY)
        return false;

    // update cells
    cells[coords.row][coords.col] = curPlayer;

    // update player
    if(curPlayer==X)
        curPlayer = O;
    else if(curPlayer==O)
        curPlayer = X;
    
    // update id
    id = 0;
    //for each cell 
    for (int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {   
            unsigned long long cellValue = 0;     
            //  cellValue = 0 if cell is empty, 1 if cell is X, 2 if cell is 0;
            if(cells[i][j] == EMPTY)
                cellValue = 0;
            else if(cells[i][j]==X)
                cellValue = 1;
            else if(cells[i][j]==O)
                cellValue = 2;
            id += cellValue * (pow(3,i*BOARD_SIZE+j));
        }
    }


    return true;
}