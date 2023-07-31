
/**
Question 1:
Complete the following method that takes a String parameter that is a time in standard international 24 hour format, such as "18:12."

The method returns a String with the same time in American 12 hour form that ends with AM or PM. For example, given the parameter in the example above, the method would return "6:12 PM."Use AM for midday times from 00:00 to 11:59 and PM for times from 12:00 to 23:59.

Recall the method Integer.parseInt() takes a String parameter and returns the integer equivalent. (15 points)

// precondition: the String value of the time parameter is valid and between
// 00:00 and 23:59 and has a length of 5 characters.
public static String convertTime(String worldFormat)
{

}
 */
public class q1
{
    // precondition: the String value of the time parameter is valid and between
    // 00:00 and 23:59 and has a length of 5 characters.
    public static String convertTime(String worldFormat)
    {
        String format;
        int convertStandard;
        String hour = worldFormat.substring(0,2);
        String min = worldFormat.substring(3,5);
        int intHour = Integer.parseInt(hour);
        int intMin = Integer.parseInt(min);
  
        if(intHour < 12) 
        {
            format = intHour + ":" + intMin + " AM";
        }

        else if(intHour == 12) 
        {
            format = 12 + ":" + intMin + " AM";

        }
        else
        {
            convertStandard = intHour % 12;
  
            format = convertStandard + ":" + intMin + " PM";
  
        }

        return format;
    }
    public static void main(String[] args) 
    {
   
  
        System.out.println(convertTime("18:45"));
    }   
}
