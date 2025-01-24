#include <iostream>
using namespace std;

#include "board.h"
#include "boardtree.h"
#include "hashtable.h"

void task1(const int score[BOARD_SIZE][BOARD_SIZE]) {
    cout << "Score grid:" << endl;
    printBoard<const int, int>(cout, score, [](int x)->int {return x;});

    Board board{score};
    cout << board;
    cout << "Score: " << board.getBoardScore() << endl;
    cout << "ID: " << board.getID() << endl;

    while (true) {
        int row, col;
        do {
            cout << "Select a row from 0 to " << BOARD_SIZE - 1 << " (top to bottom)." << endl;
            cin >> row;
        } while (row < -1 || row >= BOARD_SIZE);
        if (row == -1) break;
        do {
            cout << "Select a column from 0 to " << BOARD_SIZE - 1 << " (left to right)." << endl;
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
    }
}

void task24(const int score[BOARD_SIZE][BOARD_SIZE], const int depth, const bool alphabeta) {
    cout << "Score grid:" << endl;
    printBoard<const int, int>(cout, score, [](int x)->int {return x;});

    cout << "Search depth: " << depth << endl;

    Board board{score};
    cout << board;
    cout << "Score: " << board.getBoardScore() << endl;
    cout << "ID: " << board.getID() << endl;

    BoardTree tree{board};
    BoardTree* currentTreeRoot = &tree;

    while (true) {
        BoardOptimalMove optMove = alphabeta ? currentTreeRoot->getOptimalMoveAlphaBeta(depth, -WIN_SCORE-1, WIN_SCORE+1) : currentTreeRoot->getOptimalMove(depth);
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
}

int main(int argc, char* argv[]) {
    cout << boolalpha;
    cout << "Configured board size: " << BOARD_SIZE << endl;

    bool scoreInput = false;
    int score[BOARD_SIZE][BOARD_SIZE];
    int searchDepth = -1;

    for (int i=1; i<argc; i++) {
        // If manual scoreboard input is enabled
        if (string(argv[i]) == "-s" || string(argv[i]) == "--score") {
            scoreInput = true;
        }
        // Depth specification
        else if (string(argv[i]) == "-d" || string(argv[i]) == "--depth") {
            if (i == argc - 1) {
                cout << "Invalid command line argument. Type .\\pa3.exe -h or .\\pa3.exe --help for details." << endl;
                return 0;
            }
            searchDepth = atoi(argv[++i]);
        }
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

    if (searchDepth <= 0) {
        searchDepth = DEPTH_PRESET;
    }
    
    int TASK, TEST;
    cout << "Select a task number from 1 to 4." << endl;
    cin >> TASK;

    switch (TASK) {
        case 1:
        {
            cout << "Testing task 1: Board class" << endl;
            cout << "Select a test case number." << endl;
            cin >> TEST;
            switch (TEST) {
                case 1:
                {
                    cout << "Test case 1: Board constructor" << endl;
                    Board board{score};
                    cout << board;
                    for (int j=0; j<BOARD_SIZE; ++j) {
                        cout << "====";
                        if (j == BOARD_SIZE - 1) cout << "=";
                    }
                    cout << endl;
                    for (int i=0; i<BOARD_SIZE; ++i) {
                        cout << "| ";
                        for (int j=0; j<BOARD_SIZE; ++j) {
                            cout << board.getScoreGrid(i, j);
                            if (j != BOARD_SIZE - 1) cout << " | ";
                        }
                        cout << " |" << endl;
                        for (int j=0; j<BOARD_SIZE; ++j) {
                            cout << "====";
                            if (j == BOARD_SIZE - 1) cout << "=";
                        }
                        cout << endl;
                    }
                    cout << "Current player: " << cell2chr(board.getCurPlayer()) << endl;
                    cout << "ID: " << board.getID() << endl;
                }
                    break;
                case 2:
                {
                    cout << "Test case 2: isFull()" << endl;
                    Board board{score};
                    for (int i=0; i<BOARD_SIZE; ++i) {
                        for (int j=0; j<BOARD_SIZE; ++j) {
                            if (i == j && j == 1) continue;
                            board.setCell(i, j, static_cast<Cell>(((i + j) % 2) * 2 - 1));
                        }
                    }
                    cout << board;
                    cout << "isFull(): " << board.isFull() << endl;
                    
                    board.setCell(1, 1, X);
                    cout << board;
                    cout << "isFull(): " << board.isFull() << endl;
                }
                    break;
                case 3:
                {
                    cout << "Test case 3: isFinished()" << endl;
                    Board board1{score};
                    int k = 0;
                    for (int i=0; i<BOARD_SIZE; ++i) {
                        for (int j=0; j<BOARD_SIZE; ++j) {
                            if (i == j && j == 1) continue;
                            board1.setCell(i, j, static_cast<Cell>((k++ % 2) * 2 - 1));
                        }
                    }
                    cout << board1;
                    cout << "isFinished(): " << board1.isFinished() << endl;
                    
                    board1.setCell(1, 1, X);
                    cout << board1;
                    cout << "isFinished(): " << board1.isFinished() << endl;

                    Board board2{score};
                    board2.setCell(0, 0, X); board2.setCell(0, 1, O); board2.setCell(1, 1, X); board2.setCell(1, 2, O); board2.setCell(2, 2, X);
                    cout << board2;
                    cout << "isFinished(): " << board2.isFinished() << endl;
                }
                    break;
                case 4:
                {
                    cout << "Test case 4: getBoardScore()" << endl;
                    Board board1{score};
                    int k = 0;
                    for (int i=0; i<BOARD_SIZE; ++i) {
                        for (int j=0; j<BOARD_SIZE; ++j) {
                            if (i == j && j == 1) continue;
                            board1.setCell(i, j, static_cast<Cell>((k++ % 2) * 2 - 1));
                        }
                    }
                    cout << board1;
                    cout << "Score: " << board1.getBoardScore() << endl;

                    Board board2{score};
                    board2.setCell(2, 2, X); board2.setCell(0, 2, O); board2.setCell(0, 1, X); board2.setCell(1, 1, O); board2.setCell(1, 2, X); board2.setCell(2, 0, O);
                    cout << board2;
                    cout << "Score: " << board2.getBoardScore() << endl;
                }
                    break;
                case 5:
                {
                    cout << "Test case 5: play()" << endl;
                    Board board{score};
                    cout << board;
                    cout << "Current player: " << cell2chr(board.getCurPlayer()) << endl;
                    cout << "ID: " << board.getID() << endl;

                    board.play(BoardCoordinate{0, 0});
                    cout << board;
                    cout << "Current player: " << cell2chr(board.getCurPlayer()) << endl;
                    cout << "ID: " << board.getID() << endl;

                    board.play(BoardCoordinate{1, 1});
                    cout << board;
                    cout << "Current player: " << cell2chr(board.getCurPlayer()) << endl;
                    cout << "ID: " << board.getID() << endl;

                    board.play(BoardCoordinate{1, 1});
                    cout << board;
                    cout << "Current player: " << cell2chr(board.getCurPlayer()) << endl;
                    cout << "ID: " << board.getID() << endl;
                }
                    break;
                case 6:
                {
                    cout << "Test case 6: A full game" << endl;
                    task1(score);
                }
                    break;
                default:
                    break;
            }
        }
            break;
        case 2:
        {
            cout << "Testing task 2: BoardTree class" << endl;
            cout << "Select a test case number." << endl;
            cin >> TEST;
            switch (TEST) {
                case 1:
                {
                    cout << "Test case 1: BoardTree conversion constructor & destructor" << endl;
                    Board board{score};
                    board.setCell(0, 0, X); board.setCell(0, 1, O); board.setCell(1, 1, X);
                    BoardTree tree{board};
                    cout << tree.getRoot()->board;
                }
                    break;
                case 2:
                {
                    cout << "Test case 2: getSubTree()" << endl;
                    Board board{score};
                    board.play(BoardCoordinate{1, 1});
                    BoardTree tree{board};

                    BoardTree* subtree1 = tree.getSubTree(BoardCoordinate{0, 0});
                    cout << "Subtree1 is empty: " << subtree1->isEmpty() << endl;
                    if (!subtree1->isEmpty()) cout << subtree1->getRoot()->board;

                    BoardTree* subtree2 = tree.getSubTree(BoardCoordinate{1, 1});
                    cout << "Subtree2 is empty: " << subtree2->isEmpty() << endl;
                }
                    break;
                case 3:
                {
                    cout << "Test case 3: getOptimalMove() depth 1" << endl;
                    if (BOARD_SIZE != 3) {
                        cout << "Incorrect board size for this test case." << endl;
                        break;
                    }
                    int test_score[BOARD_SIZE][BOARD_SIZE] = {
                        {-1, -1, -1},
                        {9, -1, -1},
                        {-1, -1, -1},
                    };
                    Board board{test_score};
                    BoardTree tree{board};
                    BoardOptimalMove optMove = tree.getOptimalMove(1);
                    cout << "Estimated best score: " << optMove.score << endl;
                    cout << "Row: " << optMove.coords.row << endl;
                    cout << "Col: " << optMove.coords.col << endl;
                }
                    break;
                case 4:
                {
                    cout << "Test case 4: getOptimalMove() depth 9" << endl;
                    if (BOARD_SIZE != 3) {
                        cout << "Incorrect board size for this test case." << endl;
                        break;
                    }
                    int test_score[BOARD_SIZE][BOARD_SIZE] = {
                        {-1, -1, -1},
                        {9, -1, -1},
                        {-1, -1, -1},
                    };
                    Board board{test_score};
                    BoardTree tree{board};
                    BoardOptimalMove optMove = tree.getOptimalMove(9);
                    cout << "Estimated best score: " << optMove.score << endl;
                    cout << "Row: " << optMove.coords.row << endl;
                    cout << "Col: " << optMove.coords.col << endl;
                }
                    break;
                case 5:
                {
                    cout << "Test case 5: getOptimalMove() partially filled board v1" << endl;
                    if (BOARD_SIZE != 3) {
                        cout << "Incorrect board size for this test case." << endl;
                        break;
                    }
                    int test_score[BOARD_SIZE][BOARD_SIZE] = {
                        {1, 1, -100},
                        {1, 1, 1},
                        {1, 1, 1},
                    };
                    Board board{test_score};
                    board.play(BoardCoordinate{0, 0});
                    board.play(BoardCoordinate{1, 1});
                    board.play(BoardCoordinate{0, 1});
                    BoardTree tree{board};
                    BoardOptimalMove optMove = tree.getOptimalMove(3);
                    cout << "Estimated best score: " << optMove.score << endl;
                    cout << "Row: " << optMove.coords.row << endl;
                    cout << "Col: " << optMove.coords.col << endl;
                }
                    break;
                case 6:
                {
                    cout << "Test case 6: getOptimalMove() partially filled board v2" << endl;
                    if (BOARD_SIZE != 3) {
                        cout << "Incorrect board size for this test case." << endl;
                        break;
                    }
                    int test_score[BOARD_SIZE][BOARD_SIZE] = {
                        {1, 1, -100},
                        {1, 1, 1},
                        {1, 1, 100},
                    };
                    Board board{test_score};
                    board.play(BoardCoordinate{0, 0});
                    board.play(BoardCoordinate{1, 1});
                    board.play(BoardCoordinate{0, 1});
                    board.play(BoardCoordinate{2, 2});
                    BoardTree tree{board};
                    BoardOptimalMove optMove = tree.getOptimalMove(3);
                    cout << "Estimated best score: " << optMove.score << endl;
                    cout << "Row: " << optMove.coords.row << endl;
                    cout << "Col: " << optMove.coords.col << endl;
                }
                    break;
                case 7:
                {
                    cout << "Test case 7: getOptimalMove() partially filled board v3" << endl;
                    if (BOARD_SIZE != 3) {
                        cout << "Incorrect board size for this test case." << endl;
                        break;
                    }
                    int test_score[BOARD_SIZE][BOARD_SIZE] = {
                        {1, 1, -100},
                        {1, 100, 1},
                        {1, 1, 1},
                    };
                    Board board{test_score};
                    board.play(BoardCoordinate{0, 0});
                    board.play(BoardCoordinate{2, 0});
                    board.play(BoardCoordinate{1, 0});
                    board.play(BoardCoordinate{2, 2});
                    board.play(BoardCoordinate{2, 1});
                    BoardTree tree{board};
                    BoardOptimalMove optMove = tree.getOptimalMove(3);
                    cout << "Estimated best score: " << optMove.score << endl;
                    cout << "Row: " << optMove.coords.row << endl;
                    cout << "Col: " << optMove.coords.col << endl;
                }
                    break;
                case 8:
                {
                    cout << "Test case 8: A full game" << endl;
                    task24(score, searchDepth, false);
                }
                    break;
                default:
                    break;
            }
        }
            break;
        case 3:
        {
            cout << "Testing task 3: BoardHashTable class" << endl;
            if (TABLE_SIZE != 101) {
                cout << "Incorrect board size for this test case." << endl;
                break;
            }

            BoardHashTable::getInstance().updateTableSolution(1001, 3, BoardOptimalMove{10, BoardCoordinate{0, 1}});
            BoardHashTable::getInstance().updateTableSolution(2011, 4, BoardOptimalMove{-10, BoardCoordinate{1, 1}});
            BoardHashTable::getInstance().updateTableSolution(1506, 2, BoardOptimalMove{0, BoardCoordinate{2, 1}});
            BoardHashTable::getInstance().updateTableSolution(1017, 3, BoardOptimalMove{20, BoardCoordinate{1, 1}});
            BoardHashTable::getInstance().updateTableSolution(1563, 1, BoardOptimalMove{10000, BoardCoordinate{0, 2}});
            BoardHashTable::getInstance().updateTableSolution(1159, 4, BoardOptimalMove{-30, BoardCoordinate{0, 0}});

            cout << "Select a test case number." << endl;
            cin >> TEST;
            switch (TEST) {
                case 1:
                {
                    cout << "Test case 1: getHashedMove() with empty hash slot" << endl;
                    cout << "Hashed score 1: " << BoardHashTable::getInstance().getHashedMove(1025, 3).score << endl;
                    cout << "Hashed score 2: " << BoardHashTable::getInstance().getHashedMove(3526, 3).score << endl;

                    BoardHashTable::getInstance().updateTableSolution(1025, 3, BoardOptimalMove{25, BoardCoordinate{0, 1}});
                    cout << "Hashed score with update: " << BoardHashTable::getInstance().getHashedMove(1025, 3).score << endl;
                }
                    break;
                case 2:
                {
                    cout << "Test case 2: getHashedMove() with existing ID and equal depth" << endl;
                    cout << "Hashed score: " << BoardHashTable::getInstance().getHashedMove(2011, 4).score << endl;
                }
                    break;
                case 3:
                {
                    cout << "Test case 3: getHashedMove() with existing ID and lower or higher depth" << endl;
                    cout << "Hashed score lower: " << BoardHashTable::getInstance().getHashedMove(2011, 3).score << endl;
                    cout << "Hashed score higher: " << BoardHashTable::getInstance().getHashedMove(2011, 5).score << endl;
                }
                    break;
                case 4:
                {
                    cout << "Test case 4: getHashedMove() large test" << endl;
                    for (int i = 0; i < 1000; ++i) {
                        BoardHashTable::getInstance().updateTableSolution(137 * i + 211, i % 10 + 1, BoardOptimalMove{i, BoardCoordinate{i % 3, 3 - (i % 3)}});
                    }
                    for (int j = 0; j < 10; ++j) {
                        int i = j * 100 + 13;
                        cout << "Hashed score " << j + 1 << ": " << BoardHashTable::getInstance().getHashedMove(137 * i + 211, i % 10 + 1).score << endl;
                    }
                }
                    break;
                case 5:
                {
                    cout << "Test case 5: updateTable() with non-existing hash index" << endl;
                    BoardHashTable::getInstance().updateTable(1025, 3, BoardOptimalMove{25, BoardCoordinate{0, 1}});
                    cout << "Hashed score: " << BoardHashTable::getInstance().getHashedMoveSolution(1025, 3).score << endl;
                }
                    break;
                case 6:
                {
                    cout << "Test case 6: updateTable() with non-existing ID" << endl;
                    BoardHashTable::getInstance().updateTable(3526, 3, BoardOptimalMove{35, BoardCoordinate{1, 0}});
                    cout << "Hashed score: " << BoardHashTable::getInstance().getHashedMoveSolution(3526, 3).score << endl;
                }
                    break;
                case 7:
                {
                    cout << "Test case 7: updateTable() with existing ID" << endl;
                    BoardHashTable::getInstance().updateTable(1563, 3, BoardOptimalMove{99, BoardCoordinate{0, 1}});
                    cout << "Updated score with higher depth: " << BoardHashTable::getInstance().getHashedMoveSolution(1563, 3).score << endl;

                    BoardHashTable::getInstance().updateTable(1159, 3, BoardOptimalMove{-99, BoardCoordinate{0, 1}});
                    cout << "Updated score with lower depth: " << BoardHashTable::getInstance().getHashedMoveSolution(1159, 3).score << endl;
                }
                    break;
                case 8:
                {
                    cout << "Test case 8: updateTable() multiple times" << endl;
                    BoardHashTable::getInstance().updateTable(2022, 4, BoardOptimalMove{100, BoardCoordinate{1, 2}});
                    cout << "Updated score 1: " << BoardHashTable::getInstance().getHashedMoveSolution(2022, 4).score << endl;

                    BoardHashTable::getInstance().updateTable(2022, 6, BoardOptimalMove{-100, BoardCoordinate{2, 1}});
                    cout << "Updated score 1: " << BoardHashTable::getInstance().getHashedMoveSolution(2022, 4).score << endl;
                }
                    break;
                case 9:
                {
                    cout << "Test case 9: updateTable() large test" << endl;
                    for (int i = 0; i < 1000; ++i) {
                        BoardHashTable::getInstance().updateTable(137 * i + 211, i % 10 + 1, BoardOptimalMove{i, BoardCoordinate{i % 3, 3 - (i % 3)}});
                    }
                    for (int j = 0; j < 10; ++j) {
                        int i = j * 100 + 13;
                        cout << "Hashed score " << j + 1 << ": " << BoardHashTable::getInstance().getHashedMoveSolution(137 * i + 211, i % 10 + 1).score << endl;
                    }
                }
                    break;
                case 10:
                {
                    cout << "Test case 10: clearTable()" << endl;
                    BoardHashTable::getInstance().clearTable();
                    cout << "Hashed score: " << BoardHashTable::getInstance().getHashedMoveSolution(1001, 3).score << endl;
                }
                    break;
                case 11:
                {
                    cout << "Test case 11: Hash table used in getOptimalMove()" << endl;
                    Board board{SCORE_PRESET};
                    BoardTree tree{board};
                    BoardOptimalMove optMove = tree.getOptimalMove(9);

                    cout << "Hashed score: " << BoardHashTable::getInstance().getHashedMove(0, 9).score << endl;
                }
                    break;
                default:
                    break;
            }
        }
            break;
        case 4:
        {
            cout << "Testing task 4: Alpha-beta pruning" << endl;
            cout << "Select a test case number." << endl;
            cin >> TEST;
            switch (TEST) {
                case 1:
                {
                    cout << "Test case 1: A full game" << endl;
                    task24(score, searchDepth, true);
                }
                    break;
                default:
                    break;
            }
        }
            break;
        default:
            break;
    }
}
