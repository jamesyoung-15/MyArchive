
/**
Question 3:

Consider the following method. What is the value of mystery(2)? (5 points)

public static void mystery(int n)
{
     if(n >= 10)
     {
          System.out.print(n + " ");
     }
     else
     {
          mystery(n + 2);
     }
}
 */
public class q3
{
    public static void mystery(int n)
    {
     if(n >= 10)
     {
          System.out.print(n + " ");
     }
     else
     {
          mystery(n + 2);
     }
    }
    
    public static void main (String args[])
    {
        mystery(2);
    }
}
