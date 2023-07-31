
/**
 * Tests the rectangle, cube and box classes
 *
 * @author James Young
 * @version Dec 29, 2019
 */
public class tester
{
    public static void main(String[] args)
    {
        System.out.println();
        System.out.println("My Shapes: ");
        System.out.println();
        rectangle4 rectangle = new rectangle4(12, 20);
        box4 box = new box4(4, 4, 4);
        box4 box2 = new box4(4, 12, 8);
        cube4 cube = new cube4(4);
        square4 square = new square4(4);
        rhombus4 rhombus = new rhombus4(4);
        
        showEffectBoth(rectangle);
        showEffectBoth(box);
        showEffectBoth(box2);
        showEffectBoth(cube);
        showEffectBoth(square);
        showEffectBoth(rhombus);
        
        System.out.println();
        System.out.println("Tests for equality: ");
        System.out.println();
        
        System.out.print(box.toString());
        if (box.equals(cube)){
            System.out.print(" is same size as ");
        }
        else{
            System.out.print(" is not the same size as ");
        }
        System.out.print(cube.toString());
        System.out.println();
        
        //Checks Cube1 with Box1.
        System.out.print(box2.toString());
        if (box2.equals(cube)){
            System.out.print(" is same size as ");
        }
        else{
            System.out.print(" is not the same size as ");
        }
        System.out.println(cube.toString());
        
        System.out.print(rectangle.toString());
        if (rectangle.equals(square)){
            System.out.print(" is same size as ");
        }
        else{
            System.out.print(" is not the same size as ");
        }
        System.out.println(square.toString());
    }


    private static void showEffectBoth(rectangle4 o)
    {
        System.out.println(o);
        //System.out.println( "Rectangle: " + o  + o.getLength() + " x " + o.getWidth());
    }
}
