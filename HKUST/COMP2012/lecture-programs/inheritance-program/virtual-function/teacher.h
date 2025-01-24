#ifndef TEACHER_H /* File: teacher.h */
#define TEACHER_H
#include "uperson.h" 

enum Rank { PROFESSOR, DEAN, PRESIDENT };

class Teacher : public UPerson  // Public inheritance
{
  private:
    Rank rank;
    string research_area;

  public:
    Teacher(string n, Department d, Rank r, string a) :
        UPerson(n, d), rank(r), research_area(a) { }; 
    Rank get_rank( ) const { return rank; }
    string get_research_area( ) const { return research_area; }
    void print( ) const 
    { 
        cout << "--- Teacher Details --- \n"
             << "Name: " << get_name( ) 
			 << "\nDept: " << get_department( )
             << "\nRank: " << rank
             << "\nResearch area: " << research_area << "\n";
    } 
};
#endif
