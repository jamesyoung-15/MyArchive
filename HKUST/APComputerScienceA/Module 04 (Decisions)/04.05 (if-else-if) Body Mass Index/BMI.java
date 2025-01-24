
/**
 * Title: BMI
 * 
 * Purpose: Write a program to calculate Body Mass Index (BMI) given a 
 * person's height and weight. Use previous assignments and demo programs as models.
 *
 * Author: James Young
 */
import java.util.*;
public class BMI
{
    public static void main (String args [])
    {
        Scanner in = new Scanner(System.in);
        
        //user inputs
        System.out.print("Please enter your name (first last): ");
        String firstName = in.next();
        String lastName = in.nextLine();
        System.out.print("Please enter your weight in pounds: ");
        double weightPounds = in.nextDouble();
        System.out.print("Please enter your height in feet and inches (eg. 5 10):" );
        String heightFt = in.next();
        String heightIn = in.nextLine();
        
        //conversions
        double feetHeight = Double.parseDouble(heightFt); //change to double
        double inchesHeight = Double.parseDouble(heightIn); //change to double
        double weightInKilos = weightPounds * 0.453592;
        double heightInMeters = (((feetHeight * 12) + inchesHeight) * .0254);
        double BMI = weightInKilos /(heightInMeters * heightInMeters);
        
        //results
        System.out.println("BMI Result:");
        System.out.println("------------------------------------");
        System.out.println("Name: " + firstName + lastName);
        System.out.println("Height (cm): " + heightInMeters);
        System.out.println("Weight (kg): " + weightInKilos);
        System.out.println("BMI: " + BMI);
        
        
        
        if (BMI<18.5) {
            System.out.print("Category: Underweight");
        }
        else if (BMI>=18.5 && BMI<24.9) {
            System.out.print("Category: Normal or Healthy Weight");
        }
        else if (BMI>=25.0 && BMI<29.9) {
            System.out.print("Category: Overweight");
        }
        else if (BMI>=30.0) {
            System.out.print("Category: Obese");
        }
    }
}
