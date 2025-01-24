int main()              /* File: delete.cpp */
{
    Stack* p = new Stack(9); // A dynamically allocated stack object
    int* q = new int [100];  // A dynamically allocated array of int
    delete p;           // delete an object
    delete [] q;        // delete an array of objects
    p = nullptr;        // It is a good practice to set a pointer
    q = nullptr;        // to nullptr when it doesn't point to anything
    ...
    return 0;
}
