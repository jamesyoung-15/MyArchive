
/**
 * Calculates number of primes in a given range.
 *
 * @author James Young
 * @version Jan 11, 2019
 */
public class PrimeNumbers
{
    //intialize variables    
    private int upperLimit;
    private int lowerLimit;
    public int counter;
    
    //constructor
    public PrimeNumbers(int upperLimit, int lowerLimit){
            this.upperLimit = upperLimit;
            this.lowerLimit = lowerLimit;
    }           
    
    //method calculates number of primes and prints primes, returns total primes in range
    public int calculatePrimes(){
        //initalize variables
        int i = 0;
        int j = 0;
        int count = 0;
        int counter = 0;
        
        //loop for calculating primes and printing primes
        for (i = lowerLimit; i <= upperLimit;i++) {
            for(j = 2; j < i; j++)
            {
                if(i % j == 0)
                {
                    count = 0;
                    break;
		}
		else
		{
		    count = 1;
		}
            }
            if(count == 1){
                System.out.println(i); //prints each prime encountered
                counter ++;
            }
        }
        return counter;
    }
}
