/* File: teacher1.h */
enum Department { CBME, CIVL, CSE, ECE, IELM, MAE };
enum Rank { PROFESSOR, DEAN, PRESIDENT }; 

class Teacher
{
  private:
    string name;
    Department dept;
    Rank rank;
    string research_area;

  public:
    Teacher(string n, Department d, Rank r, string a) :
      name(n), dept(d), rank(r), research_area(a) { }
    string get_name() const;
    Department get_department() const;
    Rank get_rank() const;
    string get_research_area() const;
};
