
/**
 * Title: AnimalPopulation
 * 
 * Author: James Young
 * 
 * Date: July 24, 2019
 * 
 * Purpose: Write a program that uses the Monte Carlo sampling method 
 * to estimate the average number of animals observed 
 * before spotting one you are tracking within a particular ecosystem
 * 
 */

import java.util.Random;
import java.util.Scanner;
import java.io.IOException;
import java.io.File;
import java.io.PrintWriter;

public class AnimalPopulation
{
    // instance variables - replace the example below with your own
    public static void main(String args[]) throws InterruptedException, IOException 
    {
        //initialize variables
        Random rand = new Random();
        PrintWriter outFile = new PrintWriter(new File("trials.txt"));
        Scanner in = new Scanner(System.in);
        int counter = 0;
        int simulations = 0;
        int snakeGreen = 0;
        int snakeOthers = 0;
        
        //ask user for trials
        System.out.println("Welcome to the snake simulator. \n");
        System.out.println("How many trials would you like to simulate? (enter a number above 999):");
        simulations = in.nextInt();
        while(simulations < 1000){
            System.out.print("Please retry and enter number greater than 999: ");
            simulations = in.nextInt();
        }
    while(counter != simulations) 
            { 
            double rndm = rand.nextInt(10); //1 in 10 chance of spotting one
            if (rndm == 1) {
                snakeGreen++;
                counter++;
                //System.out.println("Numbers:" + rndm); //CHECK
            }
            else
            {
            snakeOthers++;
            counter++;
            //System.out.println("Numbers:" + rndm); //CHECK
            }
        } 
    //System.out.println("Number of green snakes:" + snakeGreen); //test
    //System.out.println("Number of other snakes:" + snakeOthers); //test
    //System.out.println("Number of sims: " + counter); //test
    System.out.println("\n");
    double avg = (double)counter/(double)snakeGreen; //calculate average
    System.out.println("Results:");
    System.out.println("The average number of snakes observed until spotting a green snake: "+avg);
    in.close();
    
    }
}
