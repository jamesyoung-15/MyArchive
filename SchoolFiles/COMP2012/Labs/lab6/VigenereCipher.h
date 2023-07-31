#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include "Cipher.h"

// VigenereCipher is a derived class of Cipher
class VigenereCipher : public Cipher 
{
  private:
    // A private static constant variable
    // Need to be initialized in VigenereCipher.cpp
    // => TODO #1: Initialize the static data member alphabetSize in VigenereCipher.cpp
    static const int alphabetSize;

  public:
    // [IMPLEMENTED] Conversion constructor
    // It calls the conversion constructor of the base class to initialize key
    VigenereCipher(string key) : Cipher(key) {}

    // [TO BE IMPLEMENTED] Override the two pure virtual functions inherited from Cipher class
    // => TODO #2: Implement the encrypt member function in VigenereCipher.cpp
    // => TODO #3: Implement the decrypt member function in VigenereCipher.cpp
    virtual string encrypt(string plaintextMsg) const override;
    virtual string decrypt(string ciphertextMsg) const override;

    // [TO BE IMPLEMENTED] A static member function, which generates a random key with length
    // specified by the parameter
    // => TODO #4: Implement the static member function generateRandomKey in VigenereCipher.cpp
    static string generateRandomKey(int length);
};

#endif
