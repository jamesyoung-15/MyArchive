int main()              /* File: memory-leak.cpp */
{
    for (int j = 1; j <= 10000; j++) 
    {
        int* snoopy = new int [100];
        int* vampire = new int [100];
        snoopy = vampire; // Now snoopy becomes vampire
        ...               // Where is the old snoopy?
    }
    
    return 0;
}
