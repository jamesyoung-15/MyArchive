#ifndef CIPHER_H
#define CIPHER_H

// #include "CipherUtility.h"
#include <iostream>
using namespace std;

// Cipher is an abstract base class
class Cipher
{
  // TODO #7
  // Make CipherUtility as a friend of Cipher so that CipherUtility can access 
  // all the data members, including those are private
  friend class CipherUtility;

  protected:
    string key;

  public:
    // Conversion constructor. Use MIL to resolve the name conflict
    Cipher(string key) : key(key) {}

    // Make the default destructor virtual
    virtual ~Cipher() = default;

    // Define two pure virtual functions

    virtual string encrypt(string plaintextMsg) const = 0;
    virtual string decrypt(string ciphertextMsg) const = 0;

    // Print the data member
    void print() const { cout << key; }
};

#endif
