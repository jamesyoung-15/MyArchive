#ifndef CIPHERUTILITY_H
#define CIPHERUTILITY_H

#include "Cipher.h"

class CipherUtility
{
  public:
    // [TO BE IMPLEMENTED] A static member function, which validates the key of the given cipher
    // => TODO #5: Implement the static member function isKeyValid in CipherUtility.cpp
    static bool isKeyValid(const Cipher* cipher);

    // [TO BE IMPLEMENTED] A recursive static member function, which recursively remove all
    // the non-alphabet characters in the string, str
    // => TODO #6: Implement the static member function removeNonAlphaCharsHelper in CipherUtility.cpp
    static string removeNonAlphaCharsHelper(string str);

    // [IMPLEMENTED] A static member function, which calls removeNonAlphaCharsHelper
    // to remove all the non-alphabet characters in the key of the given cipher
    static void removeNonAlphaChars(Cipher* cipher) {
      cipher->key = removeNonAlphaCharsHelper(cipher->key);
    }
};

#endif
