/**
 * Tester class for Caesar Shift Cipher
 *
 * @author James Young
 * @version Jan 9, 2020
 */


import java.util.Scanner;
public class CaesarTester
{
    public static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";

    //main method
    public static void main(String[] args)
    {
        boolean quit = false;

        while(!quit)
        {
            //prompt the user with a menu
            System.out.println("-------------------------------------------------------");
            System.out.println("Welcome to Caesar Shift Encryption and Decryption.");
            System.out.println("Enter e to encrypt, d' to decrypt, or q' to quit");
            System.out.println("-------------------------------------------------------");

            //create scanner for user input
            Scanner in = new Scanner(System.in);
            String choice = in.next().toLowerCase();

            if(choice.equals("e"))
            {
                System.out.println("You chose encryption");

                //create encryption object that prompts the user for input
                Encryption encrypt = new Encryption(in);
                
                encrypt.setShiftAlphabet(Encryption.generateAlphabet(ALPHABET, encrypt.getShiftKey()));
                
                //encrypt message
                Encryption.encryptMessage(ALPHABET, encrypt.getShiftAlphabet(), encrypt.getMessage());


            }
            else if(choice.equals("d"))
            {
                System.out.println("You chose decryption");
                
                Decryption decrypt = new Decryption(in);
                
                //two shifted alphabets
                String originalShiftedAlphabet = decrypt.generateAlphabet(ALPHABET, decrypt.getShiftKey());
                String reverseShiftedAlphabet = decrypt.reverseShiftAlphabet(ALPHABET, decrypt.getShiftKey());
                int shiftKey = decrypt.getShiftKey();
                String message = decrypt.getEncryptedMessage();
                
                //decrypt
                Decryption.decryptMessage(originalShiftedAlphabet, reverseShiftedAlphabet, message, shiftKey);
                
            }
            else if(choice.equals("q"))
            {
                //quit
                System.out.println("Thank's for using this program!");
                break;
            }
            else
            {
                System.out.println("You didn't choose one of the given options. Please pick again.");

                //recursion is so great
                CaesarTester.main(args);
            }
        }

    }
}
