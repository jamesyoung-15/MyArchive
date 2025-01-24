
/**
 * The purpose of this program is to demonstrate the use of the
 * equals() and equalsIgnoreCase() methods.
 *
 * @author George Boole
 * @version 06/04/17
 */
import java.util.Scanner;
public class EqualsDemo
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        // Try different input values such as:
        //  ap computer science a
        //  AP Computer Science A
        //  APCS
        // Notice the output for each input.
        System.out.print("Please enter the name of your course: ");
        String course = in.nextLine();
        System.out.println();

        if(course.equals("AP Computer Science A"))
        {
            System.out.println("Welcome to " + course);
            System.out.println("Today we are covering how to compare Strings and");
            System.out.println("multi-line blocks of code.");
        }
        else if(course.equalsIgnoreCase("AP Computer Science A"))
        {
            System.out.println("Welcome to " + course);
            System.out.println("The course name counted as a match even ");
            System.out.println("though proper capitalization was not used.");
        }
        else
        {
            System.out.println("Sorry, this is not " + course);
            System.out.println("Please check your schedule.");
        }
    }
}
