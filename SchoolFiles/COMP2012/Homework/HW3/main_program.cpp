#include <iostream>
using namespace std;

#include <chrono>

#include "board.h"
#include "boardtree.h"
#include "hashtable.h"

int main(int argc, char* argv[]) {
    // Parameters
    bool scoreInput = false;
    enum {AUTO, VERSUS, HINTED, MANUAL} mode = HINTED;
    bool alphabeta = false;
    int score[BOARD_SIZE][BOARD_SIZE];
    int searchDepth = -1;

    for (int i=1; i<argc; i++) {
        // If manual scoreboard input is enabled
        if (string(argv[i]) == "-s" || string(argv[i]) == "--score") {
            scoreInput = true;
        }

        // If autoplay is enabled
        else if (string(argv[i]) == "-a" || string(argv[i]) == "--auto") {
            if (mode != HINTED) {
                cout << "Multiple modes specified, which is not allowed. Select either -a, -v, -m or none." << endl;
                return 0;
            }
            mode = AUTO;
        }

        // If versus mode is enabled
        else if (string(argv[i]) == "-v" || string(argv[i]) == "--versus") {
            if (mode != HINTED) {
                cout << "Multiple modes specified, which is not allowed. Select either -a, -v, -m or none." << endl;
                return 0;
            }
            mode = VERSUS;
        }

        // If manual mode is enabled
        else if (string(argv[i]) == "-m" || string(argv[i]) == "--manual") {
            if (mode != HINTED) {
                cout << "Multiple modes specified, which is not allowed. Select either -a, -v, -m or none." << endl;
                return 0;
            }
            mode = MANUAL;
        }

        // If alpha-beta pruning is enabled
        else if (string(argv[i]) == "-ab" || string(argv[i]) == "--alphabeta") {
            alphabeta = true;
        }

        // Depth specification
        else if (string(argv[i]) == "-d" || string(argv[i]) == "--depth") {
            if (i == argc - 1) {
                cout << "Invalid command line argument. Type .\\pa3.exe -h or .\\pa3.exe --help for details." << endl;
                return 0;
            }
            searchDepth = atoi(argv[++i]);
        }

        // Help text
        else if (string(argv[i]) == "-h" || string(argv[i]) == "--help") {
            cout << "The following arguments are available:" << endl;
            cout << "-d [num] or --depth [num]: \t\t Set the search depth. Default value is specified in const.h." << endl;
            cout << "-s or --score: \t\t\t Enable manual score grid input. Default values are specified in const.h." << endl;
            cout << "-ab or --alphabeta: \t\t\t Enable alpha-beta pruning." << endl;
            cout << "-a or --auto: \t\t\t Let BoardTree automatically plays its suggested moves." << endl;
            cout << "-v or --versus: \t\t\t Play against the BoardTree." << endl;
            cout << "-m or --manual: \t\t\t Disable BoardTree if you would like to test the game logic." << endl;
            cout << "You can combine arguments such as .\\pa3.exe -s -ab -d 6 -a" << endl;
            return 0;
        }

        // Else, invalid argument specified
        else {
            cout << "Invalid command line argument. Type .\\pa3.exe -h or .\\pa3.exe --help for details." << endl;
            return 0;
        }
    }
    
    if (searchDepth <= 0) {
        cout << "Search depth not specified. Using preset depth of " << DEPTH_PRESET << "." << endl;
        searchDepth = DEPTH_PRESET;
    }

    if (pow(BOARD_SIZE * BOARD_SIZE, searchDepth) > 1e10) {
        cout << "WARNING: High search depth can use up a large amount of memory and will likely crash your computer. Aborting." << endl;
        return 0;
    }

    if (scoreInput) {
        cout << "Input the score for each cell, row by row: " << endl;
        for (int j=0; j<BOARD_SIZE; ++j) {
            for (int k=0; k<BOARD_SIZE; ++k) {
                cin >> score[j][k];
            }
        }
    }
    else {
            for (int j=0; j<BOARD_SIZE; ++j) {
                for (int k=0; k<BOARD_SIZE; ++k) {
                    score[j][k] = SCORE_PRESET[j][k];
                }
            }
    }

    int player = -1;
    if (mode == VERSUS) {
        do {
            cout << "Which player you would like to play as (0 for O, 1 for X)? Type -1 to quit game." << endl;
            cin >> player;
        } while (player < -1 || player >= 2);
        if (player == -1) return 0;
    }

    cout << "Score grid:" << endl;
    printBoard<int, int>(cout, score, [](int x)->int {return x;});
    
    cout << "Search depth: " << searchDepth << endl;
    
    Board board{score};
    cout << board;
    cout << "Score: " << board.getBoardScore() << endl;
    cout << "ID: " << board.getID() << endl;

    BoardTree tree{board};
    BoardTree* currentTreeRoot = &tree;

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    while (true) {
        BoardCoordinate move{-1, -1};
        if (mode == AUTO || mode == VERSUS && ((player == 0 && board.getCurPlayer() == X) || (player == 1 && board.getCurPlayer() == O))) {
            // Bot
            BoardOptimalMove optMove;
            if (alphabeta)
                optMove = currentTreeRoot->getOptimalMoveAlphaBeta(searchDepth, -WIN_SCORE - 1, WIN_SCORE + 1);
            else
                optMove = currentTreeRoot->getOptimalMove(searchDepth);
            cout << "Estimated best score: " << optMove.score << endl;
            cout << "Row: " << optMove.coords.row << endl;
            cout << "Col: " << optMove.coords.col << endl;
            move = optMove.coords;
        }
        else {
            // Give hint in non-versus
            if (mode == HINTED) {
                BoardOptimalMove optMove;
                if (alphabeta)
                    optMove = currentTreeRoot->getOptimalMoveAlphaBeta(searchDepth, -WIN_SCORE - 1, WIN_SCORE + 1);
                else
                    optMove = currentTreeRoot->getOptimalMove(searchDepth);
                cout << "Estimated best score: " << optMove.score << endl;
                cout << "Row: " << optMove.coords.row << endl;
                cout << "Col: " << optMove.coords.col << endl;
            }
            // Player
            int row, col;
            do {
                cout << "Select a row from 0 to " << BOARD_SIZE - 1 << " (top to bottom). Type -1 to quit game." << endl;
                cin >> row;
            } while (row < -1 || row >= BOARD_SIZE);
            if (row == -1) break;
            do {
                cout << "Select a column from 0 to " << BOARD_SIZE - 1 << " (left to right). Type -1 to quit game." << endl;
                cin >> col;
            } while (col < -1 || col >= BOARD_SIZE);
            if (col == -1) break;
            move = BoardCoordinate{row, col};
        }

        board.play(move);
        currentTreeRoot = currentTreeRoot->getSubTree(move);
        cout << board;

        int boardScore = board.getBoardScore();
        cout << "Score: " << boardScore << endl;
        cout << "ID: " << board.getID() << endl;

        if (boardScore == WIN_SCORE) {
            cout << "Player X won!" << endl;
            break;
        }
        else if (boardScore == -WIN_SCORE) {
            cout << "Player O won!" << endl;
            break;
        }
        else if (board.isFull()) {
            if (boardScore > 0) {
                cout << "Player X won!" << endl;
            }
            else if (boardScore < 0) {
                cout << "Player O won!" << endl;
            }
            else {
                cout << "Draw!" << endl;
            }
            break;
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    if (mode == AUTO) cout << "Took " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds." << endl;

    // BoardHashTable::getInstance().clearTable();

    return 0;
}