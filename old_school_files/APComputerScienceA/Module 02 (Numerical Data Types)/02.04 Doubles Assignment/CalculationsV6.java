
/**
 * Author: James Young
 * Purpose: Revise Calculation V5 and replace all decimal values with double variables and add three new arithmetic expressions.
 * Date: June 20, 2019
 */
public class CalculationsV6
{
    public static void main(String[ ] args)
    {
// Declare double variables
double dNum1, dNum2, dNum3, dNum4;
    dNum1 =42.21; 
    dNum2 = 3.21;
    dNum3 = 2.5;
    dNum4 = 0.5;

//declare int variables
int iNum1 = 18%4;
int iNum2 = 6;

//addition
System.out.println("Addition (from Calculation V5)");
System.out.println(iNum1 + " + " + iNum2 + " = " + (iNum1 + iNum2));
System.out.println(dNum1 + " + " + dNum2 + " = " + (dNum1 + dNum2));

//Own arithmetic expressions
System.out.println();
System.out.println("Three of my own arithmetic expressions");
System.out.println("First Expression: " + dNum3 + " * " + dNum1 + " / " + dNum2 + " = " + (dNum3 * dNum1 / dNum2));
System.out.println("Second Expression: (" + dNum1 + " - " + dNum2 + " )* " + dNum4 + " = " + ((dNum1 - dNum2) * dNum4));
System.out.println("Third Expression: (" + dNum1 + " % " + dNum4 + " )+ " + dNum3 + " = " + ((dNum1 % dNum4) + dNum3));

    }
}