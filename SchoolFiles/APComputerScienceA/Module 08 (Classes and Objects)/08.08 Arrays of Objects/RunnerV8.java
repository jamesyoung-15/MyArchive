
/**
 * Title: RunnerV8
 * Author: James Young
 * Date: October 4, 2019
 * Purpose: Expand your V7 object implementation class and client class to manage an array of data. 
 * Find the minimum, maximum, and averages of values.
 */
public class RunnerV8
{
    private double timeSec;
    private double speed;
    private double timeMin;
    private double combineMinSec;
    
    //constructor for objects
    RunnerV8 (double runnerTimeSec, double runnerTimeMin)
    {
         timeSec = runnerTimeSec;
         timeMin = runnerTimeMin;
         combineMinSec = 0.0;
         speed = 0.0;
    }
    
    //mutator combines user input of seconds and min
    public void combineTime()
    {
         double convertSec = timeSec/60.0; //convert to decimal
         combineMinSec = (convertSec + timeMin)/60.0; //add minutes to seconds
    }
    
    //getter returns run min and sec
    public double getcombineTime()
    {
        return combineMinSec;
    }
    
    //second mutator determines speed in km/h
    public void speedRunner()
    {
        speed = 5.0/combineMinSec;
    }
    
    //getter of speed
    public double getSpeedRunner()
    {
        return speed;
    }
    
    
    //getter runner min
    public double getRunMin()
    {
        return timeMin;
    }
    
    
    //getter runner sec
    public double getRunSec()
    {
        return timeSec;
    }
    
    
    public void setRunMin(double runnerTimeMin)
    {
         timeMin = runnerTimeMin;
    }

    public void setRunSec(double runnerTimeSec)
    {
         timeSec = runnerTimeSec;
    }
    
    public String toString()
    {
        return String.format("%14.5f %13.5f", timeSec, timeMin);
    }
}
