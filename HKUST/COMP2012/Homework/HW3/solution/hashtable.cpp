#include "hashtable.h"

BoardOptimalMove BoardHashTable::getHashedMove(const unsigned long long id, const int depth)
{
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

void BoardHashTable::updateTable(const unsigned long long id, const int depth, const BoardOptimalMove &optimalMove)
{
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

void BoardHashTable::clearTable()
{
    for (int i=0; i<TABLE_SIZE; ++i) {
        BoardHashNode* current = table[i];
        while (current != nullptr) {
            BoardHashNode* temp = current->next;
            delete current;
            current = temp;
        }
        table[i] = nullptr;
    }
}
