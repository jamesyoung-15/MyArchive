
/**
Question 2:

Consider the following method. What is the value of recur("mouse", 3)? (5 points)

public static String recur(String str, int n)
{
     if(n >= str.length())
     {
          return str;
     }

     return str + recur(str.substring(n), n);
}
 */
public class q2
{
    public static String recur(String str, int n)
{
     if(n >= str.length())
     {
          return str;
     }

     return str + recur(str.substring(n), n);
}
    
    public static void main (String args[])
    {
        String str = "mouse";
        int n = 3;
        System.out.println(str.substring(n));
        System.out.println(recur(str, n));
    }
}
