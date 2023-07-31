#ifndef UPERSON_H       /* File: uperson.h */
#define UPERSON_H 

enum Department { CBME, CIVL, CSE, ECE, IELM, MAE };

class UPerson
{
  private:
    string name;
    Department dept;

  protected:
    void set_name(string n) { name = n; }
    void set_department(Department d) { dept = d; }

  public:
    UPerson(string n, Department d) : name(n), dept(d) { }
    string get_name() const { return name; }
    Department get_department() const { return dept; }
};
#endif
