import java.io.IOException;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileReader;
import java.util.Scanner;
import java.util.Random;
class HurricaneSelector
{
    public static void main (String [ ] args) throws IOException
    {
        File fileName = new File("HurricaneData.txt");
        Scanner inFile = new Scanner(fileName);
        
        int [] year = new int[156];
        String [] month = new String[156];
        double [] wind = new double[156];
        int [] category = new int[156];
        int [] pressure = new int[156];
        String [] names = new String[156];
        
        for(int index = 0; index <156; index++)
        {
            year[index] = inFile.nextInt();
            month[index] = inFile.next();
            pressure[index] = inFile.nextInt();
            wind[index] = inFile.nextInt();
            names[index] = inFile.next();
        }
        
        
        inFile.close();
        
        
        
        int[] categories = new int[156];
        int cat1=0;
        int cat2=0;
        int cat3=0;
        int cat4=0;
        int cat5=0;
        int catSum=0;
        int windSum=0;
        int pressureSum=0;
        
        for(int index = 0; index<156; index++)
        {
            wind[index] = wind[index]*1.151;
            windSum += wind[index];
        }
        
        //categorise
    for(int index = 0; index < 156; index++)
    {
        if(wind[index]>= 74 && wind[index] <96)
        {
            categories [index]=1;
            catSum += categories[index];
            cat1++;
        }
        else if(wind[index]>=96 && wind[index]<111)
        {
            categories[index]=2;
            catSum += categories[index];
            cat2++;
        }
        else if(wind[index]>=111 & wind[index]<129)
        {
            categories[index]=3;
            catSum += categories[index];
            cat3++;
        }
        else if(wind[index]>=130 && wind[index]<157)
        {
            categories[index]=4;
            catSum += categories[index];
            cat4++;
        }
        else
        {
            categories[index]=5;
            catSum += categories[index];
            cat5++;
        }
    }
    
    int pressureMin = pressure[0];
        int windMin = (int)wind[0];
    int catMin = category[0];
    int pressureMax=0;
    int windMax=0;
    int catMax=0;
    
    //pressure min max
        int max = Integer.MIN_VALUE;
        for(int category : categories)
        {
            if(category > max)
            {
                max = category;
            }
        }
    for(int index=0;index<156;index++)
    {
        if(pressure[index]>0)
        {
            pressureMax = pressure[index];
        }
    }
    
    //wind min max
    for (int index = 0; index < 156; index++)
            {
            if (wind[index] < windMin){
                
                windMin = (int)wind[index];
                
            }
        }
    for(int index=0;index<156;index++)
    {
        if(wind[index]>0)
        {
            windMax = (int)wind[index];
        }
    }
    
    //Cat min max
    for (int index = 0; index < 156; index++)
            {
            if (category[index] < catMin)
            {
                catMin = category[index];
            }  
        }
    for(int index=0;index<156;index++)
    {
        if(category[index]>catMax)
        {
            catMax=category[index];
        }
        
    }

    System.out.println("                      Hurricanes 1995 - 2015");
        System.out.println();
        System.out.println("Year     Hurricane    Category     Pressure (mb)     Wind Speed (mph)");
        System.out.println("=====================================================================");

        for (int index = 0; index < 156; index++){
            
            System.out.printf("%d%13s%10d%16d%18d\n" , year[index] , names[index] , categories[index] , pressure[index] , (int)wind[index]);
            
        }
        
        windSum = windSum / 156;
        catSum = catSum / 156;
        pressureSum = pressureSum / 156;
        System.out.println("=====================================================================");
        System.out.printf("%s%20d%16d%18d\n" , "Average" , catSum , pressureSum , windSum / 2);
        System.out.printf("%s%20d%16d%18d\n" , "Maximum" , catMax , pressureMax , windMax);
        System.out.printf("%s%20d%16d%18d\n" , "Minimum" , catMin , pressureMin , windMin);
        System.out.println();
        System.out.println("Cateogry 1: " + cat1);
        System.out.println("Cateogry 2: " + cat2);
        System.out.println("Cateogry 3: " + cat3);
        System.out.println("Cateogry 4: " + cat4);
        System.out.println("Cateogry 5: " + cat5);
     
    }   
}

