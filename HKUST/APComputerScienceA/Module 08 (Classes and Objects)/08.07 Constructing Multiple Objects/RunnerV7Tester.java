
/**
 * Title: RunnerV7 Tester
 * Purpose: Convert your V3 object class to V7 implementation and 
 * client classes and instantiate multiple objects.
 * Author: James Young
 * Date: Oct 2 2019
 */

import java.util.Scanner;
public class RunnerV7Tester
{
    public static void main (String args[])
    {
        //initialize

        Scanner in = new Scanner(System.in);
        
        System.out.println("What's the first runner's first name?");
        String name1 = in.nextLine();
        
        System.out.println("How many meters did " +name1+" run?");
        double mRan = in.nextDouble();
        
        System.out.println("What is " +name1+ " running goal in km?");
        double goalKm = in.nextDouble();
        
        System.out.println("What's the second runner's first name?");
        String name2 = in.next();
        
        System.out.println("How many meters did " +name2+" run?");
        double mRan2 = in.nextDouble();
        
        System.out.println("What is " +name2+ " running goal in km?");
        double goalKm2 = in.nextDouble();
        
        double runGoalLeft = 0;
        double runKm = 0;
        double runGoalLeft2 = 0;
        double runKm2 = 0;
        
        //construct objects
        RunnerV7 runner1 = new RunnerV7(mRan, goalKm);
        RunnerV7 runner2 = new RunnerV7 (mRan2, goalKm2);
        
        //object 1
        runKm = runner1.calckm(); //call method 1
        runGoalLeft = runner1.goalLeft(); //call method 2
        
        //object 2
        runKm2 = runner2.calckm(); //call method 1
        runGoalLeft2 = runner2.goalLeft(); //call method 2
        
        System.out.println(runKm); //test
        System.out.println(runGoalLeft); //test
        
        System.out.println();
        System.out.println("========================== Progress for "+name1+" ==========================");
        //
        if (runGoalLeft > 0.0)
        {
            System.out.println();
            System.out.println("Progress:              Goal not achieved yet, runner is still running.");
            System.out.printf("Goal in (km):       %13.2f\n",   goalKm);
            System.out.printf("Amount Ran in Km:   %13.2f\n" ,runKm);
            System.out.printf("Amount left in Km:  %13.2f\n" ,runGoalLeft);
        }
        
        else if (runGoalLeft == 0 || runGoalLeft<0)
        {
            System.out.println();
            System.out.println("Progress:             " +name1+ " has met or surpassed their goal.");
            System.out.printf("Goal in (km):      %13.2f\n",  goalKm);
            System.out.printf("Amount Ran in Km:  %13.2f\n" ,runKm);
            System.out.printf("Extra km Ran:      %13.2f\n" , runGoalLeft * -1);
        }
        
        System.out.println("========================== Progress for "+name2+" ==========================");
        
        if (runGoalLeft2 > 0.0)
        {
            System.out.println();
            System.out.println("Progress:               Goal not achieved yet, runner is still running.");
            System.out.printf("Goal in (km):       %13.2f\n",  goalKm);
            System.out.printf("Amount Ran in Km:   %13.2f\n" ,runKm);
            System.out.printf("Amount left in Km:  %13.2f\n" ,runGoalLeft);
        }
        
        else if (runGoalLeft2 == 0 || runGoalLeft2<0)
        {
            System.out.println();
            System.out.println("Progress:             "+name2+" has met or surpassed their goal.");
            System.out.printf("Goal in (km):      %13.2f\n",  goalKm);
            System.out.printf("Amount Ran in Km:  %13.2f\n" ,runKm);
            System.out.printf("Extra km Ran:      %13.2f\n" , runGoalLeft * -1);
        }
    }
}
