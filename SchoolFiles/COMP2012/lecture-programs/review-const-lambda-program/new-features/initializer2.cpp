#include <iostream>     /* File: initializer2.cpp */
using namespace std;	

int main()	
{
    const char s1[] = "Steve Jobs";
    const char s2[] {"Bill Gates"};
    const char s3[] = {'h', 'k', 'u', 's', 't', '\0'};
    const char s4[] {'h', 'k', 'u', 's', 't', '\0'};

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    return 0;
}
