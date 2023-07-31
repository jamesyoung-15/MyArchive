
/**
 * This class instantiates shapes objects with four private instance variables.
 * It contains mutator methods to calculate the area of a triangle and the
 * hypotenuse of a triangle. There are getter methods for each private instance
 * variable.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
//import java.util.ArrayList;
public class ShapesV11
{
    //declaration of private instance variables
    private int mySide1, mySide2;
    private double myArea, myHypotenuse;


    //constructor for objects of type ShapesV8
    public ShapesV11(int s1, int s2)
    {
        mySide1 = s1;
        mySide2 = s2;
        myArea = 0.0;
        myHypotenuse = 0.0;
    }

    //mutator method to calculate the area of a triangle
    public double calcTriArea()
    {
        myArea = mySide1 * mySide2 * 0.5;
        return myArea;
    }

    //getter method to return the value of the area of a triangle
    public double getTriArea()
    {
        return myArea;
    }

    //mutator method to calculate the hypotenuse  of a triangle
    public void calcHypotenuse()
    {
        myHypotenuse = Math.sqrt(Math.pow(mySide1, 2) + Math.pow(mySide2, 2));
    }

    //getter method to return the value of the hypotenuse  of a triangle
    public double getHypotenuse()
    {
        return myHypotenuse;
    }

    //getter method to return the value of side 1 of a triangle
    public int getSide1()
    {
        return mySide1;
    }

    //getter method to return the value of side 2 of a triangle
    public int getSide2()
    {
        return mySide2;
    }

    // returns a String of the object's values. The format() method is similar to printf().
    public String toString()
    {
        return String.format("%12d %9d %14.1f %13.1f", mySide1,
                                                       mySide2,
                                                       myHypotenuse,
                                                       myArea);
    }
}