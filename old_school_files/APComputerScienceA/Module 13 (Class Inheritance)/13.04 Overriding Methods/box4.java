/**
 * Box class
 *
 * @author James
 * @version Dec 29, 2019
 */

public class box4 extends rectangle4
{
    // instance variables 
    private int height;
    public box4(int l, int w, int h)
    {
        super(l, w);
        height = h;
    }

    public int getHeight()
    {
        return height;
    }

    public boolean equals(box4 b)
     {
        if (getLength() == b.getLength()){
            if (getWidth() == b.getWidth()){
                if(height == b.getHeight()){                    
                    return true;
                }
            }
        }
        return false;
     }
     
    public String toString(){
        return "Box - " + getLength() + " x " + getWidth() + " x " + getHeight();
    }
}