int main()
{
    Student *s = new Student("Simpson", "Springfield", computer_sci);
    s->enroll_course("comp151");

    UPerson *p = s;
    delete p;
}
