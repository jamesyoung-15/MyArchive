/**
 * @purpose: This class calculates the CO2 output by the amount of gas used.
 * 
 * Author: James Young
 * Date: October 23, 2019
 * 
 */
public class CO2FootprintV2Tester
{
    public static void main(String[] args)
    {
        //declare variables 
        double gallonsOfGas = 2410;
        
        //invoke constructor
        CO2FootprintV2 footprint = new CO2FootprintV2(gallonsOfGas);
        
        //call methods
        footprint.calcTonsCO2();
        footprint.convertTonsToPounds();
        
        //print results
        System.out.println("           CO2 Emissions");
        System.out.println("  Gallons   Pounds      Tons");
        System.out.println("  of Gas   from Gas   from Gas");
        System.out.println("  ****************************");
        System.out.printf("  %6.1f   %8.2f    %6.3f", footprint.getGallons(),
                                                      footprint.getPoundsCO2(),
                                                      footprint.getTonsCO2());

        System.out.println();
    }
}

