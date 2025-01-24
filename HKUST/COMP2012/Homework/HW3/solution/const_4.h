#ifndef __CONST_H__
#define __CONST_H__

#include <iostream>
#include <cmath>

// Board size and table size. To try 4x4 mode, comment the following 2 lines and uncomment the bottom 2, then change SCORE_PRESET accordingly.
const int BOARD_SIZE = 4;
const int TABLE_SIZE = 200009;

// Constants representing "score of a winning player" and "illegal score".
const int WIN_SCORE = 10000;
const int ILLEGAL = 20000;

const int SCORE_PRESET[BOARD_SIZE][BOARD_SIZE] = {
    {4, 14, 15, 1},
    {9, 7, 6, 12},
    {5, 11, 10, 8},
    {16, 2, 3, 13},
};

// Default search depth
const int DEPTH_PRESET = 7;

enum Cell {
    EMPTY = 0,
    X = 1,
    O = -1,
};

// Helper function to get the character representing the player. You don't need to use this function.
const char cellChr[3] {'O', ' ', 'X'};
static const char cell2chr(const Cell c) {
    return cellChr[static_cast<int>(c) + 1];
}

// Helper function for printing any grid. You don't need to use this function.
// T2C is a function pointer parameter, which can accept a lambda or a function name
template<typename T, typename C>
void printBoard(std::ostream &os, T grid[BOARD_SIZE][BOARD_SIZE], C(*T2C)(const T)) {
    for (int j=0; j<BOARD_SIZE; ++j) {
        os << "====";
        if (j == BOARD_SIZE - 1) os << "=";
    }
    os << std::endl;
    for (int i=0; i<BOARD_SIZE; ++i) {
        os << "| ";
        for (int j=0; j<BOARD_SIZE; ++j) {
            os << T2C(grid[i][j]);
            if (j != BOARD_SIZE - 1) os << " | ";
        }
        os << " |" << std::endl;
        for (int j=0; j<BOARD_SIZE; ++j) {
            os << "====";
            if (j == BOARD_SIZE - 1) os << "=";
        }
        os << std::endl;
    }
}

// Helper function for getting the score scaling for each player.
// You should multiply X's score with number of moves O can play, and vice versa.
const int cellWeight[3] {(BOARD_SIZE * BOARD_SIZE + 1) / 2, 1, (BOARD_SIZE * BOARD_SIZE + 0) / 2};
static const int getCellWeight(const Cell c) {
    return cellWeight[static_cast<int>(c) + 1];
}

#endif // __CONST_H__