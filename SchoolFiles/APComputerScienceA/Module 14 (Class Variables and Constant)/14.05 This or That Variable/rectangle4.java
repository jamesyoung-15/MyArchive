/**
 * Rectangle class
 *
 * @author James Young
 * @version (a version number or a date)
 */

public class rectangle4
{
    private int length;
    private int width;

    
    public rectangle4(int l, int w)
    {
        this.length = l;
        this.width = w;
    }

    
    public int getLength()
    {
        return length;
    }
    public int getWidth()
    {
        return width;
    }
    
    public boolean equals(rectangle4 r)
    {
        if (length == r.getLength()){
            if (width == r.getWidth()){
                return true;
            }
        }
        return false;
    }
    
    public String toString(){
        return "Rectangle - " + length + " x " + width;
        }
    }