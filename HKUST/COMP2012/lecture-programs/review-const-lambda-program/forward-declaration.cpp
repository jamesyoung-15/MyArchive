class Cell;       // Forward declaration of Cell

class List
{
    int size;
    Cell* data;   // Points to a (forward-declared) Cell object
    Cell x;       // Error: Cell not defined yet!
};

class Cell        // Definition of Cell
{
    int info;
    Cell* next;
};
