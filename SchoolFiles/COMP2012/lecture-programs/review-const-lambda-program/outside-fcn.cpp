/* File: person.h */
class Person
{   ...
    Person* child() const;
    void have_child(Person* baby);
};

/* File: person.cpp */
Person* Person::child() const { return _child; }
void Person::have_child(Person* baby) { _child = baby; }
