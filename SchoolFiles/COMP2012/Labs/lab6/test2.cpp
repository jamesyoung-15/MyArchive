#include <iostream>
#include "VigenereCipher.h"
#include "CipherUtility.h"
#include "Utility.h"
using namespace std;

int main() {
  _srand(2012);
  string plaintext = "Desmond and Cecia are the COMP2012 course instructors.";

  cout << "Generate a random key: [";
  string key = VigenereCipher::generateRandomKey(12);
  cout << key << "]" << endl << endl;

  Cipher* cipher1 = new VigenereCipher(key);

  cout << "Encrypt the message: \"" << plaintext << "\"" << endl;
  string ciphertext = cipher1->encrypt(plaintext);
  cout << "Cipher Text: [" << ciphertext << "]" << endl << endl;

  cout << "Decrypt the message: \"" << ciphertext << "\"" << endl;
  string decryptedtext = cipher1->decrypt(ciphertext);
  cout << "Plain Text: [" << decryptedtext << "]" << endl << endl;

  delete cipher1;

  key = "myproperandvalidsecretkey";
  Cipher* cipher2 = new VigenereCipher(key);

  cout << "The key \"";

  if(CipherUtility::isKeyValid(cipher2)) {
    cipher2->print();
    cout << "\" is [valid]" << endl << endl;
  }
  else {
    cipher2->print();
    cout << "\" is [invalid]" << endl << endl;
    CipherUtility::removeNonAlphaChars(cipher2);
    cout << "Output the new key: [";
    cipher2->print();
    cout << "]" << endl << endl;
  }

  cout << "Encrypt the message: \"" << plaintext << "\"" << endl;
  ciphertext = cipher2->encrypt(plaintext);
  cout << "Cipher Text: [" << ciphertext << "]" << endl << endl;

  cout << "Decrypt the message: \"" << ciphertext << "\"" << endl;
  decryptedtext = cipher2->decrypt(ciphertext);
  cout << "Plain Text: [" << decryptedtext << "]" << endl;

  delete cipher2;

  return 0;
}
