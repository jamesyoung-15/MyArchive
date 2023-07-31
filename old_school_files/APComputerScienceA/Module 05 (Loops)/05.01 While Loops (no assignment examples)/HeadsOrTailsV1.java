import java.util.Scanner;
public class HeadsOrTailsV1
{
	public static void main(String[] args)
	{
	    // Declare and initialize variables
	    int heads = 0;
	    int tails = 0;
	    int flipCount = 0;
	    int totalFlips = 0;
	    double randNum = 0.0;
	    Scanner in = new Scanner(System.in);

	    // Input number of coins flipped
	    System.out.println("How many times will the coin be flipped? ");
	    totalFlips = in.nextInt();

	    // Simulate flipping coins.
	    while(flipCount < totalFlips)
	    {
	    	//Random value between 0.0 (inclusive) and 1.0 (exclusive)
	        randNum = Math.random();
	        System.out.print(flipCount + "\t" + randNum);

	        if(randNum < 0.5)          //change to < 0.3
	        {
	            heads++;
	            System.out.println("\t heads");
	        }
	        else
	        {
	            tails++;
	            System.out.println("\t tails");
	        }
	        flipCount++;

	    }//end while

	    //Output number of heads and number of tails
	    System.out.println();
	    System.out.println("Number of Heads = " + heads);
	    System.out.println("Number of Tails = " + tails);
	}
}
