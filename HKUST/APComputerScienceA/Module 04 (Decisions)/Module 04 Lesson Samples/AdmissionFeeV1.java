
/**
 * This program calculates the admission fee based on a person's age.
 *
 * @author George Boole
 * @version 06/04/17
 */
import java.util.Scanner;
public class AdmissionFeeV1
{
    public static void main(String [] args)
    {
        //Declare and initialize variables
        String yearsOld = "";                          //age entered as a String
        int age = -1;                                  //age of person as an integer value
        boolean isChild = false;                       //default, person is not a child
        double admissionFee = 6.00;                    //admission fee for adult
        double tax = 0.075;                            //sales tax

        Scanner in = new Scanner(System.in);

        //Input
        System.out.print("Please enter your age: ");
        yearsOld = in.nextLine();
        age = Integer.parseInt(yearsOld);

        //Processing
        if(age <= 10)                                  //evaluate if boolean expression is true or not
        {                                              // beginning brace for if block
           isChild = true;                             //if person is a child, assign true to boolean variable
           admissionFee = 4.50;                        //if person is a child, assign new admission fee
        }                                              // ending brace for if block

        admissionFee += admissionFee * tax;            //calculate admission fee + tax

        //Output
        System.out.println();
        System.out.println("Discount: " + isChild);
        System.out.println("Please pay: " + admissionFee);
       }//end of main method
    }//end of class
