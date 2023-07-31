
/**
 * Title: 8.03 RunnerV3
 * Author: James Young
 * Date: September 27, 2019
 * Purpose: Define an implementation class for an object of your choice.
 *
 */
import java.util.Scanner;

public class RunnerV3
{
    //constructor
    public RunnerV3()
    {
    }
    
    //first method asks how much user ran and converts it to km
    public double calckm(double mRan)
    {
        double calckm = (double)mRan/1000.0;
        return calckm;
    }
    
    //second method determines if you need to keep running
    public double goalLeft(double goalKm, double kmRan)
    {
        double goalLeft = (double)goalKm - (double)kmRan;
        return goalLeft;
        
    }
    
    //main method
    public static void main(String args[])
    {
        //initialize
        Scanner in = new Scanner(System.in);
        System.out.println("How many meters did the runner run?");
        double mRan = in.nextDouble();
        
        System.out.println("What is his running goal in km?");
        double goalKm = in.nextDouble();
        
        double runGoalLeft = 0;
        double runKm = 0;
        
        //construct runner object
        RunnerV3 runner = new RunnerV3();
        
        runKm = runner.calckm(mRan); //call method 1
        runGoalLeft = runner.goalLeft(goalKm, runKm); //call method 2
        
        //System.out.println(runKm); test
        //System.out.println(runGoalLeft); test
        
        System.out.println();
        System.out.println("==========================Runner Progress==========================");
        //
        if (runGoalLeft > 0.0)
        {
            System.out.println();
            System.out.println("Progress:              Goal not achieved yet, runner is still running.");
            System.out.printf("Your Goal Was (km): %8.2f\n" , goalKm);
            System.out.printf("Amount Ran in Km:   %8.2f\n" ,runKm);
            System.out.printf("Amount left in Km:  %8.2f\n" ,runGoalLeft);
        }
        
        else if (runGoalLeft == 0 || runGoalLeft<0)
        {
            System.out.println();
            System.out.println("Progress:             The Runner has done it! Runner has met or surpassed their goal.");
            System.out.printf("Your Goal Was (km):%8.2f\n" , goalKm);
            System.out.printf("Amount Ran in Km:  %8.2f\n" ,runKm);
            System.out.printf("Extra km Ran:      %8.2f\n" , runGoalLeft * -1);
        }
    }
}
