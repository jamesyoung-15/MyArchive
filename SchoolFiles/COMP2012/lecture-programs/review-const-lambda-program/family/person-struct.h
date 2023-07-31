#include <iostream>     /* File: struct/person.h */
using namespace std;

struct Person
{
    char* _name; int _age;
    Person *_father, *_mother, *_child; 
    Person(const char* my_name, int my_age, Person* my_father = nullptr,
           Person* my_mother = nullptr, Person* my_child = nullptr);
    ~Person();
    Person* father() const;
    Person* mother() const; 
    Person* child() const;
    void print_age() const;
    void print_name() const;
    void print_family() const;
    void have_child(Person* baby) ;
};

