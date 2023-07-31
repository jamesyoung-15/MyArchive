void Teacher::print() const /* correct-teacher-print.cpp */
{
    cout << "--- Teacher details ---" << endl
         << "Name: " << get_name() << endl  // Use UPerson's public fcn
         << "Dept: " << get_dept() << endl  // Use UPerson's public fcn
         << "Rank: " << get_rank() << endl; // Use its own fcn
}
