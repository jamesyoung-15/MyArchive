

 /**
 * This class tests extending classes from
 * Rectangle to Box.
 *
 * @author Poly Morphism
 * @version 06/13/17
 */

public class ShapesTester1
{
    public static void main (String []args)
    {
        Rectangle1 one = new Rectangle1(2, 4);
        Box1 two = new Box1(4,10,4);

        // Test Rectangle class
        System.out.println("The Rectangle:" );
        System.out.println("    length is " + one.getLength());
        System.out.println("    width is " + one.getWidth());
        System.out.println();

        // Test Box class
        System.out.println("The Box: ");
        System.out.println("    length is " + two.getLength());
        System.out.println("    width is " + two.getWidth());
        System.out.println("    height is " + two.getHeight());
    }
}
