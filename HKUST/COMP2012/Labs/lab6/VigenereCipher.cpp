#include "VigenereCipher.h"
#include "Cipher.h"
#include "Utility.h"
#include <cctype>

// TODO #1
// Initialize the static data member alphabetSize here
const int VigenereCipher::alphabetSize = 26;

// TODO #2
// Implement the encrypt member function according to the given algoirthm.
string VigenereCipher::encrypt(string plaintextMsg) const
{
    string result="";
    int iterations=0;
    int key_index=0;
    for(int i=0;i<plaintextMsg.length();i++)
    {
        char c = plaintextMsg[i];
        // if lower case, convert to lower case
        if(isupper(c) && isalpha(c))
            c = tolower(c);
        // if alphabet, then do shift
        if(isalpha(c) && islower(c))
        {
            // key shift
            int shift = key[key_index] - 'a';
            // apply shift, wrap around if necessary
            c = (c - 'a' + shift)%alphabetSize;
            // convert back to ascii
            c = c + 'a';
        }
        // make sure key wraps
        if(key_index+1==key.length())
            key_index=0;
        else
            key_index++;
        result +=c;
    }
    return result;
}

// TODO #3
// Implement the decrypt member function according to the given algoirthm.
string VigenereCipher::decrypt(string ciphertextMsg) const
{
    string result="";
    int iterations=0;
    int key_index=0;
    for(int i=0;i<ciphertextMsg.length();i++)
    {
        char c = ciphertextMsg[i];
        // if lower case, convert to lower case
        if(isupper(c) && isalpha(c))
            c = tolower(c);
        // if alphabet, then do shift
        if(isalpha(c) && islower(c))
        {
            // key shift
            int shift = key[key_index]-'a';
            // apply shift, wrap around if necessary
            c = ((c-'a') - shift + alphabetSize)%alphabetSize;
            // convert back to ascii
            c = c + 'a';
        }
        // make sure key wraps
        if(key_index+1==key.length())
            key_index=0;
        else
            key_index++;
        result +=c;
    }
    return result;
}


// TODO #4
// Implement the static member function generateRandomKey
// according to the given algorithm.
string VigenereCipher::generateRandomKey(int length)
{
    // init empty string key
    string key="";
    // loop for length times, each iteration generate random number between 0 and alphatbetSize, add this number to ASCII value of 'a' and convert to ASCII char then add to string
    for(int i=0;i<length;i++)
    {
        int randomNumber = _rand() % alphabetSize;
        char letter = randomNumber + 'a';
        key+=letter;
    }
    return key;
}