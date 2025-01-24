class Word              /* File: private-member-init.cpp */
{
  public:
    int frequency;
  private:
    const char* str;
};

int main() { Word movie = {1, "Titanic"}; }
