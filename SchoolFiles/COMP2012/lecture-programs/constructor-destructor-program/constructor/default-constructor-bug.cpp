class Word              /* File: default-constructor-bug.cpp */
{ 
  private: int frequency; char* str;
  public: Word(const char* s, int k = 0);
};

int main() { Word movie; }	// which constructor?
