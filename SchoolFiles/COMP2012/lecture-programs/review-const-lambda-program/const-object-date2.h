class Date              /* File: const-object-date2.h */
{
  private:
    int year, month, day;

  public:
    Date() { cin >> year >> month >> day; }
    Date(int y, int m, int d) { year = y; month = m; day = d; }

    void add_month() { month += 1; }; // Will be an inline function

    int difference(const Date& d) const { /* Incomplete */ }
    void print() const
        { cout << year << "/" << month << "/" << day << endl; }
};
