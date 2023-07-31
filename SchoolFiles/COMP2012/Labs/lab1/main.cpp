/*  File: main.cpp  */
#include "health_check.h"
#include "global.h"

int main()
{
    char gender;
    int age;
    int level;

    cout << "Welcome to Health Check" << endl;
    cout << "Please enter F if you are a female, M if you are a male: ";
    cin >> gender;
    cout << "Please enter your age: ";
    cin >> age;
    level = get_risk_level(gender, age);
    cout << "*** Your level of health risk is " << RISK_LEVEL[level] << endl;
    
    return 0;
}