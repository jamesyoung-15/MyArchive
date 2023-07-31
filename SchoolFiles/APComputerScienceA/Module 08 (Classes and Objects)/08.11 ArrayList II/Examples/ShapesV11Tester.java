
/**
 * This class tests the ShapesV11 class.
 * An ArrayList of ShapesV11 objects is created.
 * The add() method is used to add the objects to the ArrayList as they are instantiated.
 *
 * A for loop is used to call the calcTriArea() and calcHypotenuse() methods on each object in the ArrayList.
 * A second for loop is used to print the values of the instance variables for each object.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
import java.util.ArrayList;
public class ShapesV11Tester
{
    public static void main(String[] args)
    {
        ArrayList<ShapesV11> shapes = new ArrayList<ShapesV11>();
        shapes.add(new ShapesV11(10,  5));
        shapes.add(new ShapesV11( 7, 13));
        shapes.add(new ShapesV11( 2,  4));
        shapes.add(new ShapesV11(28,  3));

        ShapesV11 dataRecord;                   //creates a new dataRecord object of type ShapesV11

        for(int index = 0; index < shapes.size(); index++)
        {
            dataRecord = shapes.get(index);
            dataRecord.calcTriArea();
            dataRecord.calcHypotenuse();
        }

        //print table headings
        System.out.println("                     Triangles                     ");
        System.out.println("Number     Side 1    Side 2       Hypotenuse       Area");

        //call methods
        for(int index = 0; index < shapes.size(); index++)
        {
            System.out.println("  " + index + " " +  shapes.get(index)); //The toString() method prints object
        }
    }//end main
}//end class
