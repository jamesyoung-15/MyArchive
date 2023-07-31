/**
 * Annual Weather description: Modify the AnnualWeatherV1 class to display 
 * weather data as Fahrenheit or Celsius and inches or centimeters per the user's request.
 * 
 * Author: James Young
 * 
 * Date: July 31, 2019
 * 
 */
import java.util.Scanner;
public class AnnualWeatherV2
{
    public static void main (String [ ] args)
    {

        //Declare and initialize variables
        Scanner in = new Scanner(System.in);
        String city = "Tallahassee";
        String state = "Florida";
        String choiceTemp = ""; //user input
        String choiceLength = ""; //user input
        
        
  
        String [] month = {"January","February","March","April","May.","June","July","August","September","October","November","December"};
        
        //test with miami
        //double [] temperature ={68.1, 69.1, 72.4, 75.7, 79.6, 82.4, 83.7, 83.6, 82.4, 78.8, 74.4, 69.9};  
        //double [] precipitation ={1.9, 2.1, 2.6, 3.4, 5.5, 8.5, 5.8, 8.6, 8.4, 6.2, 3.4, 2.2}; 
        
        //Tallahassee, FL
        double [] temperature ={51.8, 54.8, 61.1, 66.4, 74.4, 80.4, 82.4, 82.1, 78.9, 69.1, 60.4, 53.7};     //initialize with Fahrenheit values
        double [] precipitation ={5.4, 4.6, 6.5, 3.6, 5.0, 6.9, 8.0, 7.0, 5.0, 3.3, 3.9, 4.1};      //initialize with inch values
        
        //units
        String tempLabel = "";    //initialize 
        String precipLabel = ""; //initialize
        
        //user inputs
        System.out.println("Choose the temperature scale (F = Fahrenheit, C = Celsius): ");
        choiceTemp = in.nextLine();
        
        
        if (choiceTemp.equalsIgnoreCase("F")) {
             tempLabel = "F";
        }
        
        else if (choiceTemp.equalsIgnoreCase("C")){ //celsius
            tempLabel = "C";
            for (int index = 0; index < 12; index++){
                temperature[index] = ((temperature[index]-32)*5)/9;//f to c
                temperature[index] = ((temperature[index]*10));//round
                temperature[index] = ((int)temperature[index]);//round
                temperature[index] = temperature[index]/10;//round
                //System.out.println(temperature[index]); //test
            }
        }
        else if (choiceTemp != "c" || choiceTemp != "f" || choiceTemp != "F" || choiceTemp != "C") {
            System.out.println("Please re-enter either c or f.\nChoose the temperature scale (F = Fahrenheit, C = Celsius): ");
            choiceTemp = in.nextLine();
        }
        
        System.out.print("Choose the precipitation scale (I = Inches, C = Centimeteres): ");
        choiceLength = in.nextLine();
            
        if (choiceLength.equalsIgnoreCase("i")) {
             precipLabel = "In";
        }
        
        else if (choiceLength.equalsIgnoreCase("C")){ //celsius
            precipLabel = "CM";
            for (int index = 0; index < 12; index++){
                precipitation[index] = precipitation[index] * 2.54; //in to cm
                precipitation[index] = precipitation[index] * 10;//round
        	precipitation[index] = ((int)precipitation[index]);
        	precipitation[index] = precipitation[index] / 10;
        	//System.out.println(precipitation[index]);//check
            }
        }
        else {
            System.out.println("Please re-enter either i or c.\nChoose the precipitation scale (I = Inches, C = Centimeteres): ");
            choiceLength = in.nextLine();
        }
        
        //initialize
        double totalPrecip = 0.0;
        double totalTempF = 0.0;
        
        //Processing - calculate average temperature and total precipitation
        for( int index = 0; index < temperature.length; index++)
        {
            totalPrecip += precipitation[index];
            totalTempF += temperature[index];
        }
        
        //annual precip
        double avgPrecip = (totalPrecip*10);
        avgPrecip = (int)avgPrecip;
        avgPrecip = avgPrecip/10;
        
        //average temperature
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
            System.out.printf("%9s%16s%20s\n", month[index], temperature[index], precipitation[index]);
         }
        System.out.println("***************************************************");
        System.out.printf("%20s %.1f %15s %.1f", "Average: ", avgTempF, "Annual: ", avgPrecip);

    }//end main
}//end class
