/* Include guard */
#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <stdlib.h>
#include <string>

/* Constant definitions */
const int MAX_BOARD_SIZE = 10;

/* Struct definitions */
struct Player{
    char letter = '\0';
    int loc[2] = {0,0};
    int weight = 0;
};

/* External function declarations */
// TODO 1

extern void initialize_player(Player ps[], int idx);
extern void initialize_board(char board[][MAX_BOARD_SIZE], const Player ps[]);
extern void play_game(Player ps[], char board[][MAX_BOARD_SIZE]);

#endif
