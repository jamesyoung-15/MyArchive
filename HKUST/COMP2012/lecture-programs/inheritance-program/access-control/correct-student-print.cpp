void Student::print() const /* correct-student-print.cpp */
{
    cout << "--- Student details ---" << endl
         << "Name: " << get_name() << endl  // Use UPerson's public fcn
         << "Dept: " << get_dept() << endl  // Use UPerson's public fcn
         << "Enrolled in:" << endl;

    for (int i = 0; i < num_courses; i++) 
        enrolled[i].print();                // Use Course's public fcn
}
