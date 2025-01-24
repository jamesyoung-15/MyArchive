/* File: person.h */
class Person
{   ...
    inline Person* child() const;
    inline void have_child(Person* baby);
};

inline Person* Person::child() const { return _child; }
inline void Person::have_child(Person* baby) { _child = baby; }
