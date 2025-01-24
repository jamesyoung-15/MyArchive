/* File: const-object-date.h */

class Date      // There are problems with this code; what are they?
{
  private:
    int year, month, day;

  public:
    Date() { cin >> year >> month >> day; }
    Date(int y, int m, int d) { year = y; month = m; day = d; }

    void add_month() { month += 1; }; // Will be an inline function

    int difference(const Date& d)
    { /* Incomplete: write this function */ }

    void print()
        { cout << year << "/" << month << "/" << day << endl; }
};
