
/**
 * Extends Terrain, tells number of mountains.
 *
 * @author James
 * @version Dec 24
 */
public class Mountain extends Terrain
{
    private int mountains;
    public Mountain(int l, int w, int m)
    {
        super(l, w);
        mountains = m;
    }
    
    public int getMountains()
    {
        return mountains;
    }
}