/**
 * Annual Weather description: Write a program that displays the average temperature 
 * and the annual precipitation for a selected city.
 * 
 * Author: James Young
 * 
 * Date: July 31, 2019
 * 
 */
import java.util.Scanner;
public class AnnualWeatherV1
{
    public static void main (String [ ] args)
    {

        //Declare and initialize variables
        Scanner in = new Scanner(System.in);
        String city = "Tallahassee";
        String state = "Florida";
        
  
        String [] month = {"January","February","March","April","May.","June","July","August","September","October","November","December"};
        
        //Tallahassee, FL
        double [] temperature ={51.8, 54.8, 61.1, 66.4, 74.4, 80.4, 82.4, 82.1, 78.9, 69.1, 60.4, 53.7};     //initialize with Fahrenheit values
        double [] precipitation ={5.4, 4.6, 6.5, 3.6, 5.0, 6.9, 8.0, 7.0, 5.0, 3.3, 3.9, 4.1};      //initialize with inch values
    
        String tempLabel = "F";    //initialize to F
        String precipLabel = "in."; //initialize to in
        
        
        double totalPrecip = 0.0;
        double totalTempF = 0.0;
        //Processing - calculate average temperature and total precipitation
        for( int index = 0; index < temperature.length; index++)
        {
            totalPrecip += precipitation[index];
            totalTempF += temperature[index];
        }
    
        double avgPrecip = (totalPrecip*10);
        avgPrecip = (int)avgPrecip;
        avgPrecip = avgPrecip/10;
        
        double avgTempF = (totalTempF/12);
       
        
        //Output: display table of weather data including average and total
        System.out.println();
        System.out.println("           Weather Data");
        System.out.println("      Location: " + city +", " + state);
        System.out.println("Month     Temperature (" +  tempLabel + ")     Precipitation (" + precipLabel + ")");
        System.out.println();
        System.out.println("***************************************************");
        for( int index = 0; index < temperature.length; index++)
        {
            System.out.printf("%9s%13s%20s\n", month[index], temperature[index], precipitation[index]);
        }
        System.out.println("***************************************************");
        System.out.printf("%18s%24s", "Average:  " + avgTempF, "Annual:  " + avgPrecip);

    }//end main
}//end class
