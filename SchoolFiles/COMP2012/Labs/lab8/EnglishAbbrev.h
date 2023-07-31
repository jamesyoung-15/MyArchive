#include "HashTable.h"

/*
  A class: EnglishAbbrev
  - It represents a dictionary storing a collection of English abbreviations 
    and their corresponding meanings
*/
class EnglishAbbrev
{
  private:
    HashTable<string,string> table; // A hash table
    int numAbbrev;                  // Number of English abbreviations in the table

  public:
    /*
      Constructor:
      - It initializes all the data members using the parameters.
    */
    EnglishAbbrev(int size, 
                  unsigned int(*hash_func1)(const string&), 
                  CollisionResolutionAlgo algo, 
                  unsigned int(*hash_func2)(const string&) = nullptr)
                  : table(size, hash_func1, algo, hash_func2), numAbbrev(0) {}

    /*
      addAbbrev function
      - abbrev: English abbreviation
      - meaning: Corresponding meaning
      - It checks whether the English abbreviation has any non-alphabetical characters.
        If so, return false. Otherwise, insert the abbreviation and meaning to the hash table.
    */
    bool addAbbrev(const string& abbrev, const string& meaning) {
      for(int i=0; i<abbrev.size(); ++i) {
        if(!isalpha(abbrev[i]))
          return false;
      }
      int num_probes = table.insert(abbrev, meaning);
      cout << "Number of Probes: " << num_probes;
      ++numAbbrev;
      return true;
    }

    /*
      removeAbbrev function
      - abbrev: English abbreviation
      - It checks whether the English abbreviation has any non-alphabetical characters.
        If so, return false. Otherwise, remove the abbreviation from the hash table.
    */
    bool removeAbbrev(const string& abbrev) {
      for(int i=0; i<abbrev.size(); ++i) {
        if(!isalpha(abbrev[i]))
          return false;
      }
      int num_probes = table.remove(abbrev);
      cout << "Number of Probes: " << num_probes << endl;
      --numAbbrev;
      return true;
    }

    /*
      searchAbbrev function
      - abbrev: English abbreviation
      - It checks whether the English abbreviation has any non-alphabetical characters.
        If so, return an empty string. Otherwise, search for the abbreviation and return the meaning
        if the abbreviation is found.
    */
    string searchAbbrev(const string& abbrev) {
      for(int i=0; i<abbrev.size(); ++i) {
        if(!isalpha(abbrev[i]))
          return string("");
      }
      string* meaning;
      int num_probes = table.find(abbrev, meaning);
      cout << "Number of Probes: " << num_probes;
      if(meaning != nullptr)
        return *meaning;
      return string("");
    }

    /*
      getNumAbbrevs function
      - It returns the number of abbreviations stored in the hash table.
    */
    int getNumAbbrevs() const {
      return numAbbrev;
    }
};
