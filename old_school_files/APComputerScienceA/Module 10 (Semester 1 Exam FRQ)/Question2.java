/**
 
 
@author: James Young
@date: Nov 11, 2019
@assignment: Question 2 of APCSA Semester 1 Exam FRQ

Question 2:

Complete the constructors and the arcLength method of the Circle class.(7 points)

  public class Circle
  {

      private double radius;

      //constructors
      // postcondition: the instance variable is initialized
      public Circle(double rad)
      {

      }

      // postcondition: the instance variable is initialized
      public Circle(int diameter)
      {

      }

      // postcondition: returns the arcLength of a circle with radius equal to this
      // circle's radius, according to the formula: (PI / 180) * r * deg,
      // where PI is the value of pi (3.1415...), r is the radius of the circle,
      // and deg is the angle in degrees passed as the parameter.
      // Use the Math class constant to represent the value of pi.
      public double arcLength(double degree)
      {

      }

      // There may be other instance variables, constructors,
      // and methods that are not shown.

  }
 */


public class Question2

  {

      private double radius;

      //constructors
      // postcondition: the instance variable is initialized
      public Question2(double rad)
      {

             radius = rad;

      }

      // postcondition: the instance variable is initialized
      public Question2(int diameter)
      {

           radius = diameter/2.0;

      }

      // postcondition: returns the arcLength of a circle with radius equal to this
      // circle's radius, according to the formula: (PI / 180) * r * deg,
      // where PI is the value of pi (3.1415...), r is the radius of the circle,
      // and deg is the angle in degrees passed as the parameter.
      // Use the Math class constant to represent the value of pi.
       public double arcLength(double degree)

      {

            double arcLength = (Math.PI/180.0) * radius * degree;

            return arcLength;                 

      }

      // There may be other instance variables, constructors,
      // and methods that are not shown.

  }     