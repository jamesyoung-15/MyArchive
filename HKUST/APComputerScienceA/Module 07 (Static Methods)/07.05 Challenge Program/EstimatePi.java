
/**
 * Title: 7.05 Challenge Program (EstimatePi)
 * Author: James Young
 * Date: September 27, 2019
 * Purpose: Write a program to calculate the value of pi 
 * by simulating throwing darts at a dart board.
 */
import java.util.Scanner;

public class EstimatePi
{
    //static variables for all methods
    
    static double x = 0; 
    static double y = 0; 
    static double r = 1.0; //radius
    static double numberOfX = 0;
    static double numberOfY = 0; 
    static double numberOfHits = 0; 
    static double pi = 0; 
    static double average = 0;
    static double dartThrows = 0; 
    static double numberOfTrials = 0;
    
    //This segment will count number of hits based on the circle equation
    public static double hits(double x, double y, double numberOfTrials)
    {
        numberOfHits = 0; //set back to zero for each trial or else values will keep getting higher

        for (int i=0; i<=numberOfTrials; i++)
        {
            x = (2 * Math.random()) - 1; //generates number below 1
            y = (2 * Math.random()) - 1; //same as above
        //use x^2+y^2<=1, anytime the number is less than 1 hit goes up by 1
        if ((Math.pow(x, 2)) + Math.pow(y, 2) <= Math.pow(r, 2))
        {
            numberOfHits ++;
        }
        }
        return numberOfHits;
    }
    
    //This segment will use equation given from assignment pi= 4(h/n) to find pi values
    public static double piValue(double numberOfHits,double dartThrows)
    {
        //pi = 4(hits/number of throws)
        double piValue = (4 * (numberOfHits)/dartThrows); 
        return piValue;
    }
    
    //main method
    public static void main(String[] args) 
    {
        //intialize
         
        //User input for throws and trials
        Scanner in = new Scanner(System.in);
        System.out.println("How many times should the darts be thrown per trial?");
        dartThrows = in.nextInt();
        System.out.println();
        System.out.println("How many trials should there be?");
        numberOfTrials = in.nextInt();
        
        double total = 0;
        
        //print value for each trial of pi
        for (int i = 0; i < numberOfTrials; i++) 
        {
            double hits = hits(x,y,dartThrows);
            double estimatedPi = piValue(numberOfHits,dartThrows);
            total += estimatedPi; //use to find average
            System.out.printf("Trial [%2d]: pi = %5f\n", i+1, estimatedPi);
        }
        //average will be the estamite
        double average = (total / numberOfTrials); 

        System.out.printf("Estamite of pi = %1.6f", average);
        
        
    }
}
