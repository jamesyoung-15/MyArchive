/**
 * 9.04 Challenge Program Catapult 
 * 
 * Purpose: Write a program to calculate the trajectory of a projectile based on launch angles and launch velocities.
 * 
 * @author James Young
 * @version October 27, 2019
 */


public class catapult {
    //instance varibles
    private double velocity, degrees, distance;
    
    //constructor
    public catapult(double mph, double deg) {
        velocity = mph;
        degrees = deg;
    }
    
    /**
     * getter method returns velocity (no param)
     */
    
    public double getVelocity(){
        return velocity;
    }
    
    /**
     * getter method returns degrees (no param)
     */
    
    public double getDegrees(){
        return degrees;
    }

    /**
     * mutator method calculates distance using equation (no param)
     * equation given in instructions (R = (v^2*sin(2theta))/g)
     * value of g is 9.8 m/s/s
     */
    
    public void calcDistance(){
        distance = (Math.pow(velocity, 2) * Math.sin( 2 * Math.toRadians(degrees)) / 9.8);
    }
        
    /**
     * getter method returns calculated distance (no param)
     */
    
    public double getDistance()
    {
        return distance;
    }

}