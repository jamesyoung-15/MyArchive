
/**
 * This class tests the ShapesV8 class.
 *
 * An array of shapes objects is created.
 *
 * A for loop is used to call the calcTriArea() and calcHypotenuse() methods on each object.
 * A second for loop is used to print the values of the instance variables for each object.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
public class ShapesV8Tester
{
    public static void main(String[] args)
    {

        //initialization of array of objects
        ShapesV8[] shapes = {new ShapesV8(10, 5),
                             new ShapesV8(7, 13)};



        //call methods
        for(int index = 0; index < shapes.length; index++)
        {
            shapes[index].calcTriArea();
            shapes[index].calcHypotenuse();
        }

        //print results after calculating area and hypotenuse
        System.out.println("Output results AFTER methods are invoked.\n");
        System.out.println("                     Triangles                     ");
        System.out.println(" Number     Side 1    Side 2       Hypotenuse       Area");
        for(int index = 0; index < shapes.length; index++)
        {
            System.out.println("  " + index + " " +  shapes[index]); //The toString() method prints object
        }

        System.out.println();
        System.out.println();
    
        System.out.println("Output after manipulating array.\n");
        int i = 1;
        int sideA = shapes[i - 1].getSide1();
        shapes[i].setSide1( shapes[i - 1].getSide2());
        shapes[i].calcTriArea();
        shapes[i].calcHypotenuse();

        System.out.println(" Number     Side 1    Side 2       Hypotenuse       Area");
        for(int index = 0; index < shapes.length; index++)
        {
            System.out.printf("%4d %12d %9d %14.1f %13.1f%n", index,
                                                              shapes[index].getSide1(),
                                                              shapes[index].getSide2(),
                                                              shapes[index].getHypotenuse(),
                                                              shapes[index].getTriArea());
        }
    
    }
}