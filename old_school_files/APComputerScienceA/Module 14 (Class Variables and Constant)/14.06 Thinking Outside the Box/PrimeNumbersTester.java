/**
 * Tests PrimeNumbers class and prints output.
 *
 * @author James Young
 * @version Jan 11, 2019
 */
import java.util.Scanner;
public class PrimeNumbersTester
{
    public static void main(String[] args)  
    {
        //create new scanner
        Scanner in = new Scanner(System.in);
        
        //asks user for lower and upper limits
        System.out.print("Enter the lower limit of prime numbers: ");
        int lowerLimit = in.nextInt();
        
        System.out.print("Enter the upper limit of prime numbers: ");
        int upperLimit = in.nextInt();
        
        //print primes between the range
        System.out.println("Prime Numbers between " + lowerLimit + " and " + upperLimit + " are: ");
        
        //construct object
        PrimeNumbers primeNumber = new PrimeNumbers(upperLimit, lowerLimit);
        
        //print number of primes
        int totalPrimeNumbers = primeNumber.calculatePrimes();
        System.out.println("Total number of primes between " + lowerLimit + " and " + upperLimit + " = " + totalPrimeNumbers);
    }
}
