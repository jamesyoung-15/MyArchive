#include "hashtable.h"
#include "board.h"
#include "const.h"
#include <functional>


/*
 Returns the BoardOptimalMove stored in the hash table for the given board ID and search depth. 
 If the board ID does not exist in the table, or the ID is stored but the search depth is lower than the parameter, then return an illegal move 
 indicating that the table does not contain the queried board ID or the stored calculation is not sufficient 
 (if the search depth parameter is equal to or lower than the stored search depth, return the stored move). 
*/
BoardOptimalMove BoardHashTable::getHashedMove(const unsigned long long id, const int depth)
{
    // table index
    int tempIndex = id % TABLE_SIZE; 
    // default constructor, illegal move
    BoardOptimalMove hashedMove;
    
    /* Loop through linked list at table index and search, return if matches requirements */
    BoardHashNode* temp = table[tempIndex];
    while(temp!=nullptr)
    {
        if(temp->depth>= depth && temp->id==id)
        {
            return temp->optimalMove;
        }
        temp = temp->next;
    }
    
    // otherwise return illegal
    return hashedMove;
}
/*
Updates the table with the optimal move for the given board ID and search depth. 
If the board ID does not exist in the table, create a new node at the corresponding linked list 
(the node can be inserted anywhere in the list). Otherwise, if the stored depth of the board ID is lower than the depth parameter, 
update the node's depth and optimalMove. 
*/
void BoardHashTable::updateTable(const unsigned long long id, const int depth, const BoardOptimalMove &optimalMove)
{
    // table index
	int tempIndex = id % TABLE_SIZE;
    
    /*  if talbe index is empty, build head */
    if(table[tempIndex]==nullptr)
    {
        // printf("Create head node\n");
        table[tempIndex] = new BoardHashNode(id,depth,optimalMove);
        return;
    }

    /* otherwise add to end of linked list */ 
    // build temp node
    BoardHashNode* temp = table[tempIndex];
    // loop till end of linked list, add to end
	while (temp != nullptr) 
    {
        // if id exists, check if search depth is greater than stored 
        // and update table if it is otherwise exit
		if (temp->id == id) 
        {
            // printf("found at %i \n", tempIndex);
            if(temp->depth < depth)
            {
                // printf("update at %i\n", tempIndex);
                temp->optimalMove = optimalMove;
                temp->depth = depth;
            }
            return;
		}
        // if at the last node, build new node and link it to last node tail
        if(temp->next==nullptr)
        {
            // printf("Reached end node");
            temp->next = new BoardHashNode(id, depth, optimalMove);
            return;
        }
		temp = temp->next;
	}


}


//  Free all dynamic memories in the hash table and reset the linked lists to nullptr. 
void BoardHashTable::clearTable()
{
    // printf("D Called\n");
    // Loop through entire table
    for(int i=0;i<TABLE_SIZE;i++)
    {
        // for each index, go through linked list, delete each node
        while(table[i]!=nullptr)
        {
            BoardHashNode* temp = table[i];
            table[i] = temp->next;
            delete temp;
            temp = nullptr;
        }
        // reset to nullptr
        table[i] = nullptr;
    }
}