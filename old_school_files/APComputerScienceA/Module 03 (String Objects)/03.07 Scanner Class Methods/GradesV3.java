
/**
 * Purpose: The purpose of this program is to count the number of
 * tickets sold and the amount of money received.
 * 
 * Author: James Young
 * Date: June 20, 2019
 */
import java.util.Scanner;
public class GradesV3
{
    public static void main(String[ ] args)
    {
        Scanner in;
        in = new Scanner(System.in);
        
        //local variables
        int numTests = 0;      //counts number of tests
        int totalPoints = 0;   //total points for all tests 
        double average = 0.0;  //average grade     
        int counter = 0;       //total test taken
        
        //ask for name and subject
        System.out.println("Please enter your name:  ");
        String studentName = in.next();     
        String studentnameRest = in.nextLine();
        System.out.println("Please enter the subject you're taking  ");
        String subjectfirstWord = in.next();
        String subjectrestofLine = in.nextLine();
        
        //calculate total grade
        System.out.println("Please enter your first test grade percentage:  ");
        int testGrade = in.nextInt();         //test grade
        counter++;
        totalPoints += testGrade;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
        
        //calculate total grade
        System.out.println("Please enter your second test grade percentage:  ");
        int testGrade2 = in.nextInt();           //test grade
        counter++;
        totalPoints += testGrade2;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade2); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
        
        //calculate total grade 
        System.out.println("Please enter your third test grade percentage:  ");
        int testGrade3 = in.nextInt();           //test grade
        counter++;
        totalPoints += testGrade3;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade3); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
        
        System.out.println("Please enter your fourth test grade percentage:  ");
        int testGrade4 = in.nextInt();           //test grade        //test grade
        counter++;
        totalPoints += testGrade4;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade4); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
    }//end of main method
}//end of class
