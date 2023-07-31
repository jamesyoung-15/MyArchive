
/**
 * Title: PlanetGravity
 * Author: James
 * Date: September 27
 * Purpose: Write a program to determine the surface gravity (g) on each planet in our solar system.
 *
 */
import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class PlanetGravity
{
    //main method
    public static void main(String[]args) throws IOException
    {
        //Planet Data
        String [] planetNames = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"}; //names of planets
        double [] mass = {3.30E23,4.869E24,5.972E24,6.4219E23,1.900E27,5.68E26,8.683E25,1.0247E26}; //masses in kg of planets
        double [] diameterInMeters = {4880000,12103600,12756300,6794000,142984000,120536000,51118000,49532000}; 
        double [] diameterInKm = {4880,12103.6,12756.3,6794,142984,120536,51118,49532 };
        double [] g = surfaceGravity(mass, diameterInMeters);
        printResults(planetNames, mass, diameterInKm, g);
        textFile(g);
    }
    
    //This segment will get values of surface gravity using equation g = (G*m)/r^2
    public static double[] surfaceGravity(double [] mass, double [] diameterInMeters)
    //will return a double array, bring down mass and diameter arrays from main
    {
        //initialize variables
       
        double constantG = 6.67E-11;// G = 6.67e^-11
        double [] surfaceGravity = new double[8]; //length will be 8 because 8 planets
        int arrayLength = 8;
        for (int i = 0; i < arrayLength; i ++)
        {
            //use g = (G*m)/r^2 for all 8 planet data sets
            // r = diameter/2
            surfaceGravity [i] = ((constantG * mass[i])/(Math.pow(diameterInMeters[i]/2, 2)));
            //System.out.print(surfaceGravity[i]);
        }
        return surfaceGravity;
    }
    //This segment will write the surface gravity data to a text file (gravitydata.txt)
    public static void textFile (double [] g) throws IOException
    {
       PrintWriter outFile = new PrintWriter(new File("surfacegravitydata.txt"));
       double []surfaceGravity = g; 
       for(int index = 0; index < 8;index++)
       {
           outFile.println(surfaceGravity[index]); //writes surface gravity values in surfacegravitydata.txt file
       }
       outFile.close();  //close file
        
    }
    
    //This segment will format the results into table
    public static void printResults (String [] planetNames, double [] mass, double [] diameterInKm, double [] g)
    {
        System.out.println("                       Planetary Data                          ");
        System.out.printf("%-12s %-17s %7s %11s\n","Planet","Diameter(Km)","Mass(Kg)","g(m/s^2)");
        System.out.println("--------------------------------------------------");   
        for(int iterate = 0; iterate < 8; iterate++)
        {
            System.out.printf("%-14s %-14.0f %5.2e %11.2f\n",planetNames[iterate],diameterInKm[iterate],mass[iterate], g[iterate]);
        }

    }
    
}
