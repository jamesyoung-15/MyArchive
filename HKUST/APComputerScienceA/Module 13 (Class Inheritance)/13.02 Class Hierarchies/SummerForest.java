
/**
 * Extends Mountain, gives forest plus the temperature.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class SummerForest extends Forest
{
    private double temperature;
    public SummerForest(int l, int w, int t, double temp)
    {
        super(l, w, t);
        temperature = temp;
    }
    
    public double getTemp()
    {
        return temperature;
    }
}
