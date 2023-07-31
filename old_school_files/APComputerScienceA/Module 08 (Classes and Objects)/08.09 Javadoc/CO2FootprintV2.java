/**
 * @purpose: This class calculates the CO2 output by the amount of gas used.
 * 
 * It contains mutator methods to calculate the amount of CO2 output in tons and 
 * the amount of CO2 output in pounds. 
 * 
 * It contains getter methods for each private instance variables.
 * 
 * Private instance variables include myGallonsUsed, myTonsCO2, myPoundsCO2.
 *
 * Author: James Young
 * Date: October 23, 2019
 */
public class CO2FootprintV2
{
    
    //declaration of private instance variables
    private double myGallonsUsed, myTonsCO2, myPoundsCO2;

    /**
     * Constructor for objects of type C02FootPrintV2
     * @param gallons = myGallonsUsed
     */
    
    CO2FootprintV2(double gallons)
    {
        myGallonsUsed = gallons;
    }

    /**
     * Mutator method to calculate tons of CO2 (no parameters)
     */ 

    public void calcTonsCO2()
    {
        myTonsCO2 = (8.78 * Math.pow(10, -3)) * myGallonsUsed;
    }

    /**
     * Mutator method to convert tons of CO2 to pounds (no parameters)
     */

    public void convertTonsToPounds()
    {
        myPoundsCO2 = myTonsCO2 * 2205;
    }
    
    /**
     * Getter method to return gallons used
     * @return gallons used by person
     */
    
    public double getGallons()
    {
        return myGallonsUsed;
    }

    /**
     * Getter method to return amount of tons of CO2
     * @return CO2 output in tons
     */

    public double getTonsCO2()
    {
        return myTonsCO2;
    }

    /**
     * Getter method to return amount of pounds of CO2
     * @return CO2 output in pounds
     */

    public double getPoundsCO2()
    {
        return myPoundsCO2;
    }
}

