
/**
Question 5:

For the recursive method below, list the base case and the recursive statement, 
then show your work for solving a call to the recur() method using any parameter value 10 or greater. (10 points)

public static int recur(int n)
{
     if(n < 3)
     {
          return 2;
     }
     else
     {
          return recur(n / 3) + 1;
     }
}

 */
public class q5
{
    public static int recur(int n)
    {
     if(n < 3)
     {
          return 2;
     }
     else
     {
          return recur(n / 3) + 1;
     }
    }
    
    public static void main (String args[])
    {
        System.out.println(recur(12));
    }
}
