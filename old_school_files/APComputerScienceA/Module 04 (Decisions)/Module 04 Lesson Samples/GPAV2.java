
/**
 * This program illustrates the use of the
 * AND logical operator to determine eligibility.
 *
 * @author George Boole
 * @version 06/04/17
 */
import java.util.Scanner;
public class GPAV2
{
    public static void main(String[] args)
    {
        String letterGrade = "";
        boolean isEligible;
        Scanner in = new Scanner(System.in);

        //Gather input
        System.out.println("GPA Calculator");
        System.out.println();
        System.out.println("Enter 5 grades separated by a space (e.g. 4 3 2 1 4)): ");
        int grade1 = in.nextInt();
        int grade2 = in.nextInt();
        int grade3 = in.nextInt();
        int grade4 = in.nextInt();
        int grade5 = in.nextInt();

        System.out.println();
        System.out.println("Enter the number of days absent: ");
        int daysAbsent = in.nextInt();

        //Calculate grade point average
        double average = (double)(grade1 + grade2 + grade3 + grade4 + grade5)/5;

        //Determine eligibility
        if(average >= 3.5)
            isEligible = true;
        else if((average >= 2.5) && (daysAbsent < 4))
            isEligible = true;
        else if((average >= 1.5) && (daysAbsent < 2 ))
            isEligible = true;
        else
            isEligible = false;

        //Output
        System.out.println();
        System.out.println("Grade point average: " + average);
        System.out.println("Student eligibility status: " + isEligible);
    }
}
