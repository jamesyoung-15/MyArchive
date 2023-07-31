
/**
 * The purpose of this program is to demonstrate the use of the
 * toUpperCase() and toLowerCase() methods.
 *
 * @author George Boole
 * @version 06/04/17
 */
import java.util.Scanner;
public class ToCaseDemo
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        //Demonstration of toUpperCase() method
        System.out.println("Please enter a word or sentence in all lowercase letters. ");
        String userInput = in.nextLine();
        System.out.println();

        String upperCase = userInput.toUpperCase();

        System.out.println("Original input: " + userInput);
        System.out.println("In upper case: " + upperCase);
        System.out.println("\n\n");

        // Demonstration of toLowerCase() method
        System.out.println("Please enter a word or sentence in all uppercase letters. ");
        userInput = in.nextLine();
        System.out.println();

        String lowerCase = userInput.toLowerCase();

        System.out.println("Original input: " + userInput);
        System.out.println("In lower case: " + lowerCase);

    }

}
