
/**
 * Write a description of class rectangle here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Rectangle
{
    private double width, length, area, p;
    Rectangle(double w, double l)
    {
        width = w;
        length = l;
        area = 0.0;
        p = 0.0;
    }
    
    public void calcRectArea()
    {
        area = width * length;
    }
    
    public double getArea()
    {
        return area;
    }
    
    
    public void calcRectPerimeter()
    {
        p = (2*(width + length));
    }
    
    public double getPerimeter()
    {
        return p;
    }
    

}
