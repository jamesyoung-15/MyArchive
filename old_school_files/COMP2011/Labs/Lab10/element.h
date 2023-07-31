#ifndef _ELEMENT_H_
#define _ELEMENT_H_

class element{
	private:
		char c;
	public:
		// Constructors
		element(){}
		element(char a){
			c = a;
		}
		
		// Accessors
		char get_element() const{
			return c;
		}
		bool equal(const element &e) const{
			return c == e.get_element();
		}
		
		// Mutator
		void set_element(char a){
			c = a;
		}

};

#endif /* _ELEMENT_H_ */
