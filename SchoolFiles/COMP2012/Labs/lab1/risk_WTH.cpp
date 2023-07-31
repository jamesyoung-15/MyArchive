/*  File: risk_WTH.cpp  */
#include "risk_WTH.h"
#include "extern.h"

int get_risk_level(char gender, int age)
{
    float waist, hip, value_WTH;
    int level;

    cout << "Please measure your waist and enter the number in centimeters (cm): ";
    cin >> waist;
    cout << "Please measure your hip and enter the number in centimeters (cm): ";
    cin >> hip;
    value_WTH = waist / hip;

    if (gender=='F') {
        if (value_WTH < FEMALE_THRESHOLD1) {
            level = LOW;
        } else if (value_WTH <= FEMALE_THRESHOLD2) {
            level = MODERATE;
        } else {
            level = HIGH;
        }
    }
    else if (gender=='M') {
        if (value_WTH < MALE_THRESHOLD1) {
            level = LOW;
        } else if (value_WTH <= MALE_THRESHOLD2) {
            level = MODERATE;
        } else {
            level = HIGH;
        }
    }

    if (age < 16)
        cout << "*** Note: This test does not work well for people of age under 16" << endl;
    cout.precision(2);
    cout << "*** Your " << TEST_NAME << " is " << value_WTH << endl;
    cout << "*** Your body shape is " << BODY_SHAPE[level] << endl;

    return level;
}
