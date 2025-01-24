#ifndef HASHTABLEUTILITY_H
#define HASHTABLEUTILITY_H

#include <iostream>
using namespace std;

const int TABLE_SIZE = 10; // Size of the hash table
const int R = 3;           // The value of R for the second hash function

enum Status { ACTIVE, EMPTY, DELETE };                          // Possible status for hash table cell
enum CollisionResolutionAlgo { LINEAR, QUADRATIC, DOUBLEHASH }; // Collision resolution algorithms

/* 
   The first hash function.
   The hash value is calculated by hash_code % TABLE_SIZE.
   Each uppercase alphabet is represented as an integer, 'A' as 0, 'B' as 1, ..., 'Z' as 25,
   where hash_code is the total sum of the integer presentation of the characters in the key. 
*/
unsigned int hash_func1(const string& key) {
  unsigned int hash_code = 0;
  for(int i = 0; i < key.size(); ++i)
    hash_code += (key[i] - 'A');
  return hash_code % TABLE_SIZE;
}

/* 
   The second hash function.
   The hash value is calculated by R -  hash_code % R.
   Each uppercase alphabet is represented as an integer, 'A' as 0, 'B' as 1, ..., 'Z' as 25,
   where hash_code is the total sum of the integer presentation of the characters in the key. 
*/
unsigned int hash_func2(const string& key) {
  unsigned int hash_code = 0;
  for(int i = 0; i < key.size(); ++i)
    hash_code += (key[i] - 'A');
  return R - hash_code % R;
}

#endif
