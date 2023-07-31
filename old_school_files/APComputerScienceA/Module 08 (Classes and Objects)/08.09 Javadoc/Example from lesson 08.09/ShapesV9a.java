
/**
 * This class instantiates shapes objects with four private instance variables.
 * It contains mutator methods to calculate the area of a triangle and the
 * hypotenuse of a triangle.  There are getter methods for each private instance
 * variable. Private instance variables include mySide1, mySide2, myArea,
 * and myHypotenuse.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
public class ShapesV9a
{
    //declaration of private instance variables
    private int    mySide1;          //side 1 of a triangle
    private int    mySide2;          //side 2 of a triangle
    private double myArea;           //area of a triangle
    private double myHypotenuse;     //hypotenuse of a triangle

    /**
     * Constructor for objects of type ShapesV9
     * @param s1 side 1 of a triangle
     * @param s2 side 2 of a triangle
     * Precondition: s1 and s2 are positive values
     */
    public ShapesV9a(int s1, int s2)
    {
        mySide1 = s1;
        mySide2 = s2;
        myArea = 0.0;
        myHypotenuse = 0.0;
    }

    /**
     * Mutator method to calculate the area of a triangle (no parameters).
     */
    public void calcTriArea()
    {
        myArea = mySide1 * mySide2 * 0.5;
    }

    /**
     * Getter method to return the value of the area of a triangle (no parameters).
     * @return the area of a triangle.
     */
    public double getTriArea()
    {
        return myArea;
    }

    /**
     * Mutator method to calculate the hypotenuse of a triangle (no parameters).
     */
    public void calcHypotenuse()
    {
        myHypotenuse = Math.sqrt(Math.pow(mySide1, 2) + Math.pow(mySide2, 2));
    }

    /**
     * Getter method to return the value of the hypotenuse of a triangle (no parameters).
     * @return the hypotenuse of a triangle.
     */
    public double getHypotenuse()
    {
        return myHypotenuse;
    }

    /**
     * Getter method to return the value of side 1 of a triangle (no parameters).
     * @return side 1 of a triangle.
     */
    public int getSide1()
    {
        return mySide1;
    }

    /**
     * Getter method to return the value of side 2 of a triangle (no parameters).
     * @return side 2 of a triangle.
     */
    public int getSide2()
    {
        return mySide2;
    }
}