/**
Question 4:
Complete the following method that determines if a triangle is acute. The method returns true if a triangle can be formed by these three sides, and false otherwise.

A triangle is acute if the square of the longest side is less than sum of the squares of the other two sides. The method parameters are the lengths of the three sides in no particular order. (10 points)

// precondition: the three sides make a triangle
public static boolean isAcute(int side1, int side2, int side3)
{

}
 */

public class q4
{
    public static boolean isAcute(int side1, int side2, int side3)
    {
            int[] array = {side1, side2, side3};  
            
            int largest = array[0];
            int smallest = array[0];
            int secondLargest = array[0];
            for (int i = 0; i < array.length; i++) 
            {
            int value = array[i];
            if (value < smallest) 
            {
                smallest = value;
            } 
            else if (value > largest) 
            {
                secondLargest = largest;
                largest = value;
                
            }
            else if (value > secondLargest)
            {
                secondLargest = value;
            }
            }
            
        
            if (Math.pow(secondLargest,2) + Math.pow(smallest,2) > Math.pow(largest,2))
            {
            return true;
            }
            else 
            {
            return false;
            }
        
    }
    
    public static void main (String args[])
    {
        System.out.println(isAcute(4,6,7));
    }
}
