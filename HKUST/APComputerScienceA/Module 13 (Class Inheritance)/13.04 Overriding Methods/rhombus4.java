/**
 * Rectangle class
 *
 * @author James Young
 * @version (a version number or a date)
 */

public class rhombus4 extends rectangle4
{
    private int side;

    
    public rhombus4(int y)
    {
        super (y,y);
        side = y;
    }

    
    public int getLength()
    {
        return side;
    }
    public int getWidth()
    {
        return side;
    }
    
    public boolean equals(square4 s)
    {
        if (side == s.getLength()){
            return true;
        }
        return false;
    }
    
    public String toString(){
        return "Rhombus - " + side + " x " + side;
        }
    }