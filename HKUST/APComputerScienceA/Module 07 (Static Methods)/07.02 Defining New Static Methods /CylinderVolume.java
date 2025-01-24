/**
 * This program uses methods to calculate the volume of a cylinder.
 * Also illustrates use of Math class methods.
 *
 * @author Grace Hopper
 * @version 06/07/17
 */
public class CylinderVolume
{
    //calculate the area of a circle
    public static double calcCircleArea(double r)
    {
        return Math.PI * Math.pow(r, 2);
    }

    //calculate the volume of a cylinder
    public static double calcCylinderVol(double a, double h)
    {
        return a * h;
    }

    public static void main(String[ ] args)
    {
        // Define and initialize variables
        double radius = 1.0;
        double height = 10.0;

        // Call methods to perform calculations and assign to variables
        double area = calcCircleArea(radius);
        double cylinderVol = calcCylinderVol(area, height);

        // Display output
        System.out.printf("Area of Circle = %5.2f%n", area);
        System.out.printf("Cylinder Volume = %5.2f%n", cylinderVol);


     }
}
