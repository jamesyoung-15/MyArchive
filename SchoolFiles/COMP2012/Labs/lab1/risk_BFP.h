#ifndef RISK_BFP_H
#define RISK_BFP_H

/*  File: risk_BFP.h    */

#include <iostream>
using namespace std;

/* Constant definitions */
const char* TEST_NAME = "BFP (Body Fat Percentage)";
const float MALE_THRESHOLD1 = 8.0;
const float MALE_THRESHOLD2 = 19.0;
const float MALE_THRESHOLD3 = 25.0;
const float FEMALE_THRESHOLD1 = 21.0;
const float FEMALE_THRESHOLD2 = 33.0;
const float FEMALE_THRESHOLD3 = 39.0;

const int UNDERWEIGHT = 0;
const int NORMAL = 1;
const int OVERWEIGHT = 2;
const int OBESE = 3;

const char* BFP_CATEGORY[4] 
    = { "UNDERWEIGHT", "NORMAL", "OVERWEIGHT", "OBESE" };

#endif