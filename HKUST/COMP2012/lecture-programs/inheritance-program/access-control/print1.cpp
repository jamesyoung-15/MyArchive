/* File: print1.cpp */

class UPerson { public: void print() const; ...  };

class Student: public UPerson { public: void print() const; ...  };

void UPerson::print() const
{
    cout << "--- UPerson details ---" << endl;
    cout << "Name: " << name << endl << "\nDept: " << dept << endl;
}

void Student::print() const 
{
    cout << "--- Student details ---" << endl
         << "Name: " << name << endl
         << "\nDept: " << dept << endl << "Enrolled in:" << endl;
    for (int i = 0; i < num_courses; i++) 
        enrolled[i].print(); // Assume a print function in Course
}
