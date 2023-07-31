
 /**
 * This class uses recursion to reverse a series of words entered from the keyboard.
 *
 * @author Elle Navan
 * @version 06/12/17
 */
import java.util.Scanner;
public class ReverseUserInput
{
    Scanner in = new Scanner(System.in);                    //creates new Scanner object

    //a recursive method to reverse the order of user input
    public void reverseInput()
    {
        System.out.print("Enter a word ('q' to quit): ");   //prompts user
        String aWord = in.next();                           //accepts user input

        if(aWord.equalsIgnoreCase("q"))
            System.out.println();
        else
            reverseInput();
        System.out.println(aWord);
    }

    public static void main(String[] args)
    {
        ReverseUserInput reverseIt = new ReverseUserInput(); //creates new object
        System.out.println("Enter a list of words,");
        System.out.println("press Enter after each word.");
        System.out.println("Type \'q\' to end the list.");
        System.out.println();

        reverseIt.reverseInput();                           //invokes reverseInput() method
    }
}
