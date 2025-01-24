
/**
 * Extends Terrain, tells number of cactuses.
 *
 * @author James
 * @version Dec 24
 */
public class Desert extends Terrain
{
    private int cactus;
    public Desert(int l, int w, int c)
    {
        super(l, w);
        cactus = c;
    }
    
    public int getCactus()
    {
        return cactus;
    } 
}
