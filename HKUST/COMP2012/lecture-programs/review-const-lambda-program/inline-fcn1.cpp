class Person
{   ...
    Person* child() const { return _child; }
    void have_child(Person* baby) { _child = baby; }
};
