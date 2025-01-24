class Word              /* File: default-constructor.cpp */
{
  private:
    int frequency;
    char* str; 
  public:
    Word() { frequency = 0; str = nullptr; } // Default constructor
};

int main() 
{ 
    Word movie; // No arguments => expect default constructor
}
