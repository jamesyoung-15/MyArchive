
/**
 * The purpose of this program is to illustrate the use of the
 * Math class ranomd() method.
 *
 * @author Charles Babbage
 * @version 06/05/17
 */
public class RandomMethodDemo
{
    public static void main(String [] args)
    {
        double randomNumber;
        int counter = 0;

        while(counter < 10)
        {
            randomNumber = Math.random();
            System.out.println(counter + ":  " + randomNumber);
            counter ++;
        }//end of while loop
    }//end of main method
}//end of class


/*
 *

if( randomNumber > 0.4 && random number < 0.6 )
{

}
 */