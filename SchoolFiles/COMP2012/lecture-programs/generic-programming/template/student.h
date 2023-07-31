#ifndef STUDENT_H /* File: student.h */
#define STUDENT_H 
#include "uperson.h"
class Course { /* incomplete */ };
class Student : public UPerson // Public inheritance
{
  //friend ostream& operator<<(ostream& os, const Student& s) { return (os << s.get_name()); }
  private:
    float GPA;
    Course *enrolled;
    int num_courses;

  public:
    Student(string n, Department d, float x) :
        UPerson(n, d), GPA(x), enrolled(nullptr), num_courses(0) { }
    float get_GPA( ) const { return GPA; }
    bool enroll_course(const string &) { /* incomplete */ }
    bool drop_course(const Course &) { /* incomplete */ }
};
#endif
