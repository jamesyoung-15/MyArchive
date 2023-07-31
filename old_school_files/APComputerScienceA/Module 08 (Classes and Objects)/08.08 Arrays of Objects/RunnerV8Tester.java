
/**
 * Title: RunnverV8Tester
 * Author: James Young
 * Date: October 4, 2019
 * Purpose: Expand your V7 object implementation class and client class to manage an array of data. 
 * Find the minimum, maximum, and averages of values.
 * 
 */

import java.util.Scanner;
public class RunnerV8Tester
{
    public static void main (String args[])
    {
        //initialize

        //user input
        Scanner in = new Scanner(System.in);
        
        //runner1
        System.out.println("What was runner 1's 5K time in minutes? (eg. if runner ran 12:34, write 12) ");
        double runTimeMin = in.nextDouble();
        
        System.out.println("What was runner 1's 5K time in seconds? (eg. if runner ran 12:34, write 34) ");
        double runTimeSec = in.nextDouble();
           
        //runner2
        System.out.println("What was runner 2's 5K time in minutes? (eg. if runner ran 12:34, write 12) ");
        double runTimeMin2 = in.nextDouble();
        
        
        System.out.println("What was runner 2's 5K time in seconds? (eg. if runner ran 12:34, write 34) ");
        double runTimeSec2 = in.nextDouble();
        
        //runner3
         System.out.println("What was runner 2's 5K time in minutes? (eg. if runner ran 12:34, write 12) ");
        double runTimeMin3 = in.nextDouble();
        
        
        System.out.println("What was runner 2's 5K time in seconds? (eg. if runner ran 12:34, write 34) ");
        double runTimeSec3 = in.nextDouble();
        
        //array of objects (total of 3 runners)
        RunnerV8[] runner = {new RunnerV8 (runTimeSec, runTimeMin),
                             new RunnerV8 (runTimeSec2, runTimeMin2),
                             new RunnerV8 (runTimeSec3, runTimeMin3)};
        
        //call methods (taken from shapesV8 example)                  
        for(int index = 0; index < runner.length; index++)
        {
            runner[index].combineTime();
            runner[index].speedRunner();
        }


        //print table for runner time and speed
        System.out.println(" Runner     Minutes     Seconds     Speed(km/h)");
        for(int index = 1; index <= runner.length; index++)
        {
            System.out.printf("%4d %11.1f %11.1f %12.2f%n", index,
                                                              runner[index -1].getRunMin(),
                                                              runner[index -1].getRunSec(),
                                                              //runner[index -1].getcombineTime(),//test
                                                              runner[index -1].getSpeedRunner());
        }
        System.out.println("--------------------------------------------------");
        
        //create array for speed of runners
        int i = 0;
        double arraySpeed [] = {runner[i].getSpeedRunner(), runner[i+1].getSpeedRunner(), runner[i+2].getSpeedRunner()};
        
        
        //find max speed of runners
        double max = Integer.MIN_VALUE;
	for(double speed1 : arraySpeed)
	{
		if(speed1 > max)
		{
		    max = speed1;
		}
	}
        
	
	//find min speed of runners
	double min = Integer.MAX_VALUE;
	for(double speed2 : arraySpeed)
	{
		if(speed2 < min)
		{
		    min = speed2;
		}
	}
	
	//find average speed of runners
	double calcTotal = 0;
	for(int index = 0; index < arraySpeed.length; index++)
	{
	    calcTotal += arraySpeed[index];
	    
	}
        double averageSpeed = calcTotal/arraySpeed.length;
        
        //test if speed array works
        //System.out.println(arraySpeed[0]);
        
        //print min, max, and average under table
        System.out.printf("Max speed: %16.2f km/h \n" ,max );
        System.out.printf("Min speed: %16.2f km/h \n" ,min);
        System.out.printf("Average Speed: %12.2f km/h \n" , averageSpeed );
        
    }//end of main

}//end of class
