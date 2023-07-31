
/**
Question 4:

Consider the following method. What is the result of mystery(3)? (5 points)

public static int mystery(int n)
{
     if (n < 5)
     {
          return mystery(n + 1) − 2;
     }

     return n − 1;
}


 */
public class q4
{
    public static int mystery(int n)
    {
     if (n < 5)
     {
          return mystery(n + 1) - 2;
     }

     return n - 1;
    }
    
     public static void main (String args[])
    {
        System.out.println(mystery(3));
    }
}
