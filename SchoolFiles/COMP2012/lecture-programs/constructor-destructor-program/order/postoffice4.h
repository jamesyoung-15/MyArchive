class Clock         /* File: postoffice4.h */
{
  private: int HHMM;    // hour, minute
  public:
    Clock() : HHMM(0)
        { cout << "Clock Constructor\n"; }
    ~Clock() { cout << "Clock Destructor\n"; }
};
class Room
{
  public:
    Room()  { cout << "Room Constructor\n"; }
    ~Room() { cout << "Room Destructor\n"; }
};
class Postoffice
{
  private:
    Room room; Clock clock;
  public:
    Postoffice()
        { cout << "Postoffice Constructor\n"; }
    ~Postoffice() 
        { cout << "Postoffice Destructor\n"; }
};
