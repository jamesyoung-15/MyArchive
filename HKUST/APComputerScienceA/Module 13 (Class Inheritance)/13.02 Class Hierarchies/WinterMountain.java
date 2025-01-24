
/**
 * Extends Mountain, gives mountain plus the temperature.
 *
 * @author James
 * @version Dec 24
 */
public class WinterMountain extends Mountain
{
    private double temperature;
    public WinterMountain(int l, int w, int m, double temp)
    {
        super(l, w, m);
        temperature = temp;
    }
    
    public double getTemp()
    {
        return temperature;
    }
}