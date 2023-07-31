#include "CipherUtility.h"
#include <cctype>

// TODO #5
// Implement the static member function isKeyValid
bool CipherUtility::isKeyValid(const Cipher *cipher)
 {
    // loop through each character in the key string of the Cipher object
    for (int i=0;i<cipher->key.length();i++)
    {
        // For each character, it checks whether it is an alphabet letter by using the isalpha function
        if(!isalpha(cipher->key[i]))
        {
            return false;
        }

    }
    return true;
 }

// TODO #6
// Implement the static member function removeNonAlphaCharsHelper
string CipherUtility::removeNonAlphaCharsHelper(string str)
{
    // if empty return empty
    if(str.length()==0)
        return "";
    
    // check if first character is not an alphabet, if it is not then recusively iterate for substring removing first character
    char c = str[0];
    if(!isalpha(c))
    {
        return removeNonAlphaCharsHelper(str.substr(1));
    }
    // return the recursive function for the next iteration including the character at 0th index
    return c + removeNonAlphaCharsHelper(str.substr(1));
}