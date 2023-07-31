
/**
 * Extension of Terrain, tells number of trees.
 *
 * @author James
 * @version Dec 24
 */
public class Forest extends Terrain
{
    private int trees;
    public Forest(int l, int w, int t)
    {
        super(l, w);
        trees = t;
    }
    
    public int getTrees()
    {
        return trees;
    }
}