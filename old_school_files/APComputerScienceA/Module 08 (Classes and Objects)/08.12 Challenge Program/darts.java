
/**
 * Title: 8.12 Challenge Program (Taken from: EstimatePi 7.05 Challenge)
 * Author: James Young
 * Date: October 26, 2019
 * Purpose: Write a program to calculate the value of pi 
 * by simulating throwing darts at a dart board.
 */

public class darts
{
    //instance variables
    
    private double dartThrows; 
    private double numberOfHits, division, piValue;
    
    
    //constructor for objects
    darts (double dtThrow)
    {
        dartThrows = dtThrow;
        numberOfHits = 0.0;
        division = 0.0;
        piValue = 0.0;
    }
    
    /**
     * mutator method to calculate number of hits from dart throws
     * no param
     */
    
    public void calcHits()
    {
        
        for (int i=0; i<=dartThrows; i++)
        {
        if ((Math.pow((2 * Math.random()) - 1, 2) + Math.pow((2 * Math.random()) - 1, 2)) <= Math.pow(1.0, 2))
        {
            numberOfHits ++;
        }
        }
    }
    
    /**
     * Getter method to get number of hits
     * no param
     */
    
    public double getHits()
    {
        return numberOfHits;
    }
    
   
    /**
     * Mutator method that calculates pi value from hits and throws
     * no param
     */
    
    
    public void calcPiValue()
    {
        //pi = 4(hits/number of throws)
        piValue = (4*(numberOfHits/dartThrows));
    }
   
    
    /**
     * Getter method gets pi value 
     * no param
     */
    
    public double getPiValue()
    {
        return piValue;
    }
    
    
    //for printing table
    public String toString()
    {
        return String.format("%14.1f", piValue);
    }
    
}
