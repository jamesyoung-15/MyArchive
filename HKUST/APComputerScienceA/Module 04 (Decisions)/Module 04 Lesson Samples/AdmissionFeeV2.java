
/**
 * This program calculates the admission fee based on a person's age.
 *
 * @author George Boole
 * @version 06/04/17
 */
import java.util.Scanner;
public class AdmissionFeeV2
{
    public static void main(String [] args)
    {

        //Declare and initialize variables
        String yearsOld = "";                          //age entered as a String
        int age = -1;                                  //age of person as an integer value
        boolean isChild;
        double admissionFee;
        double tax = 0.075;

        Scanner in = new Scanner(System.in);

        //Input
        System.out.print("Please enter your age: ");
        yearsOld = in.nextLine();
        age = Integer.parseInt(yearsOld);

        //Processing
        if(age <= 10)                        //evaluate boolean expression
        {
        	isChild = true;                  //if person is a child, assign true to boolean variable
            admissionFee = 4.50;             //if person is a child, assign new admission fee
        }
        else
        {
        	isChild = false;                 //person is not a child, assign false
            admissionFee = 6.00;             //person is not a child, charge a higher fee
        }

        admissionFee += admissionFee * tax;      //calculate admission fee + tax

        //Output
        System.out.println();
        System.out.println("Discount: " + isChild);
        System.out.println("Please pay: " + admissionFee);

    }//end of main method
}//end of class

