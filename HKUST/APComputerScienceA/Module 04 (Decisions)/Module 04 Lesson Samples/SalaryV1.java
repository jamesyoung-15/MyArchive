
/**
 * The following program calculates a person's salary based on
 * the numbers of hours worked and the hourly pay rate.
 * If the person works more than 40 hours, the pay rate is one-
 * and-a-half times the regular hourly rate for the overtime
 * hours.
 *
 * @author George Boole
 * @version 06/04/17
 */
import java.util.Scanner;
public class SalaryV1
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        //Input
        System.out.print("Please enter your name (first last): ");
        String firstName = in.next();
        String lastName = in.nextLine();

        System.out.print("\nWhat is your hourly rate of pay: ");
        String rateOfPay = in.nextLine();
        double payRate = Double.parseDouble(rateOfPay);

        System.out.print("\nHow many hours did you work: ");
        String totalHoursWorked = in.nextLine();
        double totalHours = Double.parseDouble(totalHoursWorked);
        System.out.println();

        //Processing
        double totalSalary = totalHours * payRate;

        boolean isOvertime = false;

        if(totalHours > 40)
        {
            isOvertime = true;
            totalSalary += (totalHours - 40) * payRate / 2;
        }

        //Output
        System.out.println("Employee Name: " + lastName + ", " + firstName);
        System.out.print("Hours worked: " + totalHours);
        System.out.print("\t\tOvertime: " + isOvertime + "\n");
        System.out.println("Salary: " + totalSalary);
    }
}
