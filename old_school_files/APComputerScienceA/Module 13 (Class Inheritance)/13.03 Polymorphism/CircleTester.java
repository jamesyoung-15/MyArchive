/**
 * This class prints circle, cylinder, oval, and oval cylinder.
 * 
 * @author James
 * @version 29/12/19
 * 
 */


import java.util.ArrayList;
public class CircleTester {
	private static ArrayList<String> centers = new ArrayList<String>();
	private static ArrayList<String> objects = new ArrayList<String>();
	public static void printData() {
		for (int i = 0; i < centers.size(); i++) {
			System.out.println("For this " + objects.get(i) + " " + centers.get(i));
		}
	}
	public static void showCenter() {
		Circle2 circle = new Circle2(2, 4, 1);
		Cylinder2 cylinder = new Cylinder2(10, 15, 1, 3);
		Oval2 oval = new Oval2(25, 10, 3, 4);
		OvalCylinder2 ovalCylinder = new OvalCylinder2(40, 10, 3, 4, 2);
		centers.add(circle.getCenter());
		objects.add(circle.getName());
		centers.add(cylinder.getCenter());
		objects.add(cylinder.getName());
		centers.add(oval.getCenter());
		objects.add(oval.getName());
		centers.add(ovalCylinder.getCenter());
		objects.add(ovalCylinder.getName());
		printData();
	}
	public static void main(String [] args) {
		showCenter();
	}
}