#ifndef STUDENT_H /* File: student.h */
#define STUDENT_H 
#include "uperson.h"
class Course { 
    string course; 
  public:  
    void print( ) const { cout << course; }
};

class Student : public UPerson // Public inheritance
{
  private:
    float GPA;
    Course enrolled[50];
    int num_courses;

  public:
    Student(string n, Department d, float x) :
        UPerson(n, d), GPA(x), num_courses(0) { }
    float get_GPA( ) const { return GPA; }
    bool add_course(const string &) { /* incomplete */ };
    void print( ) const 
    { 
        cout << "--- Student Details --- \n"
             << "Name: " << get_name( ) << "\nDept: " 
			 << get_department( ) << "\n"
             << num_courses << " Enrolled courses: ";
        for (int j = 0; j < num_courses; ++j)
        { enrolled[j].print( ); cout << ' '; }
        cout << "\n";
    }   
};
#endif
