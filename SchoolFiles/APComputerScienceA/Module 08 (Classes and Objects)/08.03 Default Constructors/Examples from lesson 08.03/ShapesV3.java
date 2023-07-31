
/**
 * The purpose of this program is to calculate the hypotenuse
 * of a triangle and its area. All calculations are done within
 * methods. An object is instantiated and all methods are invoked
 * on the object.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
public class ShapesV3
{
    //default constructor
    public ShapesV3()
    {
    }

    //calculate area of a triangle
    public double calcTriArea(int s1, int s2)
    {
        return s1 * s2 * 0.5;
    }
    //calculate the hypotenuse of a right triangle
    public double calcHypotenuse(int s1, int s2)
    {
        return Math.sqrt(Math.pow(s1, 2) + Math.pow(s2, 2));
    }

    //main method
    public static void main(String[] args)
    {
        //declaration of variables
        int side1, side2;
        double triArea, hypotenuse;

        //initialization of variables
        side1 = 10;
        side2 = 5;
        triArea = 0;
        hypotenuse = 0;

        ShapesV3 shapes = new ShapesV3();

        //call methods
        triArea = shapes.calcTriArea(side1, side2);
        hypotenuse = shapes.calcHypotenuse(side1, side2);

        //print results
        System.out.printf(" Triangle Area = %8.2f%n", triArea);
        System.out.printf(" Hypotenuse = %8.2f%n", hypotenuse);
    }//end main method
}//end class
