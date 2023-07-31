#include <iostream>
#include <string>
#include "linkedlist.cpp"

using namespace std;

int selectAction(){
    int selection;
    cout << "Please type: " << endl << "1 Add" <<endl
         <<"2 Search" << endl <<"3 Print_By_Major"<<endl
         <<"4 Print"<<endl<< "5 Delete ALL" << endl <<"6 Exit"<<endl;
    cin >> selection;
    return selection;
}

int main() {

    Init();
    int func;
    cout << "Welcome to Lab9 Linkedlist " << endl;
    while (1) {
        func=selectAction();
        switch (func) {
            case 1:
                Add();
                break;
            case 2:
                Search();
                break;
            case 3:
                Print_By_Major();
                break;
            case 4:
                Print();
                break;
            case 5:
                Delete_ALL(h->head);
                break;
            default:
                cout << "Exit" << endl;
                return 0;
        }
    }
}