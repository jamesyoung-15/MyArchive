#include <iostream>
#include "Full_time.h"
#include "Contract.h"

using namespace std;

int main() {
    Employee* p1 = new Employee("Tony", 3000.0);
    Employee p2("Tom", 4000.0);
    Employee* b1 = new Full_time("Jane", 4500.0, "associate", 5, 1000.0); 
    Employee p3 = *b1;
    Employee* t1 = new Contract("Lisa", 2000.0, 10, 150.0); 
    p1->print();
    p2.print();
    b1->print();
    p3.print();
    t1->print();
	
    // TODO: Please use dynamic_cast to convert t1 to Contract type and call info() member function
    Contract* t2 = dynamic_cast<Contract*>(t1);
    t2->info();
    
    delete p1;
    delete b1;
    delete t1;
    
	return 0;
}