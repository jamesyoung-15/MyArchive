#include <iostream>
#include <cstring>
#include "set.h"
using namespace std;

// TODO #1: Implement the constructor for an empty set
// Initialize an empty set with array_size equal to 1 
set::set(){
	sptr = new element[1];// Allocate memory for one element

	// ADD YOUR CODE HERE
	array_size = 1;
	num_elements =0;
}

// TODO #7: Implement the constructor for an array of elements
set::set(const element array_ele[], int n){
	
	// ADD YOUR CODE HERE
	sptr = new element[n]; // Allocate memory for one element
	array_size = n;
	num_elements = 0;
	for (int i =0; i<n; i++)
	{
		set::add(array_ele[i].get_element());
	}
}

// TODO #2: Implement the destructor
// Release the memory of the set pointer
set::~set(){

	// ADD YOUR CODE HERE
	delete [] sptr;
}

// TODO #3: Return true if some element is in the set and false otherwise
bool set::in(const element &e) const{
	// ADD YOUR CODE HERE

	//if element is in the set
	for (int i=0;i<num_elements;i++)
	{
		element ele = sptr[i].get_element();
		if(ele.equal(e))
		{
			return true;
		}
	}
	//otherwise return false
	return false;
}

// TODO #4: Add a new element and return true if it is successfully added
// Note that we double the array_size once it is full
bool set::add(const element &e) {

	// ADD YOUR CODE HERE

	//check if element is already in set
	if(in(e)== true)
	{
		return false;  
	}
	else
	{
		num_elements++;
	}

	//double array size if full
	if(num_elements == array_size)
	{
		element *newArray = new element[2*num_elements];
		for(int i =0;i<num_elements-1;i++)
		{
			newArray[i] = sptr[i].get_element();
		}
		delete []sptr;
		sptr = newArray;
		array_size = 2*num_elements;
		sptr[num_elements-1] = e;
	}
	else
	{
		sptr[num_elements-1]=e;
	}
	return true;
}

// TODO #5: Remove an element and return true if there is such an element
// Note that we halve the array_size when num_elements is smaller than a quarter of array_size
bool set::remove(const element &e) {
	
	// ADD YOUR CODE HERE

	//if element is outside set
	if(in(e)==false)
	{
		return false;
	}
	//remove element
	else
	{
		num_elements--;
		//if current number of elements is small enough
		if(num_elements*4<=array_size)
		{
			//reduce array_size by half
			array_size = array_size/2;
			//create new array of new array_size
			element *newArray = new element[array_size];
			//copy elements into new array
			for(int i =0;i<num_elements;i++)
			{
				newArray[i] = sptr[i].get_element();
			}
			//release old memory
			delete [] sptr;
			sptr = newArray;
		}
	}
	return true;
}

// TODO #6: Include all elements from the new set
void set::s_union(const set& s) {

	// ADD YOUR CODE HERE

	//repeatingly adding elements in s
	for(int i = 0; i<s.size(); i++)
	{
		set::add(s.sptr[i].get_element());
	}
}

int set::size() const{
	return num_elements;
}

void set::print() const{
	// Print the information of the set
	cout << "The current number of elements is " << num_elements << ".\n";
	cout << "The array size is " << array_size << ".\n"; 
	cout << "The set is {";
	for (int i = 0; i < num_elements; i++){
		cout << sptr[i].get_element();
		if(i != num_elements-1)
			cout << ", ";
	}
	cout << "}.\n";
}

int main(){
	element a = element('a');
	element b = element('b');
	element c = element('c');
	element d = element('d');

	cout << "------1. Test construct function------" << endl;

	cout << "construct {}:" << endl;
	set cs = set();
	cs.print();
	cout << endl;

	cout << "construct {a, d}:" << endl;
	element array_ele[4] = {a, d, a, a};
	set cs2 = set(array_ele, 4);
	cs2.print();
	cout << endl;

	cout << "------2. Test add function------" << endl;
	
	cout << "add a:" << endl;
	if(cs.add(a))
		cout << "Successfully add the new element " << a.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << a.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "add b:" << endl;
	if(cs.add(b))
		cout << "Successfully add the new element " << b.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << b.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "add c:" << endl;
	if(cs.add(c))
		cout << "Successfully add the new element " << c.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << c.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "add a:" << endl;
	if(cs.add(a))
		cout << "Successfully add the new element " << a.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << a.get_element() << ".\n";
	cs.print();
	cout << endl;
	
	cout << "------3. Test union function------" << endl;

	cout << "union {}:" << endl;
	cs.s_union(set());
	cs.print();
	cout << endl;

	cout << "union {a,d}:" << endl;
	cs.s_union(cs2);
	cs.print();
	cout << endl;
	
	cout << "------4. Test remove function------" << endl;

	cout << "remove d:" << endl;
	if(cs.remove(d))
		cout << "Successfully remove the element " << d.get_element() << ".\n";
	else 
		cout << "Fail to remove the element " << d.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "remove c:" << endl;
	if(cs.remove(c))
		cout << "Successfully remove the element " << c.get_element() << ".\n";
	else 
		cout << "Fail to remove the element " << c.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "remove c:" << endl;
	if(cs.remove(c))
		cout << "Successfully remove the element " << c.get_element() << ".\n";
	else 
		cout << "Fail to remove the element " << c.get_element() << ".\n";
	cs.print();
	cout << endl;
	
	return 0;
}