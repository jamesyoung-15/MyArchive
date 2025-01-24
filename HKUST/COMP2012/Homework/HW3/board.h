#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "const.h"

struct BoardCoordinate {
    int row, col;

    BoardCoordinate(int row, int col): row(row), col(col) {}
    bool isValid() const { return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE; }
};

struct BoardOptimalMove {
    int score;
    BoardCoordinate coords;

    // Default constructor returns an "illegal" move
    BoardOptimalMove(): score(ILLEGAL), coords(BoardCoordinate(-1, -1)) {}
    BoardOptimalMove(const int score, const BoardCoordinate& coords): score(score), coords(coords) {}
};

class Board {
    friend std::ostream& operator<<(std::ostream& os, const Board& board) {
        printBoard<const Cell, const char>(os, board.cells, cell2chr);
        return os;
    }

    private:
        Cell cells[BOARD_SIZE][BOARD_SIZE];
        int score[BOARD_SIZE][BOARD_SIZE];
        Cell curPlayer;
        unsigned long long id;

    public:
        // Initialize cells as all empty, score with the given parameter, curPlayer as X and id as 0.
        Board(const int score[][BOARD_SIZE]);

        // Return true if all cells are not EMPTY.
        bool isFull() const;

        // Return true if the game has finished (a match is found or board is full).
        bool isFinished() const;

        // Calculate the board's current score.
        int getBoardScore() const;

        // Play the next move at coords. If successful, update the data members and return true. Otherwise return false.
        bool play(const BoardCoordinate& coords);

        // Implemented
        Cell getCurPlayer() const { return curPlayer; }
        unsigned long long getID() const { return id; }
};

#endif // __BOARD_H__