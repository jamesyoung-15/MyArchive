#ifndef COURSE_H /* File: course.h */
#define COURSE_H 

class Course 
{
  private:
    string code;

  public:
    Course(const string& s) : code(s) { }
    ~Course( ) { cout << "destruct course: " << code << endl; }
    void print( ) const { cout << code; }
};
#endif
