#include "person.h"     /* File: person.cpp */
#include <cstring>

Person::Person(const char* my_name, int my_age, Person* my_father,
               Person* my_mother, Person* my_child)
{
    _name = new char [strlen(my_name)+1];
    strcpy(_name, my_name);
    _age = my_age;
    _father = my_father;
    _mother = my_mother;
    _child = my_child;
};

Person::~Person() { delete [] _name; }

Person* Person::father() const { return _father; }

Person* Person::mother() const { return _mother; }

Person* Person::child() const { return _child; }

void Person::have_child(Person* baby) { _child = baby; }

void Person::print_age() const { cout << _age; }

void Person::print_name() const
{
    cout << (_name ? _name : "unknown");
}




// Helper function
void print_parent(Person* parent)
{
    if (parent)
        parent->print_name();
    else
        cout << "unknown";
}





void Person::print_family() const
{
    Person *f_grandfather = nullptr, *f_grandmother = nullptr,
        *m_grandfather = nullptr, *m_grandmother = nullptr;

    if (_father) {
        f_grandmother = _father->mother();
        f_grandfather = _father->father();
    }

    if (_mother) {
        m_grandmother = _mother->mother(); 
        m_grandfather = _mother->father();
    }

    cout << "Name: "; print_name(); cout << endl;
    cout << "Father: "; print_parent(_father); cout << endl;
    cout << "Mother: "; print_parent(_mother); cout << endl;

    cout << "Grand Fathers: "; print_parent(f_grandfather);
    cout << ", "; print_parent(m_grandfather); cout << endl;
    cout << "Grand Mothers: "; print_parent(f_grandmother);
    cout << ", "; print_parent(m_grandmother); cout << endl;
}
