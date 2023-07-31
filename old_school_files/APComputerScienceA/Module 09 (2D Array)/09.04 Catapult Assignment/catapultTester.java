/**
 * 9.04 Challenge Program Catapult 
 * 
 * Purpose: Write a program to calculate the trajectory of a projectile based on launch angles and launch velocities.
 * 
 * @author James Young
 * @version October 27, 2019
 */

public class catapultTester {

    public static void main(String[] args) {
        
        
        //initialize
        catapult[][] catapultsArray = new catapult[7][7]; //2D array w/ 7 row 7 columns        
        double [] velocityArray = {20, 25, 30, 35, 40, 45, 50};
        double [] degreesArray = {25, 30, 35, 40, 45, 50, 55};
        
        //get values from velocity and degree array
        for(int row = 0; row < catapultsArray.length; row++) {
            double velocity = velocityArray[row];
            for(int column = 0; column <catapultsArray.length; column++)
            {
                //call method
                catapultsArray[row][column] = new catapult(velocity, degreesArray[column]);
            }
        }
        
        //print table
        System.out.println("                      Projectile Distance (meters)                      ");
        System.out.println("M/S   25 Deg   30 Deg   35 Deg   40 Deg   45 Deg   50 Deg   55 Deg    ");
        System.out.println();
        System.out.println("======================================================================");
        
        //print values from 2d array
        for (catapult[] catapult1 : catapultsArray) {
            System.out.printf("%2.0f ", catapult1[0].getVelocity());
            for (int column = 0; column < catapultsArray.length; column++) {
                catapult1[column].calcDistance();
                System.out.printf("%8.1f ", catapult1[column].getDistance());
            }
            System.out.printf("\n");
        }
    }

}