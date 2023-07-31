
/**
 * The purpose of this program is to demonstrate nested
 * for loops.
 *
 * @author Charles Babbage
 * @version 06/05/17
 */

public class Odometer
{
    public static void main(String[] args)
    {
        for(int pos4 = 0; pos4 <= 9; pos4++) //loop for 1000s position
            for(int pos3 = 0; pos3 <= 9; pos3++) //loop for 100s position
                for(int pos2 = 0; pos2 <= 9; pos2++) //loop for 10s position
                    for(int pos1 = 0; pos1 <= 9; pos1++) //loop for 1s position
                        System.out.println(pos4 + "" + pos3 + "" + pos2 + "" + pos1);
    } //end main
}//end class
