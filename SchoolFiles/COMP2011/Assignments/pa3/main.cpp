#include <iostream>
#include <cstring>
#include "patient.h"

using namespace std;

const int MAX_FILENAME_SIZE = 1000;

int main(){    
    Patient* root = nullptr;
    int input=0, input2=0;
    Patient* currentPointer = root;

    Patient* current = nullptr;
    Patient* previous = nullptr;
    Patient* parent = nullptr;

    while (input!=88){
        cout << "========= COVID-19 TRACING DATABASE MENU =========" << endl;
        if (currentPointer!=nullptr){
            cout << "You are at:";
            printPatientID(currentPointer);
            cout << endl;
            cout << "0 ---- Go to the root infection case" << endl;
            cout << "1 ---- Go to the infectees list" << endl;
            cout << "2 ---- Go to the next infectee" << endl;
            cout << "3 ---- Print the detailed information of this patient" << endl;
            cout << "4 ---- Print the whole infection chain" << endl;
            cout << "5 ---- Print the daily statistics" << endl;
            cout << "6 ---- Print a particular id's current position, previous ID and parent ID" << endl;
            cout << "7 ---- Remove the inactive case" << endl;
            cout << "11 ---- Close the file" << endl;
        }
        else{
            cout << "There is no data in the system" <<endl;
            cout << "10 ---- Load a file to the system" << endl;
        }
        cout << "88 ---- Quit the program" << endl;
        cout << "=========COVID-19 TRACING DATABASE MENU =========" << endl;
        cout << "Please enter your option: ";
        cin >> input;
        
        if (currentPointer!=nullptr){
        switch(input){
            case 0:
                currentPointer=root;
                break;
            case 1:
                if (currentPointer->infectees!=nullptr)
                    currentPointer=currentPointer->infectees;
                else{
                    cout << "There is no infectees case"<<endl;
                }
                break;
            case 2:
                if (currentPointer->next!=nullptr)
                    currentPointer=currentPointer->next;
                else{
                    cout << "There is no next case"<<endl;
                }
                break;
            case 3:
                printPatientDetails(currentPointer);
                break;
            case 4:
                printPatientDatabase(root);
                break;
            case 5:
                cout << "Which day: ";
                cin >> input2;
                if (input2>0){
                    cout << "The infected number of Day " << input2 << " is ";
                    cout << printDailyStat(root, input2);
                }
                else{
                    cout << "Your input is incorrect! Please enter again" <<endl;
                }
                break;
            case 6:
                cout << "ID: ";
                cin >> input2;
                if (input2>0){
                    cout << "The ID=" << input2 << " case is:"<<endl;
                    current = root;
                    previous = nullptr;
                    parent = nullptr;

                    searchPatientByID(input2, current, previous, parent);
                    if (current!=nullptr)
                        cout << "Current"<< current->ID <<endl;
                    if (previous!=nullptr)
                        cout << "Previous"<< previous->ID <<endl;
                    if (parent!=nullptr)
                        cout << "Parent" << parent->ID <<endl;
                    if (current==nullptr&&previous==nullptr&&parent==nullptr)
                        cout << "Not Found" << endl;
                }
                else{
                    cout << "Your input is incorrect! Please enter again" <<endl;
                }
                break;
            case 7:
                removeInactive(root);
                currentPointer = root;
                break;
            case 11:
                deleteAllPatients(root);
                currentPointer = nullptr;
                root = nullptr;
                break;
            }
            
        }
        if (input==10 && currentPointer==nullptr){
            cout << "Please type the file for loading to the database." << endl;
            
            char filename[MAX_FILENAME_SIZE];
            cin >> filename;
            
            root = buildChainInfection(filename);
            currentPointer = root;
        }
        cout << endl << endl;
    }

    cout <<"===== COVID-19 TRACING DATABASE PROGRAM END ====="<<endl;
    
    deleteAllPatients(root);
}