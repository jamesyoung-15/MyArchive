/**
Question 2:
Complete the following method that tells the number of days in the month of February in a given year. If the year is a standard year, February will have 28 days. If the year is a leap year, February has 29 days. Here is how to determine if year is a leap year:

If year is evenly divisible by 4 and it's not evenly divisible by 100, it's a leap year.

If year is evenly divisible by 400, it's also a leap year.

For example, the following years were leap years: 2000, 1996, 1992.

The following years were not leap years: 1900, 1800. (10 points)

public static int daysInFebruary(int year)
{

}
 */

public class q2 
{
    
    
    public static int daysInFebruary(int year)
    {
        int days = 0;
        
        if ((year % 4 == 0) && year % 100 != 0) 
        {
            return days = 29;
        }
        else if (year % 400 == 0) 
        {
            return days = 29;
        }
        else 
        {
            return days = 28;
        }

    }  
}