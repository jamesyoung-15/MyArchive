class UPerson           /* File: protected-uperson.h */
{
  protected:
    string name;
    Department dept;

  public:
    UPerson(string n, Department d) : name(n), dept(d) { };
    void print() const;
    ...
};
