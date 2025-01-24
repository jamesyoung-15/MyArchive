#include <iostream>
using namespace std;
class A
{
    public:
        void nonConstMemFunc() { }
        void constMemFunc() const { }
        const A getConstObj() { return *this; }
        const A& getConstRefObj() { return *this; }
};
int main()
{
    const A constObj;
    constObj.nonConstMemFunc(); // Error: Yes
    constObj.constMemFunc(); // Error: No
    A nonConstObj;
    A nonConstObj2 = nonConstObj.getConstObj(); // Error: No
    A nonConstObj3 = nonConstObj.getConstRefObj(); // Error: No
    A& nonConstRefObj1 = nonConstObj.getConstObj(); // Error: Yes
    A& nonConstRefObj2 = nonConstObj.getConstRefObj(); // Error: Yes
    const A constObj2 = nonConstObj.getConstObj(); // Error: No
    const A constObj3 = nonConstObj.getConstRefObj(); // Error: No
    const A& constRefObj1 = nonConstObj.getConstObj(); // Error: No
    const A& constRefObj2 = nonConstObj.getConstRefObj(); // Error: No
    A& const mystery = nonConstObj.getConstObj(); // Error: Yes
    return 0;
}