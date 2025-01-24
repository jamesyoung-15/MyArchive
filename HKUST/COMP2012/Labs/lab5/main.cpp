#include <iostream>  /* File: main.cpp */
#include <fstream>
using namespace std;
#include "course.h"
#include "sortedArray.h"

const int MAX_SIZE = 10;

// Read objects
template <typename T>
void readArray(T arr[], int &size) {
    cout << "Enter the number of elements: ";
    cin >> size; 
    for (int i=0; i<size; ++i) 
        cin >> arr[i];
}

// Process 2 SortedArray objects
template <typename T, int SIZE, bool ORDER>
void checkSortedArrays(const SortedArray<T, SIZE, ORDER>& arr1, const SortedArray<T, SIZE, ORDER>& arr2) {
    cout << "Is " << arr1 << " equal to " << arr2 << "? ";
    cout << ((arr1 == arr2) ? "Yes" : "No") << endl; 
    // Add 2 SortedArray objects
    cout << arr1 << " + " << arr2 << " = " << arr1 + arr2 << endl;
    cout << arr2 << " + " << arr1 << " = " << arr2 + arr1 << endl;
}

int main() {

    int option = 0;
    while (option != -1) {
        cout << "Option 1: Integer sequences\n";
        cout << "Option 2: Course sequences\n"; 
        cout << "Select an option (enter -1 to exit): ";
        cin >> option;

        if (option == 1) { 

            // SortedArray objects of integer values
            int intArray1[MAX_SIZE] = {}, size1 = 0;
            int intArray2[MAX_SIZE] = {}, size2 = 0;
            cout << "For integer sequence 1\n";
            readArray(intArray1, size1);                
            cout << "For integer sequence 2\n";
            readArray(intArray2, size2);                
            SortedArray<int, MAX_SIZE, true> numberSequence1 { intArray1, size1 };
            SortedArray<int, MAX_SIZE, true> numberSequence2 { intArray2, size2 };
            checkSortedArrays(numberSequence1, numberSequence2);

        } else if (option == 2) {

            // SortedArray objects of Course objects
            Course courseArray1[MAX_SIZE], courseArray2[MAX_SIZE];
            int size1 = 0, size2 = 0;
            cout << "For course sequence 1\n";
            readArray(courseArray1, size1);                
            cout << "For course sequence 2\n";
            readArray(courseArray2, size2);                
            SortedArray<Course, MAX_SIZE, false> courseSequence1 { courseArray1, size1 };
            SortedArray<Course, MAX_SIZE, false> courseSequence2 { courseArray2, size2 };
            checkSortedArrays(courseSequence1, courseSequence2);

        }
    }

    return 0;
}
