/**
Question 5:
The calcCircleArea() method invoked within in the CircleStatsTester class is overloaded. Write the overloaded methods in the incomplete public CircleStats class. (10 points)

public class CircleStats
{
     public CircleStats()
     {
     }

      //...code goes here
}

public class CircleStatsTester
{
     public static void main(String[] args)
     {
         int diameter = 5;
         double radius = 2.5;
         CircleStats cStats = new CircleStats();

         System.out.println("The area = " + cStats.calcCircleArea(diameter));
         System.out.println("The area = " + cStats.calcCircleArea(radius));

     }
}

 */


class CircleStats 
{ 
    CircleStats() 
    { 
    } 
    public int calcCircleArea(int diameter) {
        double radius = diameter/2.0;
        return (int)(Math.PI * Math.pow(radius,2));
    }

    public double calcCircleArea(double radius) {
        return (Math.PI * (Math.pow(radius,2)));
    }
} 

public class q5 
{ 
    public static void main(String[] args) 
    { 
     int diameter = 5; 
     double radius = 2.5; 
     CircleStats cStats = new CircleStats(); 
     System.out.println("The area = " + cStats.calcCircleArea(diameter)); 
     System.out.println("The area = " + cStats.calcCircleArea(radius)); 
    } 
}