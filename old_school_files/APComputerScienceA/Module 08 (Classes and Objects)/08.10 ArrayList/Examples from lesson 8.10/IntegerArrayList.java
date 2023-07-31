
/**
 * This class adds randomly selected integers to an ArrayList
 * and then prints the list.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
import java.util.ArrayList;
public class IntegerArrayList
{
    public static void main(String[] args)
    {
        ArrayList<Integer> intList = new ArrayList<Integer>();  //declare an ArrayList
        int rndNumber = 0;
        int position = 0;

        for(int i = 0; i < 50; i++)                            //iterate a loop from 0 to 49
        {
            rndNumber = (int)(Math.random() * 100);             //generate a random number from 0 to 99
            intList.add(rndNumber);                             //add the random number to the next index position
        }

        System.out.println("Random integers in the list: ");
        System.out.println("List size: " + intList.size());     //prints the current number of elements in the list
        System.out.println(intList);                            //print a list of all elements in the ArrayList
        System.out.println();


        for(int i = 0; i < intList.size(); i++)                 //iterate a through each index position in the ArrayList
        {
            if(intList.get(i) > 25)                             //get the object from the ArrayList that is in index
            {                                                   //position i and check to see if its value is greater than 25
                intList.remove(i);                              //if it is, remove the object at index position i from the ArrayList.
                i--;                                            //decrement the index counter by one
            }                                                   //why is this necessary?  remove it and see what happens.
        }
        System.out.println("List with values greater than 25 removed: ");
        System.out.println("List size: " + intList.size());     //prints the current number of elements in the list
        System.out.println(intList);                            //print a list of all elements in the ArrayList
        System.out.println();


        for(int i = 0; i < intList.size(); i++)                 //iterate through each index position in the ArrayList
        {
            rndNumber = (int)(Math.random() * -100);            //generate a random number from 0 to -99
            intList.set(i, rndNumber);                          //set the new numbers in each index position in the ArrayList
        }

        System.out.println("List of negative random numbers from 0 to -99. ");
        System.out.println("List size: " + intList.size());     //prints the current number of elements in the list
        System.out.println(intList);                            //print a list of all elements in the ArrayList
        System.out.println();


        for(int n = 0; n < 10; n++)                             //for loop to iterate for a count of 10
        {
            rndNumber = (int)(Math.random() * 100) + 100;       //what's the smallest random number that can be chosen if 100 is added to every one?
            position = (int)((Math.random() * intList.size())); //what's the range of values position can take on if every random number is multiplied times the size of the list?
            intList.add(position, rndNumber);                   //where is each new random number added?
        }                                                       //what happens if you change add() to set()?

        System.out.println("An expanded list of random numbers: ");
        System.out.println("List size: " + intList.size());     //prints the current number of elements in the list
        System.out.println(intList);                            //print a list of all elements in the ArrayList
        System.out.println();
    }
}
