#ifndef PG_STUDENT_H    /* File: v-pg-student.h */
#define PG_STUDENT_H

class PG_Student : public Student
{
  private:
    string research_topic;

  public:
    PG_Student(string n, Department d, float x) :
        Student(n, d, x), research_topic("") { }

    string get_topic() const { return research_topic; }
    void set_topic(const string& x) { research_topic = x; }
    virtual void print() const override {
        cout << "--- PG Student Details --- \n"
             << "research topic: " << research_topic << endl;
        Student::print();
    }
};
#endif
