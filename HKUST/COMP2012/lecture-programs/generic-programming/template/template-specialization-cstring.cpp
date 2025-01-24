#include <iostream>     /* File: template-specialization-cstring.cpp */
#include <cstring>
using namespace std;

/* General case  */
template <typename T>
const T& larger(const T& a, const T& b)
    { cout << "general case: "; return (a < b) ? b : a; }

/* Exceptional case  */
template <>
const char* const& larger(const char* const& a, const char* const& b)
    { cout << "special case: "; return (strcmp(a, b) < 0) ? b : a; }

int main()
{
    const char* m = "microsoft"; // Smaller address
    const char* a = "apple";     // Bigger address

    cout << larger(a, m) << " is better!" << endl;
    cout << larger(m, a) << " is better!" << endl;
    cout << larger(22, 88) << " is greater!" << endl;
    return 0;
}
