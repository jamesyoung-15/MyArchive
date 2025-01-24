

 /**
 * This class defines a Box object by extending
 * Rectangle and includes height.
 *
 * @author Poly Morphism
 * @version 06/13/17
 */

public class Box1 extends Rectangle1
{
    // instance variables
    private int height;

    // Constructor for objects of class Box
    public Box1(int l, int w, int h)
    {
        // call superclass
        super(l, w);

        // initialize instance variables
        height = h;
    }

    // return the height
    public int getHeight()
    {
        return height;
    }
}
