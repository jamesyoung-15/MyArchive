
/**
 * Purpose: The purpose of this program is to count the number of
 * tickets sold and the amount of money received.
 * 
 * Author: James Young
 * Date: June 20, 2019
 */
public class GradesV2
{
    public static void main(String[ ] args)
    {
        //local variables
        int numTests = 0;      //counts number of tests
        int testGrade = 0;     //individual test grade
        int totalPoints = 0;   //total points for all tests 
        double average = 0.0;  //average grade     
        int counter = 0;       //total test taken
               
        //calculate total grade
        testGrade = 95;         //test grade
        counter++;
        totalPoints += testGrade;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
        
        //calculate total grade
        testGrade = 73;         //test grade
        counter++;
        totalPoints += testGrade;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
        
        //calculate total grade 
        testGrade = 91;         //test grade
        counter++;
        totalPoints += testGrade;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
        
        testGrade = 82;         //test grade
        counter++;
        totalPoints += testGrade;
        average = (double)totalPoints/counter;
        System.out.print(" Test # " + counter);
        System.out.print("   Test Grade: " + testGrade); 
        System.out.print("   Total points: " + totalPoints);
        System.out.println("   Average Score: " + average);
    }//end of main method
}//end of class
