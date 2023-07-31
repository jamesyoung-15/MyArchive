#ifndef STUDENT_H       /* File: student.h */
#define STUDENT_H 

#include "uperson.h"
class Course { /* incomplete */ };

class Student : ??? UPerson // ??? = public/protected/private
{
  private:
    float GPA;
    Course* enrolled;
    int num_courses;

  public:
    Student(string n, Department d, float x) :
        UPerson(n, d), GPA(x), enrolled(nullptr), num_courses(0) { }
    float get_GPA() const { return GPA; }
    bool enroll_course(const string& c) { /* incomplete */ };
    bool drop_course(const Course& c) { /* incomplete */ };
};
#endif
