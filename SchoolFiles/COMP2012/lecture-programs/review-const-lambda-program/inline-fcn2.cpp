class Person
{   ...
    inline Person* child() const { return _child; }
    inline void have_child(Person* baby) { _child = baby; }
};
