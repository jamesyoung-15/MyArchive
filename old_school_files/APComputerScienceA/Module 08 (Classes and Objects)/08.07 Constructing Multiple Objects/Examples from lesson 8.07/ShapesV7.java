
/**
 * This class calculates information about geometric shapes.
 *
 * @author Alan Kay
 * @version 06/08/17
 */
public class ShapesV7
{
    private int mySide1;
    private int mySide2;

    ShapesV7(int s1, int s2)
    {
        mySide1 = s1;
        mySide2 = s2;
    }

    public double calcTriArea()
    {
        return mySide1 * mySide2 * 0.5;
    }

    public double calcHypotenuse()
    {
        return Math.sqrt(Math.pow(mySide1, 2) + Math.pow(mySide2, 2));
    }
}
