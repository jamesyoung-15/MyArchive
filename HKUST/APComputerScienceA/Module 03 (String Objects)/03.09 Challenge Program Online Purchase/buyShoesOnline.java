/**
 * Name: James Young
 * Purpose: Write a program to simulate an online purchase by 
 * asking the user for input and displaying a receipt.
 * Date: July 14, 2019
 */

import java.util.Scanner;
public class buyShoesOnline
{
    public static void main (String args [])
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Welcome to buyshoessonline.com.");
        System.out.println("Please enter your first and last name:  ");
        String firstName = in.next();
        String lastName = in.nextLine();
        System.out.println("Please enter today's date (mm/dd/yy):  ");
        String todayDate = in.next();
        System.out.println("What shoes would you like to buy? (enter shoe name and brand):  ");
        String shoesWanted = in.next();
        String shoesWantedName = in.nextLine();
        System.out.println("Please enter the price ($): ");
        double shoesPrice = in.nextDouble();
        System.out.println("How many pairs would you like: ");
        int shoeQuantity = in.nextInt();
        System.out.println("Please enter your debit card number （######-###-####）: ");
        String creditCard = in.next();
        System.out.println("Please enter your pin (#####）: ");
        String pinNumber = in.next();
        System.out.println("***************************************************************************\n");
        System.out.println("***************************************************************************\n");
        System.out.println("Your e-Recipt: \n");
        System.out.println(todayDate);
        System.out.println("Order Code: J5123A7 \n");
        System.out.println("Name: " + firstName + lastName);
        String newCreditCardNumber = creditCard.substring(10);
        System.out.println("Account: ######-###-" + newCreditCardNumber);
        System.out.println("Shoe name: " + shoesWanted + shoesWantedName);
        System.out.println("Price of shoes: " + shoesPrice);
        System.out.println("Number of pairs ordered: " + shoeQuantity);
        double totalShoePrice = shoesPrice * shoeQuantity;
        System.out.println("$" + totalShoePrice + " has been debited to your account. \n ");
        System.out.println("Thank you for ordering from buyshoessonline.com.");
        System.out.println("***************************************************************************\n");
        System.out.println("***************************************************************************");
    }
}
