/*  File: risk_BFP.cpp  */

#include "risk_BFP.h"
#include "extern.h"

int get_risk_level(char gender, int age)
{
    float weight, height;
    float value_BMI, value_BFP;
    int category, level;

    cout << "Please measure your weight and enter the number in kilograms (kg): ";
    cin >> weight;
    cout << "Please measure your height and enter the number in meters (m): ";
    cin >> height;
    value_BMI = (float) weight / height / height;
    value_BFP = value_BMI * 1.2 + age * 0.23;

    if (gender=='F') {
        value_BFP = value_BFP - 5.4;
        if (value_BFP < FEMALE_THRESHOLD1) {
            category = UNDERWEIGHT;
            level = MODERATE;
        } else if (value_BFP < FEMALE_THRESHOLD2) {
            category = NORMAL;
            level = LOW;
        } else if (value_BFP <= FEMALE_THRESHOLD3) {
            category = OVERWEIGHT;
            level = MODERATE;
        } else {
            category = OBESE;
            level = HIGH;
        }
    } else if (gender=='M') {
        value_BFP = value_BFP - 16.2;
        if (value_BFP < MALE_THRESHOLD1) {
            category = UNDERWEIGHT;
            level = MODERATE;
        } else if (value_BFP < MALE_THRESHOLD2) {
            category = NORMAL;
            level = LOW;
        } else if (value_BFP <= MALE_THRESHOLD3) {
            category = OVERWEIGHT;
            level = MODERATE;
        } else {
            category = OBESE;
            level = HIGH;
        }
    }

    if ((age < 20) or (age > 79))
        cout << "*** Note: This test does not work well for people of age under 20 or over 79" << endl;
    cout.precision(4);
    cout << "*** Your " << TEST_NAME << " is " << value_BFP << "%" << endl;
    cout << "*** Your category is " << BFP_CATEGORY[category] << endl;

    return level;
}
