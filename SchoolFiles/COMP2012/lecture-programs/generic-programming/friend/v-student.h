#ifndef V_STUDENT_H     /* File: v-student.h */
#define V_STUDENT_H
#include "course.h"
#include "v-uperson.h"

class Student : public UPerson
{ 
    // No forward declaration of class Hacker is needed
    friend class Hacker; // Got a Hacker friend! Good luck!

  private:
    float GPA; Course* enrolled[50]; int num_courses;

  public:
    Student(string n, Department d, float x) :
        UPerson(n, d), GPA(x), num_courses(0) { }

    ~Student()
        { for (int j = 0; j < num_courses; ++j) delete enrolled[j]; }

    bool add_course(const string& s) 
        { enrolled[num_courses++] = new Course(s); return true; };

    virtual void print() const
    {
        cout << "--- Student Details --- \n"
             << "Name: " << get_name()
             << "\nDept: " << get_department()
             << "\nGPA: " << GPA
             << "\n" << num_courses << " Enrolled courses: ";

        for (int j = 0; j < num_courses; ++j)
           { enrolled[j]->print(); cout << ' '; }

        cout << endl;
    }
};

#endif  // V_STUDENT_H
