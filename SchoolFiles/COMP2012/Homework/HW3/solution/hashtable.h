#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "board.h"
#include "const.h"

class BoardHashTable {
    private:
        struct BoardHashNode {
            unsigned long long id;
            int depth;
            BoardOptimalMove optimalMove;
            BoardHashNode* next;

            BoardHashNode(const unsigned long long id, const int depth, const BoardOptimalMove& optimalMove): 
                id(id), depth(depth), optimalMove(optimalMove), next(nullptr) {}
        };

        BoardHashNode* table[TABLE_SIZE] {nullptr};

        BoardHashTable() = default;
        ~BoardHashTable() { clearTable(); }
    
    public:
        BoardHashTable(const BoardHashTable&) = delete;
        BoardHashTable& operator=(const BoardHashTable&) = delete;
        
        // Return the only instance of BoardHashTable
        static BoardHashTable& getInstance()
        {
            static BoardHashTable instance;
            return instance;
        }
        
        // Return the stored BoardOptimalMove for the given id and depth. If it is not stored, return "illegal" (default) BoardOptimalMove.
        BoardOptimalMove getHashedMove(const unsigned long long id, const int depth);

        // Update the table with the optimal move for the given id and depth.
        // If id does not exist, create a new linked list node at (id % TABLE_SIZE).
        // Else, if stored depth is lower, update the optimal move with the parameter. Otherwise, do nothing.
        void updateTable(const unsigned long long id, const int depth, const BoardOptimalMove& optimalMove);

        // Clear all dynamic memory and reset table array to all nullptr.
        void clearTable();

        // For testing
        void updateTableSolution(const unsigned long long id, const int depth, const BoardOptimalMove& optimalMove) {
            BoardHashNode* current = table[id % TABLE_SIZE];
            while (current != nullptr) {
                if (current->id == id) {
                    if (current->depth < depth) {
                        current->depth = depth;
                        current->optimalMove = optimalMove;
                    }
                    return;
                }
                current = current->next;
            }

            // If this is reached, the board ID has not been added to the table yet, add a new node now
            if (current == nullptr) {
                int tableIndex = id % TABLE_SIZE;
                // Add new board ID to the start of this linked list
                BoardHashNode* newNode = new BoardHashNode(id, depth, optimalMove);
                newNode->next = table[tableIndex];
                table[tableIndex] = newNode;
            }
        }

        BoardOptimalMove getHashedMoveSolution(const unsigned long long id, const int depth) {
            BoardHashNode* current = table[id % TABLE_SIZE];
            while (current != nullptr) {
                if (current->id == id) {
                    if (current->depth >= depth)
                        return current->optimalMove;
                    else
                        return BoardOptimalMove();
                }
                current = current->next;
            }
            return BoardOptimalMove();
        }
};

#endif // __HASHTABLE_H__