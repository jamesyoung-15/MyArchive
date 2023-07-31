
/**
 * The purpose of this program is to demonstrate the use of the
 * compareTo() and compareToIgnoreCase() methods.
 *
 * @author George Boole
 * @version 06/04/17
 */
import java.util.Scanner;
public class CompareToDemo
{
    public static void main(String[] args)
    {
        String myWord = "programming";
        Scanner in = new Scanner(System.in);

        System.out.print("Please enter a word: ");
        String yourWord = in.next();
        System.out.println();

        // Try both statements at separate times. How does the output change?
        int value = yourWord.compareTo(myWord);
        //int value = yourWord.compareToIgnoreCase(myWord);

        System.out.println("The value returned after comparing is: " + value );
        System.out.println();
        System.out.println("In an alphabetized list of words, our words would be written in this order: ");
        System.out.println();

        if(value < 0)
        {
            System.out.println("    " + yourWord);
            System.out.println("    " + myWord);
        }
        else if(value > 0)
        {
            System.out.println("    " + myWord);
            System.out.println("    " + yourWord);
        }
        else
        {
            System.out.println("    " + yourWord);
            System.out.println("    " + myWord);
            System.out.println("We chose the same word");
        }
    }
}
