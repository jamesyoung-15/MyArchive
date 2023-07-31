#include<iostream>
#include<string.h>
using namespace std;

enum majors {COMP, CPEG, DSCT };

struct node{
    string name;
    majors major;
    node* next;     // next node
    node* next_sm;  // next node with the same major
};


struct headnode{
    node* head;
    node* tail;
    node* comp_pointer;
    node* cpeg_pointer;
    node* dsct_pointer;
};


string Print_Key(majors in_major) {
    switch (in_major) {
        case 0: return ("COMP");
        case 1: return ("CPEG");
        case 2: return ("DSCT");
        default: return ("ERROR!");
    }
};


majors Print_Major(string in_major){
    if(in_major=="COMP")
        return majors(COMP);
    else if(in_major=="CPEG")
        return majors(CPEG);
    else if(in_major=="DSCT")
        return majors(DSCT);
    else {cout<<"ERROR!"<<endl; return majors(COMP);}
}


headnode* h = nullptr;


int Init() {
    h = new headnode;
    h->head = nullptr;
    h->tail = nullptr;
    h->comp_pointer = nullptr; // points to the first node with major = COMP
    h->cpeg_pointer = nullptr; // points to the first node with major = CPEG
    h->dsct_pointer = nullptr; // points to the first node with major = DSCT
    return 0;
}

// TODO Add() a new student with major
int Add() {
    string in_name;
    int major_num;

    cout << "Please input name: ";
    cin >> in_name;
    cout << "Please input major: 1 COMP 2 CPEG 3 DSCT" << endl;
    cin >> major_num;
    major_num--;



    // new nodes are always added at the end

    //create and allocate node
    node* n = new node;

    //assign data to node
    n->name = in_name;
    n->major = majors(major_num);

    //set next to null as it is last node
    n->next = nullptr;
    n->next_sm = nullptr;

    //if list is empty put it as head
    if(h->head == nullptr)
    {
        h->head = n;
        h->tail = n;
    }
    //otherwise there is list, place new node goes after tail, then set tail to new node
    else
    {
       h->tail->next = n;
       h->tail = n;
    }


    //add major to end of major pointer
    if(major_num == 0)
    {
        if(h->comp_pointer == nullptr)
        {
            h->comp_pointer = n;
        }
        else
        {
            node* compPtr = h->comp_pointer;
            while(compPtr->next_sm !=nullptr)
                compPtr = compPtr->next_sm;
            compPtr->next_sm = n;
        }
    }
    else if(major_num == 1)
    {
        if(h->cpeg_pointer == nullptr)
        {
            h->cpeg_pointer = n;
        }
        else
        {
            node* cpegPtr = h->cpeg_pointer;
            while(cpegPtr->next_sm !=nullptr)
                cpegPtr = cpegPtr->next_sm;
            cpegPtr->next_sm = n;
        }
    }
    else if(major_num == 2)
    {
        if(h->dsct_pointer == nullptr)
        {
            h->dsct_pointer = n;
        }
        else
        {
            node* dsctPtr = h->dsct_pointer;
            while(dsctPtr->next_sm !=nullptr)
                dsctPtr = dsctPtr->next_sm;
            dsctPtr->next_sm = n;
        }
    }

    cout << h->tail->name;
    cout << " Added!" << endl;
    return 0;
}



int Search() {
    node* head = h->head;
    node* tail = h->tail;
    string name;
    cout << "Please input the name: ";
    cin >> name;
    node* now_node = head;
   
    // TODO Search by input the name 
    cout<<"Returned Results: " << endl;

    //if head is empty, no linked list
    if(now_node == nullptr)
        cout<<"No names found, list is empty"<<endl;

    //traverse through nodes, check if current node has name
    while(now_node != nullptr)
    {
        if(now_node->name == name)
            cout<< "Name:" << now_node->name << " Major:" << Print_Key(now_node->major)<<endl;
        now_node = now_node->next;
    }
    return 0;
}

void Print() {
    node* head = h->head;
    node* tail = h->tail;
    node* now_node = head;
    cout << "Students Information:" << endl;
    
    // TODO Print all students information

    //if linked list is empty
    if(now_node == nullptr)
        cout<<"No students added" << endl;

    //traverse through each node, print each node
    while(now_node!= nullptr)
    {
        cout<<"Name:" <<now_node->name << " Major:"<< Print_Key(now_node->major)<<endl;
        now_node = now_node -> next;
    }
   
}

int Print_By_Major(){ 
    string in_major;
    cout<< "Please input major:"<<endl;
    cin>>in_major;
    majors m= Print_Major(in_major);
    node* ptr=nullptr;

   
    // TODO Print students with same major


    cout << "Students Information:" << endl;

    if(in_major == "COMP")
    {
        ptr = h->comp_pointer;
        while (ptr != nullptr)
        {
            cout<<"Name:"<<ptr->name<<" Major:" << Print_Key(ptr->major) << endl;
            ptr = ptr->next_sm;
        }
    }
    else if (in_major == "CPEG")
    {
        ptr = h->cpeg_pointer;
        while (ptr != nullptr)
        {
            cout<<"Name:"<<ptr->name<<" Major:" << ptr->major << endl;
            ptr = ptr->next_sm;
        }
    }
    else if (in_major == "DSCT")
    {
        ptr = h->dsct_pointer;
        while (ptr != nullptr)
        {
            cout<<"Name:"<<ptr->name<<" Major:" << ptr->major << endl;
            ptr = ptr->next_sm;
        }
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
    
    // TODO Print students with same major


    return 0;    
}

void Delete_ALL(node*& head){
    
    if(head==nullptr)
        cout<<"Deleting Success!"<<endl;
    else if(head!=nullptr)
    {
        Delete_ALL(head->next);
        cout<<"deleting " <<head->name<<endl;
        delete head;
        head = nullptr;
        
    }


    // TODO Delete ALL studnets 


}