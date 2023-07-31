#include <iostream>
using namespace std;

#include <chrono>

#include "board.h"
#include "boardtree.h"
#include "hashtable.h"

// Uncomment the body of each of these functions once you finish the tasks
// In VS Code, you can select the comment block and type Ctrl + /

void task1() {
    Board board{SCORE_PRESET};
    cout << board;
    cout << "Score: " << board.getBoardScore() << endl;
    cout << "ID: " << board.getID() << endl;

    while (true) {
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

        board.play(BoardCoordinate{row, col});
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

        // // Own test
        // else if(board.isFinished())
        // {
        //     cout<< "Finished function" << endl;
        // }
    }
}

void task2() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Board board{SCORE_PRESET};
    cout << board;
    cout << "Score: " << board.getBoardScore() << endl;
    cout << "ID: " << board.getID() << endl;

    BoardTree tree{board};
    BoardTree* currentTreeRoot = &tree;

    while (true) {
        BoardOptimalMove optMove = currentTreeRoot->getOptimalMove(DEPTH_PRESET);
        cout << "Estimated best score: " << optMove.score << endl;
        cout << "Row: " << optMove.coords.row << endl;
        cout << "Col: " << optMove.coords.col << endl;

        board.play(optMove.coords);
        currentTreeRoot = currentTreeRoot->getSubTree(optMove.coords);
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
    cout << "Took " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds." << endl;
}

// Expected output for this task:
// First call: 20000
// Second call: 10000
// Third call: 20000
// Fourth call: 20000

void task3() {
    Board board{SCORE_PRESET};
    if (BOARD_SIZE < 3) {
        cout << "Board is too small." << endl;
        return;
    }
    board.play(BoardCoordinate{0, 0});
    board.play(BoardCoordinate{0, 1});
    board.play(BoardCoordinate{1, 0});
    board.play(BoardCoordinate{1, 1});
    cout << "First call: " << BoardHashTable::getInstance().getHashedMove(board.getID(), 3).score << endl;
    BoardHashTable::getInstance().updateTable(board.getID(), 3, BoardOptimalMove{10000, BoardCoordinate{2, 0}});
    cout << "Second call: " << BoardHashTable::getInstance().getHashedMove(board.getID(), 3).score << endl;
    cout << "Third call: " << BoardHashTable::getInstance().getHashedMove(board.getID(), 4).score << endl;
    BoardHashTable::getInstance().clearTable();
    cout << "Fourth call: " << BoardHashTable::getInstance().getHashedMove(board.getID(), 3).score << endl;
}

void task4() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Board board{SCORE_PRESET};
    cout << board;
    cout << "Score: " << board.getBoardScore() << endl;
    cout << "ID: " << board.getID() << endl;

    BoardTree tree{board};
    BoardTree* currentTreeRoot = &tree;

    while (true) {
        BoardOptimalMove optMove = currentTreeRoot->getOptimalMoveAlphaBeta(DEPTH_PRESET, -WIN_SCORE-1, WIN_SCORE+1);
        cout << "Estimated best score: " << optMove.score << endl;
        cout << "Row: " << optMove.coords.row << endl;
        cout << "Col: " << optMove.coords.col << endl;

        board.play(optMove.coords);
        currentTreeRoot = currentTreeRoot->getSubTree(optMove.coords);
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
    cout << "Took " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds." << endl;
}

int main() {
    if (pow(BOARD_SIZE * BOARD_SIZE, DEPTH_PRESET) > 1e10) {
        cout << "WARNING: High search depth can use up a large amount of memory and will likely crash your computer. Aborting." << endl;
        return 0;
    }
    int TASK;
    do {
        cout << "Select a task number from 1 to 4." << endl;
        cin >> TASK;
    } while (TASK < 0 || TASK > 4);
    switch (TASK) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        default:
            break;
    }
}