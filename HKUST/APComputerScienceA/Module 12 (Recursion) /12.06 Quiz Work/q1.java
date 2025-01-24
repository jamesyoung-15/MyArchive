
/**

Question 1:

Consider the following method. What is the value of recur("COMPUTER")? (5 points)

public static void recur(String str)
{
     int len = str.length();
     if(len > 1)
     {
          String temp = str.substring(0, len − 2);
          System.out.println(temp);
          recur(temp);
     }
}

 */


public class q1
{
    public static void recur(String str)
    {
     int len = str.length();
     if(len > 1)
     {
          String temp = str.substring(0, len - 2);
          System.out.println(temp);
          recur(temp);
     }
    }
    
    public static void main (String args[])
    {
        String str = "COMPUTER";
        recur(str);
    }
}
