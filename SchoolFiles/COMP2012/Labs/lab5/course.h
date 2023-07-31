#ifndef _COURSE_H  /* File: course.h */
#define _COURSE_H
#include <cstring>
#include <cctype>

class Course {
  public:

    /* Constructors */
    // Default constructor
    Course();

    // Conversion constructor
    Course(const string& s);

    /* Accessor */
    // Gets the course code
    string get_code() const;

    /* Mutator */
    // Sets the course code if it is valid
    void set_code(const string& s);

    /* Operator overloading */
    // smaller-than operator: 
    // Checks whether the course code is smaller than the other course code 
    bool operator<(const Course& other) const;

    // larger-than operator: 
    // Checks whether the course code is larger than the other course code 
    bool operator>(const Course& other) const;

    // equal-to operator:
    // Checks whether the two courses are with the same course code
    bool operator==(const Course& other) const;

    // not-equal-to operator:
    // Checks whether the two courses are with different course code
    bool operator!=(const Course& other) const;

  private:
    string code;
};

// global output operator
ostream& operator<<(ostream& os, const Course& c);

// global input operator
istream& operator>>(istream& is, Course& c);

#endif
