#ifndef V_UPERSON_H /* File: v-uperson.h */
#define V_UPERSON_H 

enum Department { CBME, CIVL, CSE, ECE, IELM, MAE };
class UPerson
{
  private:
    string name;
    Department dept;

  public:
    UPerson(string n, Department d) : name(n), dept(d) { };
    string get_name( ) const { return name; }
    Department get_department( ) const { return dept; }
    virtual void print( ) const 
    { 
        cout << "--- UPerson Details --- \n"
             << "Name: " << name << "\nDept: " << dept << "\n";
    }
};
#endif
