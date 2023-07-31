/**
 * Title: HurricaneSelector
 * Author: James Young
 * Purpose: Write a program to calculate the average category, pressure, and wind speed of 
 * Atlantic hurricanes that have occurred between a given year range.
 * Date: September 15, 2019
 */


import java.util.Scanner;
import java.io.File;
import java.io.IOException;

    public class HurricanesSelector
    {
    
        public static void main(String[] args)throws IOException
        {  
        
    
            File fileName = new File("HurricaneData.txt");
            Scanner inFile = new Scanner(fileName);
        
            int numberOfHurricanes = 156; //156 columns in file
		

		
		int[] years = new int[numberOfHurricanes];
		int[] speeds = new int[numberOfHurricanes];
		int[] pressures = new int[numberOfHurricanes];
		String[] names = new String[numberOfHurricanes];
		
		for(int i = 0; i < numberOfHurricanes; i++)
		{
			
			years[i] = inFile.nextInt();
			
			inFile.next();
			
			pressures[i] = inFile.nextInt();
			
			speeds[i] = inFile.nextInt();
			
			names[i] = inFile.next();
			
		}
		inFile.close();
		
		//convert unit
		for(int i = 0; i < speeds.length; i++)
		{
			speeds[i] *= 1.15078; //1.15078 miles to the knot
		}
		
		//put into categories
		int[] categories = new int[numberOfHurricanes];
		for(int i = 0; i < categories.length; i++)
		{
			if(speeds[i] >= 74 && speeds[i] < 96) //cat 1 74-95
			{
				categories[i] = 1;
			}
			else if (speeds [i] >= 96 && speeds[i] < 111) //cat 2 97-110
			{
				categories[i] = 2;
			}
			else if(speeds[i] >= 111 && speeds[i] < 130) //cat 3 111-129
			{
				categories[i] = 3;
			}
			else if(speeds[i] >= 130 && speeds[i] < 157) //cat 4 130-156
			{
				categories[i] = 4;
			}
			else if(speeds[i] >= 157) //cat 5 157 or higher
			{
				categories[i] = 5;
			}
		}
		
		//average category
		int categoryAverage = 0;
		for(int category : categories)
		{
			categoryAverage += category;
		}
		categoryAverage /= categories.length;
		
		//cat max
		int max = Integer.MIN_VALUE;
		for(int category : categories)
		{
			if(category > max)
			{
				max = category;
			}
		}
		
		//cat min
		int min = Integer.MAX_VALUE;
		for(int category : categories)
		{
			if(category < min)
			{
				min = category;
			}
		}
		
		//avg pressure
		int pressureAverage = 0;
		for(int pressure : pressures)
		{
			pressureAverage += pressure;
		}
		pressureAverage /= pressures.length;
		
		//max pressure
		int pressureMax = Integer.MIN_VALUE;
		for(int pressure : pressures)
		{
			if(pressure > pressureMax)
			{
				pressureMax = pressure;
			}
		}
		
		//min pressure
		int pressureMin = Integer.MAX_VALUE;
		for(int pressure : pressures)
		{
			if(pressure < pressureMin)
			{
				pressureMin = pressure;
			}
		}
		
		//avg wind speed
		int speedAverage = 0;
		for(int speed : speeds)
		{
			speedAverage += speed;
		}
		speedAverage /= speeds.length;
		
		//max wind speed
		int speedMax = Integer.MIN_VALUE;
		for(int speed : speeds)
		{
			if(speed > speedMax)
			{
				speedMax = speed;
			}
		}
		
		//min wind speed
		int speedMin = Integer.MAX_VALUE;
		for(int speed : speeds)
		{
			if(speed < speedMin)
			{
				speedMin = speed;
			}
		}
		
		
		
		//initialize
		int c1 = 0;
		int c2 = 0;
		int c3 = 0;
		int c4 = 0;
		int c5 = 0;
		//count num of category (Saphir-Simpson Hurricane Wind Scale)
		for(int category : categories)
		{
			if(category == 1)
			{
				c1++;
			}
			else if(category == 2)
			{
				c2++;
			}
			else if(category == 3)
			{
				c3++;
			}
			else if(category == 4)
			{
				c4++;
			}
			else if(category == 5)
			{
				c5++;
			}	
		}
        
        //print results
        System.out.println("                      Hurricanes 1995 - 2015");
        System.out.println();
        System.out.println("Year     Hurricane    Category     Pressure (mb)     Wind Speed (mph)");
        System.out.println("=====================================================================");
        
        int j = 0;
        for (j = 0; j < years.length; j++){
            
            System.out.printf("%d%13s%10d%16d%18d\n" , years[j] , names[j] , categories[j] , pressures[j] , (int)speeds[j]);
            
        }
        
      
        System.out.println("=====================================================================");
        System.out.printf("%s%20d%16d%18d\n" , "Average" , categoryAverage , pressureAverage , speedAverage / 2);
        System.out.printf("%s%20d%16d%18d\n" , "Maximum" , max , pressureMax , speedMax);
        System.out.printf("%s%20d%16d%18d\n" , "Minimum" , min , pressureMin , speedMin);
        System.out.println();
        System.out.println("Summary of Categories:");
        System.out.println("  Cat1: " + c1);
        System.out.println("  Cat2: " + c2);
        System.out.println("  Cat3: " + c3);
        System.out.println("  Cat4: " + c4);
        System.out.println("  Cat5: " + c5);
        
   
        
    }
}