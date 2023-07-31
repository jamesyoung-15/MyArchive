#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "HashTableUtility.h"
using namespace std;

/*
  A class template: Entry
  - It represents an entry in the hash table, which consists of a key-value pair and a status
*/
template <typename K, typename V>
class Entry {
  public:
    K key;
    V value;
    Status status;
    Entry() : status(EMPTY) { } // Set status to EMPTY by default
};

/*
  A class template: HashTable
  - It represents a hash table.
*/
template <typename K, typename V>
class HashTable
{
  private:
    unsigned int table_size;              // Hash table size
    Entry<K,V>* table;                    // A dynamically allocated array of Entry objects
    unsigned int(*hash_func)(const K&);   // Hash function of the table
    unsigned int(*hash_func2)(const K&);  // Second hash function of the table for double hashing
    CollisionResolutionAlgo algo;         // Collision resolution algorithm for the hash table

  public:
    /*
      TODO 1: Construtor:
      - It dynamically allocates an array of Entry objects in size table_size.
      - It also initializes all the other data members using the parameters.
    */
    HashTable(unsigned int table_size, 
              unsigned int(*hash_func)(const K&), 
              CollisionResolutionAlgo algo, 
              unsigned int(*hash_func2)(const K&)=nullptr) ;

    /*
      TODO 2: Destructor:
      - It deallocates all the dynamically allocated memory to avoid memory leaks.
    */
    ~HashTable();

    /*
      TODO 3: offset function (equivalent to f in the lecture notes):
      - i: Represents the number of collisions
      - key: Represents the key
      - It returns the offset from the home location (i.e., hash value computed using hash_value1) 
        according to the current collision resolution algorithm, algo.
    */
    unsigned int offset(int i, const K& key);

    /*
      TODO 4: insert function
      - key: Represents the key
      - value: Represents the value
      - It inserts the key-value pair to the hash table, and returns the number of probes
        for the insertion of key-value pair.
    */
    unsigned int insert(const K& key, const V& value);

    /*
      TODO 5: remove function
      - key: Represents the key
      - It performs lazy deletion for the key-value pair, and returns the number of probes
        for the removal of key-value pair.
    */
    unsigned int remove(const K& key);

    /*
      TODO 6: find function
      - key: Represents the key
      - value: The pointer to the value of the key if the key is found, otherwise it is nullptr.
    */
    unsigned int find(const K& key, V*& v);

    /*
      print function
      - It prints all the key-value pairs in those entries marked as ACTIVE in the table.
    */
    void print() const {
      for(int i=0; i<table_size; ++i) {
        cout << i << ": ";
        if(table[i].status == ACTIVE) // If the status of the entry is ACTIVE
          cout << table[i].key << ", " << table[i].value;
        cout << endl;
      }
    }
};

#include "HashTable.tpp"

#endif
