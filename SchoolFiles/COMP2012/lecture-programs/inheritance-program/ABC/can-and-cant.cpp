#include <string>       /* File: can-and-cant.cpp */
using namespace std;

#include "personal-asset-abc.h"
#include "bank-acc-asset.h"

Personal_Asset x("20010/01/01");      // Error: can't create ABC object
Personal_Asset f1(int x) { /* .. */ } // Error: can't return ABC object
int f2(Personal_Asset x) { /* .. */ } // Error: can't CBV with ABC object

Bank_Acc_Asset b("01/01/2000", 0.0);  // OK!
Personal_Asset* p_asset_ptr = &b;     // OK!
Personal_Asset& p_asset_ref = b;      // OK!

Personal_Asset* f3(const Personal_Asset& x) { /* incomplete */ } // OK!



