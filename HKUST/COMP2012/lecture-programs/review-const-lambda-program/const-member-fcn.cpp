class Date
{
    int year, month, day;
  public:
    int get_day( ) const { return day; } // inline + const 
    int get_month( ) const { return month; } // inline + const
    void add_year(int y); // non-const function
};
