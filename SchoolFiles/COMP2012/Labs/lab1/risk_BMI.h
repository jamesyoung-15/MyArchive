#ifndef RISK_BMI_H
#define RISK_BMI_H

/*  File: risk_BMI.h    */

#include <iostream>
using namespace std;

/* Constant definitions */
const char* TEST_NAME = "BMI (Body Mass Index)";
const float THRESHOLD1 = 18.5;
const float THRESHOLD2 = 25.0;
const float THRESHOLD3 = 40.0;

const int UNDERWEIGHT = 0;
const int NORMAL = 1;
const int OVERWEIGHT = 2;
const int OBESE = 3;

const char* BMI_CATEGORY[4] 
    = { "UNDERWEIGHT", "NORMAL", "OVERWEIGHT", "OBESE" };

#endif