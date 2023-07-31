/**
 * Title: 7.01 Math Class Methods CirclePoints
 * Author: James Young
 * Purpose: Calculate the (x, y) coordinates of points on a circle of radius 1.0.
 */

public class CirclePoints
{
      public static void main(String[ ] args)
    {
        //initialize
        double radius = 1.0;
        double x1 = 1.1; //not 1.0 as x-=0.1 in loop
        double y = 0.0;

        //print format
        System.out.println("Points on a Circle with a Radius of " + radius);
        System.out.println("   x1        y1              x1         y2");
        System.out.println("********************************************");
        for(int counter = 0; counter < 21; counter++){ //20 loops
            x1-= 0.1;
            double pointY = Math.sqrt((Math.pow(radius, 2) - Math.pow(x1, 2)));
            System.out.printf("%5.2f     %5.2f            %5.2f     %5.2f\n" , x1, pointY, x1, -1 * pointY);
        }
    }
}