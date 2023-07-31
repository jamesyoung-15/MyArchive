
/**
 * This program demonstrates the creation of two objects, each containing
 * its own private instance data.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
public class ShapesV7Tester
{
	public static void main(String[] args)
    {
        //declaration of variables
        int side1A, side2A, side1B, side2B;
        double hypotenuseA, triAreaA, hypotenuseB, triAreaB;

        //initialization of variables
        side1A = 10; side2A =  5; triAreaA = 0.0; hypotenuseA = 0.0;
        side1B =  7; side2B = 13; triAreaB = 0.0; hypotenuseB = 0.0;

        //create object
        ShapesV7 shapes1 = new ShapesV7(side1A, side2A);
        ShapesV7 shapes2 = new ShapesV7(side1B, side2B);

        //call methods
        triAreaA = shapes1.calcTriArea();
        hypotenuseA = shapes1.calcHypotenuse();
        triAreaB = shapes2.calcTriArea();
        hypotenuseB = shapes2.calcHypotenuse();

        //print results
        System.out.println("                     Triangles                     ");
        System.out.println("        Side 1      Side 2    Hypotenuse     Area");

        System.out.printf("%12d %11d %13.2f %11.2f%n", side1A, side2A, hypotenuseA, triAreaA);
        System.out.printf("%12d %11d %13.2f %11.2f%n", side1B, side2B, hypotenuseB, triAreaB);
    }
}

