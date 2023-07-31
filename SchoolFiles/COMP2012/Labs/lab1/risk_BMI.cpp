/*  File: risk_BMI.cpp  */

#include "risk_BMI.h"
#include "extern.h"

int get_risk_level(char gender, int age)
{
    float weight, height, value_BMI;
    int category, level;

    cout << "Please measure your weight and enter the number in kilograms (kg): ";
    cin >> weight;
    cout << "Please measure your height and enter the number in meters (m): ";
    cin >> height;
    value_BMI = weight / height / height;

    if (value_BMI < THRESHOLD1) {
        category = UNDERWEIGHT;
        level = MODERATE;
    } else if (value_BMI < THRESHOLD2) {
        category = NORMAL;
        level = LOW;
    } else if (value_BMI <= THRESHOLD3) {
        category = OVERWEIGHT;
        level = MODERATE;
    } else {
        category = OBESE;
        level = HIGH;
    }

    cout.precision(4);
    cout << "*** Your " << TEST_NAME << " is " << value_BMI << endl;
    cout << "*** Your category is " << BMI_CATEGORY[category] << endl;

    return level;
}