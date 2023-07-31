
/**
 * Title: RunnerV7
 * Purpose: Convert your V3 object class to V7 implementation and 
 * client classes and instantiate multiple objects.
 * Author: James Young
 * Date: Oct 2 2019
 */
public class RunnerV7
{
    private double metersRan;
    private double myGoalinKm;
    private double kilometersRan;
    
    RunnerV7 (double mRn, double goalKm)
    {
         metersRan = mRn;
         myGoalinKm = goalKm;
    }
    
    public double calckm()
    {
         kilometersRan = (double)metersRan/1000.0;
         return kilometersRan;
    }
    
    //second method determines if you need to keep running
    public double goalLeft()
    {
        return (double)myGoalinKm - (double)kilometersRan; 
    }
    
}
