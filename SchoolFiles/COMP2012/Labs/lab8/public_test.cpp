#include "EnglishAbbrev.h"
#include "HashTableUtility.h"

int main()
{
  cout << "Enter testcase number (1: Linear, 2: Quadratic, 3: Double): ";
  int testcase_num;
  cin >> testcase_num;

  CollisionResolutionAlgo algo;
  unsigned int(*hash_func_one)(const string&) = hash_func1;
  unsigned int(*hash_func_two)(const string&) = nullptr;

  switch(testcase_num) {
    case 1:
      algo = LINEAR;      
      break;
    case 2:
      algo = QUADRATIC;
      break;
    case 3:
      algo = DOUBLEHASH;
      hash_func_two = hash_func2;
      break;
  }

  EnglishAbbrev englishAbbrev(TABLE_SIZE, hash_func_one, algo, hash_func_two);
  string abbrevs[] { "RSVP", "ASAP", "LMK", "BRB", "CC", "DOB", "ETA" };
  string meanings[] { "Please reply", "As soon as possible", "Let me know", "Be right back", "Carbon copy",
                      "Date of birth", "Estimated time of arrival" };

  cout << "**** Insert all the abbreviations ****" << endl;
  for(int i=0; i<7; ++i) {
    cout << "Insert: " << abbrevs[i] << ", ";
    englishAbbrev.addAbbrev(abbrevs[i], meanings[i]);
    cout << endl;
  }

  cout << endl;
  cout << "*** Search and Print the meaning ***" << endl;
  string meaning = englishAbbrev.searchAbbrev("RSVP");
  cout << endl;
  cout << "Meaning of RSVP: " << meaning << endl;

  meaning = englishAbbrev.searchAbbrev("CC");
  cout << endl;
  cout << "Meaning of CC: " << meaning << endl;

  meaning = englishAbbrev.searchAbbrev("ASAP");
  cout << endl;
  cout << "Meaning of ASAP: " << meaning << endl;

  cout << endl;
  cout << "*** Remove some abbreviations ***" << endl;
  englishAbbrev.removeAbbrev("BRB");
  englishAbbrev.removeAbbrev("CC");

  cout << endl;
  cout << "*** Search and Print the meaning ***" << endl;
  meaning = englishAbbrev.searchAbbrev("BRB");
  cout << endl;
  if(meaning == "")
    cout << "Meaning of BRB: " << "Not found" << endl;
  else
    cout << "Meaning of BRB: " << meaning << endl;

  meaning = englishAbbrev.searchAbbrev("CC");
  cout << endl;
  if(meaning == "")
    cout << "Meaning of CC: " << "Not found" << endl;
  else
    cout << "Meaning of CC: " << meaning << endl;
}
