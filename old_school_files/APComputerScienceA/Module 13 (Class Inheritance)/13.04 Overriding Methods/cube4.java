
/**
 * Cube class
 *
 * @author James Young
 * @version Dec 29
 */
public class cube4 extends box4
{
    public cube4(int x)
    {
       super(x, x, x);
    }
    
    public String toString(){
     return "Cube - " + getLength() + " x " + getWidth() + " x " + getHeight();
    }
}