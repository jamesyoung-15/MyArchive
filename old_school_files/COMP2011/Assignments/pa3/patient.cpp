#include <iostream>
#include <cstring>
#include "patient.h"
using namespace std;

/* 
    For the following tasks, feel free to define your helper function if needed.

    You are NOT allowed to modify any of the given function prototypes 
    including the return types, function names, default values, and parameter lists.

    You are NOT allowed to use array.

    You need to make sure that there is NO memory leak.
 */


/*  HELPER FUNCTIONS */

//TASK 1 Helper
//For task 1, count number of infected patients from root
int totalInfectees(Patient* patient)
{
    int count =1;
    if(patient==nullptr)
    {
        return 0;
    }
    else
    {
        count+=totalInfectees(patient->infectees);
        count+=totalInfectees(patient->next);
        return count;
    }

};
//END OF TASK 1

//Task 4 Helper
//return true if patient exist in data structure, otherwise false
bool findPatient(Patient* patient, int ID)
{
    if(patient == nullptr)
    {
        return false;
    }
    if(patient->ID == ID)
    {
        return true;
    }
    bool checkLeft = findPatient(patient->infectees,ID);
    if(checkLeft)
    {
        return true;
    }
    bool checkRight = findPatient(patient->next,ID);
    return checkRight;
}

//return desired node, used to pass to current
Patient* getNode(Patient* node, int ID)
{
    if (node == NULL)
    {
        return nullptr;
    }
 
    if (node -> ID == ID)
    {
        return node;
    }
 
    Patient* check = getNode(node -> infectees,ID);
    if (check != nullptr)
    {
        return check;
    }
 
    check = getNode(node->next, ID);
    return check;
}

//return parent of desired node, search recursively and update parent everytime recursively going left
Patient* getParentNode(Patient* node, int ID, Patient* parent)
{
    if (node == NULL)
    {
        return nullptr;
    }
 
    if (node -> ID == ID)
    {
        return parent;
    }
 
    Patient* check = getParentNode(node -> infectees,ID, node);
    if (check != nullptr)
    {
        return check;
    }
 
    check = getParentNode(node->next, ID, parent);
    return check;
}

//return previous node of desired node, basically same as get parent node function but update previous recursively going left
Patient* getPreviousNode(Patient* node, int ID, Patient* previous)
{
    if (node == NULL)
    {
        return nullptr;
    }
 
    if (node -> ID == ID)
    {
        return previous;
    }
 
    Patient* check = getPreviousNode(node -> infectees,ID, previous);
    if (check != nullptr)
    {
        return check;
    }
 
    check = getPreviousNode(node->next, ID, node);
    return check;
}

//check if desired node is infected by unknown source
bool checkUnknown(Patient* patient, int ID)
{
    if(patient == nullptr)
    {
        return false;
    }
    if(patient->ID == ID)
    {
        return true;
    }
    bool checkRight = checkUnknown(patient->next,ID);
    if(checkRight)
    {
        return true;
    }
    return checkRight;
}
//END OF TASK 4

//Task 5 Helper
void test(Patient*& current, Patient* root, int ID, Patient* parent, Patient* previous)
{
    root = current;
    searchPatientByID(ID,root, previous,parent);
    //Rule 0
    if((previous!=nullptr &&parent==nullptr&&root->infectees==nullptr))
    {
        Patient* child = nullptr;
        if(root->next!=nullptr)
        {
            child = root->next;
        }
        if(previous!=nullptr)
        {
            if(previous!=root)
            {
            if(previous->next!=nullptr)
                {
                    previous->next = child;
                }
            }
        }
        delete root;
        root=nullptr;
        return;
    }
    //Rule 1
    else if(parent==nullptr&&root->infectees!=nullptr&&previous!=nullptr)
    {
        Patient* child = nullptr;
        if(root->infectees!=nullptr)
        {
            child = root->infectees;
        }
        if(previous!=nullptr)
        {
            previous->next = child;
        }
        delete root;
        root=nullptr;
    }
    //Rule 2
    else if(parent!=nullptr&&root->infectees==nullptr&&previous!=nullptr)
    {
        Patient* child = nullptr;
        if(root->next!=nullptr)
        {
            child = root->next;
        }
        if(previous!=nullptr)
        {
            previous->next = child;
        }
        delete root;
        root=nullptr;
    }
    //Rule 3
    else if(parent!=nullptr&&root->infectees!=nullptr&&previous!=nullptr)
    {
        Patient* child = nullptr;
        if(root->infectees!=nullptr)
        {
            child = root->infectees;
        }
        if(root->next==nullptr)
        {
            previous->next = child;
        }
        else if(root->next!=nullptr)
        {
            previous->next = child;
            Patient* tempNext = root->next;
            Patient* temp = child;
            while(temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = tempNext;
        }
        delete root;
        root=nullptr;
    }
    //Rule 4
    else if(parent == nullptr&&previous==nullptr&&root->infectees==nullptr)
    {
        Patient* tempHead = root;
        Patient* temp = root->next;
        delete root;
        current= temp;
    }
    //Rule 5
    else if(parent == nullptr&&previous==nullptr&&root->infectees!=nullptr)
    {
        Patient* tempHead = root;
        Patient* temp = root->next;
        delete root;
        current= temp;
    }
    //Rule 6
    else if(root->infectees==nullptr&& parent!=nullptr && previous == nullptr)
    {
        //cout<<root->ID<<endl;
        Patient* child = nullptr;
        if(root->next!=nullptr)
        {
            child = root->next;
        }
        if(parent!=nullptr)
        {
            if(parent->infectees!=nullptr)
            {
                parent->infectees = child;
            }
        }
        delete root;
        root=nullptr;
    }
    //Rule 7
    else if(root->infectees!=nullptr&&parent!=nullptr&&previous==nullptr)
    {
        Patient* child = nullptr;
        if(root->infectees!=nullptr)
        {
            child = root->infectees;
        }
        if(root->next==nullptr)
        {
            if(previous!=root)
            {
                previous->infectees = child;
            }
            else
            {
                root->infectees = child;
            }
        }
        else if(root->next!=nullptr)
        {
            if(parent!=current)
            {
                parent->infectees = child;
            }
            else
            {
                current->infectees = child;
            }
            Patient* tempNext = root->next;
            Patient* temp = child;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next = tempNext;
        }
        delete root;
        root=nullptr;
    }
}
Patient* getID(Patient* node, int ID)
{
    if (node == NULL)
    {
        return nullptr;
    }
 
    if (node -> ID == ID)
    {
        return node;
    }
 
    Patient* check = getID(node -> infectees, ID);
    if (check != nullptr)
    {
        return check;
    }
 
    check = getID(node->next, ID);
    return check;
}

//END OF TASK 

/*  HELPER FUNCTIONS END */



/*  TASK START */

// Task 1: Print detailed information of a given patient, including the total count of following cases which are epidemiologically linked to him/her
void printPatientDetails(const Patient* patient){
    cout <<"ID:" << patient->ID<<endl;
    cout <<"Date of Infection:" << patient->date_of_infection<<endl;
    cout<<STATUS_NAME[patient->current_status]<<endl;
    cout <<"Date of Recovery or Death:" << patient->date_of_recovery_or_death<<endl;
    cout <<"Location:" << DISTRICT_NAMES[patient->location]<<endl;
    int count =0;
    if(patient->infectees!=nullptr)
    {
        count = totalInfectees(patient->infectees);
    }
    else
    {
        count=0;
    }
    cout<<"Total infectees:" << count << endl;
    //cout<<"count:"<<count<<endl;
};

// Task 2: Print tree view of Patient Database. 
void printPatientDatabase(const Patient* root, int vertical_alignment){
    if(root==nullptr)
    {
        return;
    }
    for(int i =0; i<vertical_alignment; i++)
    {
        printf("\t");
    }
    cout<<"ID:"<<root->ID<<endl;
    vertical_alignment++;
    printPatientDatabase(root->infectees,vertical_alignment--);
    printPatientDatabase(root->next,vertical_alignment);
};

// Taks 3: Print the number of newly confirmed cases for a given day
int printDailyStat(const Patient* root, int day){
    int count =0;
    if(root==nullptr)
    {
        return 0;
    }
    else if(root->date_of_infection==day)
    {
        count++;
        count+=printDailyStat(root->next,day);
        count+=printDailyStat(root->infectees,day);
    }
    else
    {
        count+=printDailyStat(root->infectees,day);
        count+=printDailyStat(root->next,day);
    }
    return count;
};
// Task 4: search Patient by the given ID. Returns 3 pointers by reference.
void searchPatientByID(int ID, Patient*& current, Patient*& previous, Patient*& parent){
    current->ID = 1;
    parent = nullptr;
    previous = nullptr;
    if(findPatient(current, ID)==true && ID!=1)
    {
        Patient* temp = current;
        Patient* temp2 = current;
        Patient* tempParent = parent;
        Patient* tempPrevious = previous;
        current = getNode(temp,ID);
        if(getParentNode(temp,ID,tempParent)!=nullptr || getPreviousNode(temp,ID,tempPrevious)!=nullptr)
        {
            //cout<<"HI!"<<endl;
            tempParent = getParentNode(temp,ID,tempParent);
            tempPrevious = getPreviousNode(temp,ID,tempPrevious);
            if(tempParent!=nullptr && tempPrevious!=nullptr)
            {
                if(tempParent->ID==tempPrevious->ID)
                {
                    if(checkUnknown)
                    {
                        // cout<<"Previous"<<tempPrevious->ID<<endl;
                        previous = tempPrevious;
                    }
                    else
                    {
                        // cout<<"Parent"<<tempParent->ID<<endl;
                        parent = tempParent;
                    }
                }
                else
                {
                    if(tempParent->ID>tempPrevious->ID)
                    {
                        // cout<<"Parent"<<tempParent->ID<<endl;
                        parent = tempParent;
                    }
                    else
                    {
                        // cout<<"Previous"<<tempPrevious->ID<<endl;
                        // cout<<"Parent"<<tempParent->ID<<endl;
                        previous = tempPrevious;
                        parent = tempParent;
                    }
                }
            }
            else if(tempParent==nullptr && tempPrevious!=nullptr)
            {
                if(tempPrevious->ID == 1)
                {
                    //cout<<"hi"<<endl;
                    previous = tempPrevious;
                }
                else
                {
                    previous = tempPrevious;
                }
            }
            else if(tempPrevious==nullptr&&tempParent!=nullptr)
            {
                // cout<<"Parent"<<tempParent->ID<<endl;
                parent = tempParent;
            }
        }

        //if previous or parent is supposed to be 1, it will change to current so need to change it back
        if(previous!=nullptr)
        {
            if(previous->ID==current->ID)
            {
                previous->ID=1;
            }
        }
        if(parent!=nullptr)
        {
            if(parent->ID==current->ID)
            {
                parent->ID=1;
            }
        }
    }
    else if(ID==1)
    {
        current->ID = ID;
        parent = nullptr;
        previous = nullptr;
    }
    else
    {
        current = nullptr;
        previous = nullptr;
        parent = nullptr;
    }
};

// Task 5: Remove all cases who have recovered or deceased
void removeInactive(Patient* &root){
    Patient* node=root;
    Patient* r = root;
    Patient* temp = root;


    int count =2;
    while(temp!=nullptr)
    {
        temp = getID(r,count);
        if(temp!=nullptr)
        {
            //cout<<temp->ID<<endl;
            if(temp->current_status!=0)
            {
                //cout<<temp->ID<<endl;
                test(node, temp,temp->ID,nullptr,nullptr);
            }
            count++;
        }
    }
};
// Task 6: Remove all cases
void deleteAllPatients(Patient* &root){
    if (!root) 
    {
        return;
    }
    deleteAllPatients(root->infectees);
    deleteAllPatients(root->next);
    delete root;
    root = nullptr;
};