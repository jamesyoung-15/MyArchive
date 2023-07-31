
/**
 * This class tests the ShapesV9b class.
 *
 * A single instance of the ShapesV9b class is used to invoke the methods
 * and calculate the area and hypotenuse for two triangles.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
public class ShapesV9bTester
{
    public static void main(String[] args)
    {
        //declaration of variables
        int side1A = 10;
        int side2A = 5;
        int side1B = 7;
        int side2B = 13;
        double hypotenuseA, triAreaA;
        double hypotenuseB, triAreaB;

        //Invoke default constructor
        ShapesV9b shape = new ShapesV9b();

        //call methods
        triAreaA = shape.calcTriArea(side1A, side2A);
        hypotenuseA = shape.calcHypotenuse(side1A, side2A);

        triAreaB = shape.calcTriArea(side1B, side2B);
        hypotenuseB = shape.calcHypotenuse(side1B, side2B);


        //print results
        System.out.println("        Side 1    Side 2     Hypotenuse       Area");

        System.out.printf("%12d %9d %14.1f %13.1f%n", side1A, side2A, hypotenuseA, triAreaA);
        System.out.printf("%12d %9d %14.1f %13.1f%n", side1B, side2B, hypotenuseB, triAreaB);

    }
}