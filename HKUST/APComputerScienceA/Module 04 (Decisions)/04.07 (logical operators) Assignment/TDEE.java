/**
 * Project: 4.07 TDEE
 * Author: James Young
 * Date: July 17, 2019
 * Purpose: Write a program to calculate total daily energy expenditure.
 */

import java.util.Scanner;
public class TDEE
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        
                
        //user info
        System.out.print("Enter your name: ");
        String name = in.nextLine();
        System.out.print("Enter your BMR: ");
        int bmr = in.nextInt();   
        System.out.print("Gender (M or F): ");
        String gender = in.next();
        
        //Select activity Level
        System.out.println("Select Your Activity Level");
        System.out.println("[A] Resting (Sleeping, Reclining)");
        System.out.println("[B] Sedentary (Minimal Movement)");
        System.out.println("[C] Light (Sitting, Standing)");
        System.out.println("[D] Moderate (Light Manual Labor, Dancing, Riding Bike)");
        System.out.println("[E] Very Active (Team Sports, Hard Manual Labor)");
        System.out.println("[F] Extremely Active (Full-time Athlete, Heavy Manual Labor)\n");
        System.out.print("Enter the letter corresponding to your activity level: ");
        String activityLevel1 = in.next();
        char activityLevel = activityLevel1.charAt(0);
       
        
        double activityFactor = 0.0;
        
        boolean activityLevelA = activityLevel == 'A' || activityLevel == 'a';
        boolean activityLevelB = activityLevel == 'B' || activityLevel == 'b';
        boolean activityLevelC = activityLevel == 'C' || activityLevel == 'c';
        boolean activityLevelD = activityLevel == 'D' || activityLevel == 'd';
        boolean activityLevelE = activityLevel == 'E' || activityLevel == 'e';
        boolean activityLevelF = activityLevel == 'F' || activityLevel == 'f';
        
        if (activityLevelA){
            activityFactor = 1.0;
        }else if (activityLevelB){
            activityFactor = 1.3;
        }else if (activityLevelC){
            if(gender.equalsIgnoreCase("M")){
                activityFactor = 1.6;
            }else{
                activityFactor = 1.5;
            }
        }else if (activityLevelD){
            if(gender.equalsIgnoreCase("M")){
                activityFactor = 1.7;
            }else{
                activityFactor = 1.6;
            }
        }else if (activityLevelE){
            if(gender.equalsIgnoreCase("M")){
                activityFactor = 2.1;
            }else{
                activityFactor = 1.9;
            }
        }else if (activityLevelF){
            if(gender.equalsIgnoreCase("M")){
                activityFactor = 2.4;
            }else{
                activityFactor = 2.2;
            }
        }else{
            System.out.println("\nInvalid activity level choice!");
        }
        
        double tdee = bmr * activityFactor;
        
        String gender1 = gender.toUpperCase();
        
        System.out.println("Name: " + name + "   Gender: " + gender1);
        System.out.println("BMR: " + bmr + "   Activity Factor: " + activityFactor);
        System.out.println("TDEE: " + tdee);
        
        
        
    }   
}