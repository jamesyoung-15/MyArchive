
/**
 * This class instantiates Shapes objects with a default constructor.
 * It contains methods to calculate and return the area of a triangle and the
 * hypotenuse of a triangle.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
public class ShapesV9b
{
    /**
     * Default constructor for objects of type ShapesV9
     */
    public ShapesV9b()
    {
    }

    /**
     * Accessor method to calculate and return the area of a triangle.
     * @param s1 side 1 of a triangle.
     * @param s2 side 2 of a triangle,
     * @return the area of a triangle.
     * Precondition: s1 and s2 are positive values
     */
    public double calcTriArea(int s1, int s2)
    {
        return s1 * s2 * 0.5;
    }

    /**
     * Accessor method to calculate and return the hypotenuse of a triangle.
     * @param s1 side 1 of a triangle.
     * @param s2 side 2 of a triangle,
     * @return the hypotenuse of a triangle.
     * Precondition: s1 and s2 are positive values
     */
    public double calcHypotenuse(int s1, int s2)
    {
        return Math.sqrt(Math.pow(s1, 2) + Math.pow(s2, 2));
    }
}