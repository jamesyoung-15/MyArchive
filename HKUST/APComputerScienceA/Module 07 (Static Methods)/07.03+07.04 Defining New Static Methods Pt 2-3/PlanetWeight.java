
import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class PlanetWeight
{
    //This segment will read the surface gravity values from surfacegravitydata.txt file
    //will create a double array from those values
     public static double[] surfaceGravity() throws IOException
    {
        //initialize variables
        double [] surfaceGravity = new double[8]; //8 values of g
        int i = 0;
        File fileName = new File("surfacegravitydata.txt");
        Scanner inFile = new Scanner(fileName);
        //use values from txt to create array
        while (inFile.hasNext()){
           surfaceGravity[i] = inFile.nextDouble();
	   i++;
	}
	inFile.close(); //close file
        return surfaceGravity;
    }
    
    //This segment converts weight on earth to other planets
    
    public static double [] findWeights(double[] surfaceGravity, double[] weights)
    {
        //initialize variables
        Scanner input = new Scanner(System. in); //scanner
        System.out.println("Enter weight in lbs: ");
        double weightofUser = input.nextDouble(); //ask user for their weight in pounds (on earth)
        double [] convertUserWeighttoMass = new double [8];
        double weighttog = weightofUser * 453.59237; //finds weight of user in g
        //lbs to g is 1 lb = 453.59237 g
        
        //this converts weight in g to weights on other planets in g
        for (int i = 0; i < 8; i++){
            convertUserWeighttoMass[i] = weighttog * (surfaceGravity[i]/9.8);
	}
	//this converts weights in g to weights in lbs
        for (int i = 0; i < 8; i++){
            weights[i] = convertUserWeighttoMass[i]/453.59237;
	}
        return weights;
    }
    
    
    //This segment prints result to table
     public static void printTable(double[] surfaceGravity, double[] weights, String[] planetNames) 
     {
           System.out.println("My Weight on the Planets");
	   System.out.println("");
	   System.out.println("Planet	    Gravity(g/ms^2)	 Weight(lbs)");
	   for (int i = 0; i< 8; i ++)
	   {
	        System.out.printf(planetNames[i] + "	     %4.2f	           %4.2f",surfaceGravity[i],weights[i]);
	        System.out.println();
	   }
    }
    //main method
     public static void main(String args[])throws IOException
     {
        String [] planetNames = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
        double [] surfaceGravities = surfaceGravity();
        double[] weights = new double[8];
        weights = findWeights(surfaceGravities, weights);
	printTable(surfaceGravities, weights, planetNames);
    }
}