
/**
 * Title: 8.12 Challenge Program (Taken from: EstimatePi 7.05 Challenge Program)
 * Author: James Young
 * Date: October 26, 2019
 * Purpose: Write a program to calculate the value of pi 
 * by simulating throwing darts at a dart board.
 */
import java.util.Scanner; 

public class dartsTester
{
    public static void main (String args[])
    {
        //initialize (10 trials because assignment needs 10 objects)
        Scanner in = new Scanner(System.in);
        
        System.out.println("First Trial: How many times should the darts be thrown per trial?");
        double dartThrows1 = in.nextDouble();
        System.out.println();

        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows2 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows3 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows4 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows5 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows6 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows7 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows8 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows9 = in.nextDouble();
        System.out.println();
        
        System.out.println("Second Trial: How many times should the darts be thrown per trial?");
        double dartThrows10 = in.nextDouble();
        System.out.println();
        
        
        //array of 10 objects
        darts[] darts = {new darts(dartThrows1),
                         new darts(dartThrows2),
                         new darts(dartThrows3),
                         new darts(dartThrows4),
                         new darts(dartThrows5),
                         new darts(dartThrows6),
                         new darts(dartThrows7),
                         new darts(dartThrows8),
                         new darts(dartThrows9),
                         new darts(dartThrows10)};
        
        //call methods                 
        for(int index = 0; index < darts.length; index++)
        {
            darts[index].calcHits();
            darts[index].calcPiValue();
        }
        
        
        //print table
        System.out.println("Trial        Pi Value");
        for(int index = 1; index <= darts.length; index++)
        {
            System.out.printf("%4d ",index);
            System.out.println(darts[index-1]); //uses the toString method
        }
        
        
        //get average pi value
        double total = 0;
        for (int i = 0; i< darts.length; i++)
        {
            total+=darts[i].getPiValue();
        }
        double average = total/10;
        System.out.println("-------------------------------");
        System.out.printf("%3s %9.1f", "Average: ", average);
        
    }
}
