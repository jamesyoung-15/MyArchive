#ifndef HEALTH_CHECK_H
#define HEALTH_CHECK_H

/*  File: health_check.h    */

#include <iostream>
using namespace std;

/* Constant definitions */
const char* RISK_LEVEL[3] 
    = { "LOW", "MODERATE", "HIGH" };

/* External function declarations   */
extern int get_risk_level(char, int);

#endif