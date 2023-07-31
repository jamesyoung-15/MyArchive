import java.util.ArrayList;
public class RectangleTester
{
     public static void main(String[ ] args)
     {
          ArrayList<Rectangle> shapes = new ArrayList< Rectangle >();
          shapes.add(new Rectangle(1, 1));
          shapes.add(new Rectangle(2, 2));
          shapes.add(new Rectangle(3, 3));
          shapes.add(new Rectangle(4, 4));

          Rectangle dataRecord;


          
          int index = 3;
          dataRecord = shapes.get(index);
          dataRecord.calcRectArea();
          dataRecord.calcRectPerimeter();
          System.out.println("Area = " + dataRecord.getArea());
          System.out.println("Perimeter = " + dataRecord.getPerimeter());
          
     }
}