
/**
 * Title: 5.07 Secret Passcodes
 * 
 * Author: James Young
 * 
 * Purpose: Write a program to generate random passwords; 
 * the user should be able to select the character set and the length.
 * 
 * Date: July 29, 2019
 */
import java.util.Scanner;
import java.util.Random;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.File;
public class SecretPasscodes
{
    public static void main(String args[]) throws IOException 
    {
        //file output and input
        PrintWriter outFile = new PrintWriter(new File("pass.txt"));
        File fileName = new File("pass.txt");
        Scanner inFile = new Scanner(fileName);
        Scanner in = new Scanner(System.in);
    
        //menu
        System.out.println("Password Generator Menu");
        System.out.println("********************************************");
        System.out.println("[1] Lowercase Letters");
        System.out.println("[2] Uppercase Letters");
        System.out.println("[3] Numbers only");
        System.out.println("[4] Numbers and Letters");
        System.out.println("[5] Quit (use this to view your passwords)");
        System.out.println("********************************************");
        
        //initialize variables
        String token = "";
        String password = "";
        String password1 = "";
        String password2 = "";
        String password3 = "";
        int num = 0;
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        int num4 = 0;
        int count = 0;
        int userChoice = 0;
        while(userChoice != 5) {
            System.out.print("Enter selection (1 - 5): ");
            userChoice = in.nextInt();
            while(userChoice > 5 || userChoice == 0) {
                System.out.print("Please enter a number from the menu. Enter selection (1 - 5): ");
                userChoice = in.nextInt();
            }
            if(userChoice == 1) {
                System.out.print("Pass Length (6 or more): ");
                int passwordLength = in.nextInt();
                while(passwordLength < 6) {
                    System.out.print("Password length too short. Pass Length (6 or more): ");
                    passwordLength = in.nextInt();
                }
                for(int a = 0; a < passwordLength; a++) {
                    Random rand1 = new Random();
                    num = rand1.nextInt(26) + 97;
                    password = "" + (char)num + "";
                    outFile.print( password); 
                }
                outFile.println();
            }
      
            if(userChoice == 2) {
                System.out.print("Pass Length (6 or more): ");
                int passwordLength1 = in.nextInt();
                while(passwordLength1 < 6) {
                    System.out.print("Password length too short. Pass Length (6 or more): ");
                    passwordLength1 = in.nextInt();
                }
                for(int b = 0; b < passwordLength1; b++) {
                    Random rand3 = new Random();
                    num1 = rand3.nextInt(26) + 'A';
                    password1 = "" + (char)num1 + "";
                    outFile.print( password1); 
          
                }
                outFile.println();
            }
      
            if(userChoice == 3) {
                System.out.print("Pass Length (6 or more): ");
                int passwordLength2 = in.nextInt();
                while(passwordLength2 < 6) {
                    System.out.print("Password length too short. Pass Length (6 or more): ");
                    passwordLength2 = in.nextInt();
                }
                for(int c = 0; c < passwordLength2; c++) {
                    Random rand2 = new Random();
                    num2 = rand2.nextInt(10);
                    password2 = "" + num2 + "";
                    outFile.print(num2);
                }
                outFile.println();
            }
            if(userChoice == 4) {
                System.out.print("Pass Length (6 or more): ");
                double passwordLength3 = in.nextDouble();
                while(passwordLength3 < 6) {
                    System.out.print("Password length too short. Pass Length (6 or more): ");
                    passwordLength3 = in.nextDouble();
                }
                for(double d = 0; d < passwordLength3; d ++) { 
                    Random rand4 = new Random();
                    num3 = rand4.nextInt(78) + 48; //get ascii range of 48-127
                    if (num3 >=65 && num3 != 91 && num3 != 92 && num3 != 93 && num3 != 94 && num3 != 95 && num3 != 96 && num3 < 123 || num3 > 48 && num3 < 58){
                        //use and or statements to exclude other punctuations (91-96 and 58-64)
                        password3 = "" + (char)num3 + "";
                }
          outFile.print(password3);
        }
        outFile.println();
      }
    }
    outFile.close();
    System.out.println();
    System.out.println("Here are your randomly generated codes:");
    while(inFile.hasNext()) {
      token = inFile.next();
      count = count + 1;
      System.out.println(count + ":  " + token);
    }
    inFile.close();
    System.out.println("Thank you for using Pass Code Generator");
    
    
  }
}

