
/**
 * Write a description of class correspondingEquation here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class correspondingEquation
{
    static int a = 3;
    static int b = 4;
    static int c = 5;
    
    // postcondition: returns x + y
    public static int add(int x, int y) 
    {
        return x+y;
    }

    // postcondition: return x * y
    public static int multiply(int x, int y) 
    {   
        return x*y;
    }
    
    public static int answer()
    {
        int answer = multiply(add(multiply(a, b), add(multiply(a, c), multiply(b, c))), 2);
        return answer;
    }
    
    public static void main(String[] args) 
    {
    
    int ab = answer();
    System.out.println(ab);
    
    }
}
