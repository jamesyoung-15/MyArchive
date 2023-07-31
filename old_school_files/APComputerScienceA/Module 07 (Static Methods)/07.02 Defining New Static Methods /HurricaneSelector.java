/**
 * Author: Jonathan Ma
 * Date: September 19
 */

import java.io.File;
import java.util.Scanner;
import java.io.IOException;

public class HurricaneSelector
{
    public static void main(String[] args)throws IOException
    {
        File fileName = new File ("HurricaneData.txt");
        Scanner inFile = new Scanner(fileName);
        
        int hurricanes = 156;
        String[] name = new String[hurricanes];
        int wsAvg = 0;
        int wsMax = 0;
        int pressureAvg = 0;
        int pressureMax = 0;
        int catAvg = 0;
        int catMax = 0;
        int[] year = new int[hurricanes];
        int[] pressure = new int[hurricanes];
        int[] ws = new int[hurricanes];
        int[] cat = new int[hurricanes];
        int cat1 = 0;
        int cat2 = 0;
        int cat3 = 0;
        int cat4 = 0;
        int cat5 = 0;
 

        
        for(int x = 0; x<hurricanes;x++)
        {
            inFile.next();
            year[x] = inFile.nextInt();
            pressure[x] = inFile.nextInt();
            ws[x] = inFile.nextInt();
            name[x] = inFile.next();
        }
        inFile.close();
        for(int x = 0;x<ws.length;x++)
        {
            ws[x] *= 1.15;
        }
        for(int i = 0;i<cat.length;i=i++)
        {
            if(ws[i] >= 74 && ws[i] < 96) 
            {
                cat[i] = 1;
            }
            else if (ws [i] >= 96 && ws[i] < 111) 
            {
                cat[i] = 2;
            }
            else if(ws[i] >= 111 && ws[i] < 130) 
            {
                cat[i] = 3;
            }
            else if(ws[i] >= 130 && ws[i] < 157) 
            {
                cat[i] = 4;
            }
            else if(ws[i] >= 157) 
            {
                cat[i] = 5;
            }
        }
        for(int variable : cat)
        {
            catAvg += variable;
        }
        catAvg /= cat.length;
        int catMax2 = Integer.MIN_VALUE;
        for(int variable : cat)
        {
            if(cat>catMax2)
            {
                catMax2 = variable;
            }
        }
        int catMin = Integer.MAX_VALUE;
        for (int variable:cat)
        {
            if(cat<min)
            {
                min = cat;
            }
        }
        for(int variable2:ws)
        {
            wsAvg += ws;
        }
        wsAvg/=ws.length;
        int speedMax = Integer.MIN_VALUE;
        for(int variable2:ws)
        {
            if(variable2>wsMax)
            {
                wsMax = ws;
            }
        }
        int wsMin = Integer.MAX_VALUE;
        for(int variable2 : ws)
        {
            if(variable2<wsMin)
            {
                wsMin = ws;
            }
        }
        
        for(int variable3 : pressure)
        {
            pressureAvg +=variable2;
        }
        pressureAvg/=pressure.length;
        int pressureMax = Integer.MIN_VALUE;
	for(int variable3 : pressures)
		{
			if(pressure > pressureMax)
			{
				pressureMax = variable3;
			}
		}
		
	int pressureMin = Integer.MAX_VALUE;
	for(int variable3 : pressures)
		{
			if(variable3 < pressureMin)
			{
				pressureMin = variable3;
			}
		}
	for(int variable : categories)
	{
		if(variable == 1)
			{
				cat1++;
			}
		else if(variable == 2)
			{
				cat2++;
			}
		else if(variable == 3)
			{
				cat3++;
			}
		else if(variable == 4)
			{
				cat4++;
			}
		else if(variable == 5)
			{
				cat5++;
			}	
		}
		
	System.out.println("                   Hurricanes 1995 - 2015");
        System.out.println();
        System.out.println("Year     Hurricane    Category     Pressure (mb)     Wind Speed (mph)");
        System.out.println("=====================================================================");
        for (int x = 0; x < years.length; x++)
        {
            
            System.out.printf("%d%13s%10d%16d%18d\n" , year[x] , name[x] , cat[x] , pressures[x] , (int)ws[j]);
            
        }
        System.out.println("=====================================================================");
        System.out.printf("%s%20d%16d%18d\n","Average", catAvg ,pressureAvg,  wsAvg/ 2);
        System.out.printf("%s%20d%16d%18d\n" ,"Maximum" , catMax , pressureMax ,wsMax);
        System.out.printf("%s%20d%16d%18d\n","Minimum" , catMin ,pressureMin , wsMin);
        System.out.println();
        System.out.println("Summary of categories:");
        System.out.println("  Cat1: " + cat1);
        System.out.println("  Cat2: " + cat2);
        System.out.println("  Cat3: " + cat3);
        System.out.println("  Cat4: " + cat4);
        System.out.println("  Cat5: " + cat5);
        
    }
}