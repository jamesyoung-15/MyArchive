int main()              /* File: dangling-reference.cpp */
{
    char* q = new char [128]; // Dynamically allocate a char buffer
    char* p = q;        // p and q now points to the same char buffer
    delete [] q;
    q = nullptr;        // delete the char buffer

    /* Now p is a dangling pointer! */
    p[0] = 'a';         // Error: possibly segmentation fault
    delete [] p;        // Error: possibly segmentation fault
    return 0;
}
