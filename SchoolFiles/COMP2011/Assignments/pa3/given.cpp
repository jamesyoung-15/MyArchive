#include "patient.h"
#include <iostream>
#include <fstream>
using namespace std;


Patient* buildChainInfection(const char filename[]){
    struct temp_store_virus_id{ // You are not allowed to use this struct
        Patient** ptrToAllId;
        int total_loaded;
    };
    ifstream ifs(filename);
    if (!ifs){
        cout << "Error on loading the file. Stop loading..."<<endl;
        return nullptr;
    }
    Patient** ptrToAllId = new Patient*[MAX_NUMBER_OF_DATA];
    temp_store_virus_id temp = {ptrToAllId, 0};

    Patient* newroot = nullptr;
    int ID=0, doi=0, dodr = 0, parentID = 0;
    int status_int = 0;int dist_int = 0;
    bool firstLine = true;
    while (!ifs.eof()){
        if (firstLine==true){
            char dumpline[64];
            ifs.getline(dumpline,64);
            firstLine = false;
            continue;
        }
        ifs >> ID; ifs >> doi; ifs >> status_int;
        ifs >> dodr; ifs >> dist_int; ifs >> parentID;
        
        Patient* new_node = new Patient{ID, doi, static_cast<STATUS>(status_int), 
            dodr, static_cast<DISTRICT>(dist_int), nullptr, nullptr};
        // printPatientID(new_node);
        // cout << endl;
        temp.ptrToAllId[temp.total_loaded] = new_node;
        temp.total_loaded ++;
        if (newroot==nullptr){
            newroot = new_node;
        }
        else if (parentID!=-1){
            Patient* infectees = temp.ptrToAllId[parentID-1]->infectees;
            if (infectees!=nullptr){
                while (infectees->next!=nullptr){
                    infectees = infectees->next;
                }
                infectees->next = new_node;
            }
            else{
                temp.ptrToAllId[parentID-1]->infectees = new_node;
            }
        }
        else{
            Patient* next = newroot;
            while (next->next!=nullptr){
                next = next->next;
            }
            next->next = new_node;
        }
    }
    ifs.close();
    delete [] ptrToAllId;
    return newroot;
}

// This function is given.
void printPatientID(const Patient* patient){
    cout <<"ID:" << patient->ID;
}