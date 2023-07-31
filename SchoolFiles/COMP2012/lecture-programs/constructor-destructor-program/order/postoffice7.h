class Clock  /* File: postoffice7.h */
{
  private:
    int HHMM;
  public:
    Clock() : HHMM(0) { cout << "Clock Constructor\n"; }
    Clock(int hhmm) : HHMM(hhmm)
        { cout << "Clock Constructor at "<< HHMM << endl; }
    ~Clock()
        { cout << "Clock Destructor at " << HHMM << endl; }
};

class Postoffice
{
  private:
    Clock clock;
  public:
    Postoffice()
        { clock = Clock(800);  cout << "Postoffice Constructor\n"; }
    ~Postoffice( ) { cout << "Postoffice Destructor\n"; }
};
