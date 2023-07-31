#include <iostream>
#include <fstream>

using namespace std;
#define MAX_NUM_STU 10  //maximum number of students
#define NUM_INIT 5  //number of initial students

//Save initial data into the file.
void init(const int id[], const string name[], const float grade[], const string filename){
    ofstream ofs(filename);
    int i;

    if (ofs){
        ofs << "ID" << "\t" << "Name" << "\t" << "Grade" << endl;
        for (i=0; i<NUM_INIT; i++){
            ofs << id[i] << "\t" << name[i] << "\t"  << grade[i] << endl;
        }
        ofs.close();
        cout << "Initialization success!" << endl;
    }
    else{
        cerr << "Error: Cannot open " << filename << endl;
        exit(1);
    }
}

//Print all entries in the file.
void display(const string filename){
    ifstream ifs(filename);
    string line;

    if (ifs){
        while (true){
            getline(ifs, line);
            if(ifs.eof()) break;
            cout << line << endl;
        }
        ifs.close();
    }
    else{
        cerr << "Error: Cannot open " << filename << endl;
        exit(1);
    }
}

//TODO1: append a new entry to the file.
void append(const int id, const string name, const float grade, const string filename){
    int numberOfLines =0; //number of lines in the text file
    string line;
    ifstream ifs1(filename);

    //get number of lines in the text document, number of students, grades, and id is lines-1
    if(ifs1){
       while(true){
          getline(ifs1,line);
          if(ifs1.eof()) break;
          numberOfLines++;
       }
       ifs1.close();
    }


    ifstream ifs(filename);
    //create array of names, grades, and id 
    string currentNames[numberOfLines];
    int currentID[numberOfLines];
    float currentGrades[numberOfLines];

    //use getline to go past first line of title
    getline(ifs,line);
    //put first entry in line as ID, second as name, thrid as grade, store into array
    for (int i=0; i<numberOfLines-1; i++)
    {
        ifs >> currentID[i];
        ifs >> currentNames[i];
        ifs >> currentGrades[i];
    }
    //add the user input to last index of array
    currentID[numberOfLines-1] = id;
    currentNames[numberOfLines-1] = name;
    currentGrades[numberOfLines-1] = grade;

    //output the updated array into file
    ofstream ofs(filename);
    if (ofs){
        ofs << "ID" << "\t" << "Name" << "\t" << "Grade" << endl;
        for (int i=0; i<numberOfLines; i++){
            ofs << currentID[i] << "\t" << currentNames[i] << "\t"  << currentGrades[i] << endl;
        }
        ofs.close();
    }
    
    // for (int i=0; i<numberOfLines; i++)
    // {
    //     cout << currentID[i]<<endl;
    //     cout << currentNames[i]<<endl;
    //     cout << currentGrades[i]<<endl;
    // }
}

//TODO2: look up one entry by the name. 
//If find succesfully, print out his/her information and return true, otherwise, return false.
bool lookup(const string name, const string filename){
    string tempLine,line;
    ifstream ifs(filename);

    //go past first line
    getline(ifs, tempLine);

    //go through each line, search the name in each line using .find
    if(ifs){
        while(getline(ifs,tempLine)){
            if(tempLine.find(name)!= string::npos)
            {
                cout << tempLine << endl;
                return true;
            }
        }
        ifs.close();
    }
    return false;
}

//TODO3: calculate the average grade of all students in the file. 
//Please print out the total number of students and the average grade after calculation.
void cal_mean(const string filename){
    ifstream ifs(filename);
    string line, name, id;
    int totalStudents=0;
    float grade, avgGrade,totalGrade=0;

    //go past first line
    getline(ifs,line);

    //read first two inputs to skip
    while(ifs >> id >> name){
        totalStudents++;
        ifs >> grade;
        totalGrade += grade;
    }
    avgGrade = totalGrade/(totalStudents);
    cout << "Find " << totalStudents <<" students in total. Mean of their grades is " << avgGrade << endl;
}

int main(){
    const int id[NUM_INIT] = {1,2,3,4,5};
    const string name[NUM_INIT] = {"Bill", "Jack", "Ron", "Mark", "Donald"};
    const float grade[NUM_INIT] = {90.5, 95.5, 85.5, 93.5, 87.5};
    const string filename = "data.txt";
    init(id, name, grade, filename);

    int cmd, test_id;
    float test_grade;
    string test_name;
    bool find;

    while (true){
        cout << "Please enter: \n 1 to display all the entries\n 2 to append a new entry\n 3 to lookup an entry\n 4 to calculate the average grade\n 0 to exit: ";
        cin >> cmd;

        switch (cmd){
            case 0:
                return 0;

            case 1:
                display(filename);
                break;
            
            case 2:
                cout << "Please enter the id you want to append: ";
                cin >> test_id;
                cout << "Please enter the name you want to append: ";
                cin >> test_name;
                cout << "Please enter the grade you want to append: ";
                cin >> test_grade;
                append(test_id, test_name, test_grade, filename);
                break;
            
            case 3:
                cout << "Please enter the name you want to look up: ";
                cin >> test_name;
                find = lookup(test_name, filename);
                if (find) cout << "Find " << test_name << " successfully!" << endl;
                else cout << "Cannot find " << test_name << endl;
                break;

            case 4:
                cal_mean(filename);
                break;
            
            default:
                cout << "Wrong command!" << endl;
                break;
        }
    }
    return 0;
}