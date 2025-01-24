void f()
{
    // x, y are local variables
    // on the runtime stack
    int x = 4;	
    Word y {"Titanic"};

    // p is another local variable 
    // on the runtime stack.
    // But the array of 100 int's 
    // that p points to
    // is on the heap
    int* p = new int [100];
}
