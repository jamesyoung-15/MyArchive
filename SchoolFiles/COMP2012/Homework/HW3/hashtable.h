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
};

#endif // __HASHTABLE_H__