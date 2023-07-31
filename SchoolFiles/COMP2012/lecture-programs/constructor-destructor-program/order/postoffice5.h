class Clock         /* File: postoffice5.h */
{
  public:
    Clock() { cout << "Clock Constructor\n"; }
    ~Clock() { cout << "Clock Destructor\n"; }
};
class Room
{
  private:
    Clock clock;
  public:
    Room()  { cout << "Room Constructor\n"; }
    ~Room() { cout << "Room Destructor\n"; }
};
class Postoffice
{
  private:
    Room room;
  public:
    Postoffice()
        { cout << "Postoffice Constructor\n"; }
    ~Postoffice() 
        { cout << "Postoffice Destructor\n"; }
};
