#include "lab7.h"
using namespace std;

/* Global variable definitions */
int total_step = 0;
int board_size = 0;

/* Main function */
int main(){
    char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    char c = '\0';
    
    Player ps[2];
    while(true){
        // get chessboard size
        while(true){
            cout << "Please specify the size of chessboard (2-10)" << endl;
            cin >> board_size;
            if (board_size < 2 || board_size > 10)
                cout << "the size of chessboard should be in 2-10" << endl;
            else
                break;
        }

        // initialization
        srand(0); // set random seed
        initialize_player(ps, 0);
        initialize_player(ps, 1);
        initialize_board(board, ps);

        // play game
        play_game(ps, board);

        // whether play again
        c = '\0';
        while (c != 'y' && c != 'n'){
            cout << "Play again? (y/n): ";
            cin >> c;
        }
        total_step = 0;
        if(c=='y') continue;
        else break;
    }

    return 0;
}