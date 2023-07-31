#ifndef PG_STUDENT_H    /* File: pg-student.h */
#define PG_STUDENT_H

#include "student.h" 

class PG_Student : public Student
{
  private:
    string research_topic;

  public:
    PG_Student(string n, Department d, float x) :
        Student(n, d, x), research_topic("") { }

    string get_topic() const { return research_topic; }
    void set_topic(const string& x) { research_topic = x; }
};

#endif
