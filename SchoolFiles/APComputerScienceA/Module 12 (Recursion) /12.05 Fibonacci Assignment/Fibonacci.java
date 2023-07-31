/**
 * @title: 12.05 Fibonacci
 * @author: James Young
 * @date: November 12, 2019
 * @purpose: Write a program to recursively calculate the nth Fibonacci number.
 * 
 */

import java.util.Scanner;

//class to write my recursion
class FibonacciCalculations
{
    FibonacciCalculations()
    {
    }
    
    /**
     * @param n is the number user inputs
     * @return Fibonacci value after going through formula
     */
    
    public int fibonacciValue(int n) 
    {
        if (n <= 1) 
        {
            return n; //base condition
        }
        else
        {
            //fibonacci formula: F(n-1) + F(n-1)
            return fibonacciValue(n-1) + fibonacciValue(n-2); //recursive call
        }
    }
}

//public class for main method
public class Fibonacci
{
    public static void main(String[] args) 
    {
        //initialize
        Scanner in = new Scanner(System.in);
        FibonacciCalculations var = new FibonacciCalculations();
        
        
        System.out.println("Welcome to Fibonnacci number calculator. Please enter a number from 0-40 or the program will take a long time. Press Q to quit.");
	System.out.println("How many numbers would you like to calculate?");
        
	int numOfInputs = in.nextInt();
	
	
	for (int i = 0; i < numOfInputs; i ++)
	{
	System.out.println("Enter a number to calculate or press q to quit: ");
	String userInput = in.next(); //user either puts value or quits program, so use string
	if (userInput.equals("q")) //user command to quit
	{
	    break; //terminates loop
	} 
	else //will keep asking if user doesn't press q
	{
	    int userValue = Integer.parseInt(userInput); //convert string to integer from user input
	    int fibonacciVal = var.fibonacciValue(userValue); //get value from fibonacciValue method
	    System.out.println("Fibonacci Value: "+ fibonacciVal); //print value
	}
        }
    }
}
