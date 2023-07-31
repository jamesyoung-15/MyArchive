/**
 * Title: 05.03 Family Composition
 * Author: James Young
 * Date: July 20, 2019
 * Purpose: Write a program to calculate the probability that a 
 * family with two children will consist of two boys, a boy and a girl, or two girls.
 */

import java.util.Scanner; 
import java.io.File; 
import java.io.FileReader; 
import java.io.IOException; 
public class family 
{
    public static void main(String[] args) throws IOException {
        int bothBoys = 0;
        int bothGirls = 0;
        int boyAndGirl = 0;
        int sampleSize = 0;
        int counter=0; 
        String token = ""; 
        double percentageOfBothBoy=0;
        double percentageOfBoyAndGirl = 0;
        double percentageOfBothGirl =0; 
        Scanner inFile = new Scanner(new File("MaleFemaleInFamily.txt"));

        while(inFile.hasNext()){
            token = inFile.next();
            System.out.println(token);
                if(token.equals("BB")){
                    bothBoys++;
                    counter++;
                }else if(token.equals("GG")){
                    bothGirls++;
                    counter++;
                }else if(token.equals("BG")){
                    boyAndGirl++;
                    counter++;
                }else if(token.equals("GB")){
                    boyAndGirl++;
                    counter++;  
                }  
            }
                 
        sampleSize = counter;
        
        System.out.println("Sample size: " + sampleSize + "families");
        System.out.println("Number of families with two boys: "+ bothBoys);
        System.out.println("Number of families with one boy and one girl: "+ boyAndGirl);
        System.out.println("Number of families with two girls: "+ bothGirls);
        
        inFile.close();
        percentageOfBothBoy = ((double)bothBoys / (double)sampleSize) * 100; 
        percentageOfBothGirl = ((double)bothGirls / (double)sampleSize) * 100; 
        percentageOfBoyAndGirl = ((double)boyAndGirl / (double)sampleSize) * 100; 
        System.out.println("Percentage of families with two boys: "+ percentageOfBothBoy +"%") ; 
        System.out.println("Percentage of families with one boy one girl: "+ percentageOfBoyAndGirl + "%"); 
        System.out.println("Percentage of families with two girls: " + percentageOfBothGirl + "%"); 
                
        }


    }