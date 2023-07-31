
/**
 * @purpose: This program that calculates the amount of carbon dioxide produced in a year from waste by a household 
 * and compare how recycling can reduce the CO2 footprint.
 * 
 * @author James Young
 * @date October 23, 2019
 */


import java.util.ArrayList;                                   

public class CO2FromWasteTester
{
    public static void main(String[] args) 
    {
        //create arraylist
        ArrayList<CO2FromWaste> cO2waste = new ArrayList<CO2FromWaste>();
        
        //1.number of indiviuals, 2.boolean value for paper, 3. boolean value for plastic, boolean value for glass, boolean value for can
        cO2waste.add(new CO2FromWaste(1, true, true, true, true));
        cO2waste.add(new CO2FromWaste(6, true, false, true, false));
        cO2waste.add(new CO2FromWaste(3, false, true, true, false));
        cO2waste.add(new CO2FromWaste(2, true, true, false, true));
        cO2waste.add(new CO2FromWaste(10, true, false, false, true));
        cO2waste.add(new CO2FromWaste(1, false, true, true, true));
        
        CO2FromWaste dataRecord;
        
        //print table heading from example in assignment instruction
        System.out.println();
        System.out.println("|_______|________|_____ Household Waste Recycled _______|_______  Pounds of CO2  __________|");
        System.out.println("|       |        |                                      | Total   |            |    Net    |");
        System.out.println("| Index | People |  Paper  |  Plastic  | Glass |  Cans  |Emission | Reduction  |  Emission |");
        System.out.println("|-------|--------|---------|-----------|-------|--------|---------|------------|-----------|");
        
        //call methods
        for(int index = 0; index < cO2waste.size(); index++)
        {
            dataRecord = cO2waste.get(index);
            dataRecord.calcGrossWasteEmission();
            dataRecord.calcWasteReduction();
            dataRecord.calcNetWasteReduction();
        }
        
        //print results
        for(int index = 0; index < cO2waste.size(); index++)
        {
            dataRecord = cO2waste.get(index);
            
            System.out.printf("|%4d   |%4d    |%6s   |%7s   | %6s | %6s | %7.1f | %10.1f |%9.1f  |%n",
                      index, dataRecord.getNumberOfPeople(),
                      String.valueOf(dataRecord.getRecyclingPaper()), String.valueOf(dataRecord.getRecyclingPlastic()), 
                      String.valueOf(dataRecord.getRecyclingGlass()), String.valueOf(dataRecord.getRecyclingCans()),//these will print true or false
                      dataRecord.getGrossWasteEmission(), dataRecord.getWasteReduction(),
                      dataRecord.getNetWasteEmission());
        }
    }
}
