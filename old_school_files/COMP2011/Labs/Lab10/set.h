#ifndef _SET_H_
#define _SET_H_

#include "element.h"

class set{
	private:
		element* sptr; // the pointer of the set elements
		int array_size; // the array size of elements
		int num_elements; // the current number of elements
	
	public:
		// Constructors
		set();
		set(const element[], int);
		
		// Destructor
		~set();
		
		// Accessors
		int size() const;
		void print() const;
		bool in(const element&) const;
		
		// Mutators			
		bool add(const element&);
		bool remove(const element&);
		void s_union(const set&);
	
};

#endif /* _SET_H_ */
