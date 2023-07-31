/* File: course.cpp */
#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>
#include <cctype>
#include "course.h" 

/* Constructors */
// Default constructor
Course::Course() = default;

// Conversion constructor
Course::Course(const string& s) { 
    set_code(s);
}

/* Accessor */
// Gets the course code
string Course::get_code() const {
    return code;
}

/* Mutator */
// Sets the course code if it is valid
void Course::set_code(const string& s) { 
    if (s.length() != 8) {
        cerr << "Error: a course code must be 4 alphabets plus 4 digits!" << endl;
        exit(-1);
    }
    for (int i=0; i<s.length(); ++i) {
        if ( ((i <= 3) && (!isalpha(s[i]))) || ((i > 3) && (!isdigit(s[i]))) ) {
            cerr << "Error: a course code must be 4 alphabets plus 4 digits!" << endl;
            exit(-1);  
        }
        code.push_back(toupper(s[i]));
    }
}

// global output operator
ostream& operator<<(ostream& os, const Course& c) {
    os << c.get_code();
    return os;
}


/*** DO NOT MODIFY THE CODE ABOVE ***/
/*** ADD YOUR CODE BELOW ***/


// TODO #4: Implement the Smaller-Than Operator <
// Checks whether the course code is smaller than the other course code 
bool Course::operator<(const Course& other) const
{
    if(this->get_code()>other.get_code())
        return false;
    return true;
}

// TODO #5: Implement the Larger-Than Operator >
// Checks whether the course code is larger than the other course code 
bool Course::operator>(const Course& other) const
{
    if(this->get_code()>other.get_code())
        return true;
    return false;
}

// TODO #6: Implement the Equal-To Operator ==
// Checks whether the two courses are with the same course code
bool Course::operator==(const Course& other) const
{
    if(this->get_code()==other.get_code())
        return true;
    return false;
}

// TODO #7: Implement the Not-Equal-To Operator !=
// Checks whether the two courses are with different course code
bool Course::operator!=(const Course& other) const
{
    if(this->get_code()==other.get_code())
        return false;
    return true;
}

// TODO #8: Implement the Global Input Operator >>
// Get the input value for the course code
istream& operator>>(istream& is, Course& c)
{
    string code;
    is>>code;
    c.set_code(code);
    return is;
}