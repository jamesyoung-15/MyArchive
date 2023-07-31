/* File: const-int-ptr.cpp */
int i = 151;
i += 20;    // OK

int* pi = &i;
*pi += 20;  // OK

const int* pic = &i;
*pic += 20; // Error! Can't change i through pic

pic = pi;   // OK
*pic += 20; // Error! Can't change *pi thru pic

pi = pic;   // Error: Invalid conversion from 'const int*' to 'int*'
