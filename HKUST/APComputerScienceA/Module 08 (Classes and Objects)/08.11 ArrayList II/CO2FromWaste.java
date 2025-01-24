
/**
 * @purpose: This program that calculates the amount of carbon dioxide produced in a year from waste by a household 
 * and compare how recycling can reduce the CO2 footprint.
 *
 * @author James Young
 * @date October 23, 2019
 */

import java.util.ArrayList;                                   

public class CO2FromWaste
{
    // instance variables
    private int numPeople;
    private boolean paper, plastic, glass, cans;
    private double grossWasteEmission, wasteReduction, netWasteEmission;

    /**
     * Constructor for objects of class CO2FromWaste
     */
    public CO2FromWaste(int pple, boolean recyclePaper, boolean recyclePlastic, boolean recycleGlass, boolean recycleCans)
    {
        numPeople = pple;
        cans = recycleCans;
        glass = recycleGlass;
        plastic = recyclePlastic;
        paper = recyclePaper;
    }
    
    /**
     * Getter method returns number of people
     */
    
        public int getNumberOfPeople() {
        return numPeople;
    }

    /**
     * Getter method returns boolean value for recycling paper
     */
    
    public boolean getRecyclingPaper() {
        return paper;
    }

    /**
     * Getter method returns boolean value for recycling plastic
     */
    
    public boolean getRecyclingPlastic() {
        return plastic;
    }
    
    /**
     * Getter method returns boolean value for recycling glass
     */

    public boolean getRecyclingGlass() {
        return glass;
    }

    /**
     * Getter method returns boolean value for recycling cans
     */
    
    public boolean getRecyclingCans() {
        return cans;
    }
    
    /**
     * Mutator method calculates waste emission for each individual
     */
    
    public void calcGrossWasteEmission()
    {
        grossWasteEmission = (numPeople * 1018); //1018 pounds of CO2 for each indiviual
    }
    
    /**
     * Mutator method calculates waste deduction depending on what someone recycles
     */
    
    public void calcWasteReduction()
    {
        //initialize variables
        double paperCO2, plasticCO2, glassCO2, aluminumCO2; //amount of CO2 deduction variables
        
        if (paper == true)
        {
            paperCO2 = 184; //recycling paper reduces 184 lbs of CO2
        }
        
        else
        {
            paperCO2 = 0;
        }
        
        if (plastic == true)
        {
            plasticCO2 = 25.6; //recycling plastic reduces 25.6 lbs of CO2
        }
        
        else
        {
            plasticCO2 = 0;
        }
        
        if (glass == true)
        {
            glassCO2 = 45.6; //recycling glass reduces 45.6 lbs of CO2
        }
        
        else
        {
            glassCO2 = 0;
        }
        
        if (cans == true)
        {
            aluminumCO2 = 165.8; //recylcing aluminum/cans reduces 165.8 lbs of CO2
        }
        
        else
        {
            aluminumCO2 = 0;
        }
        
        //calculate total CO2 by subtracting all waste reduction
        wasteReduction = numPeople * (paperCO2 + plasticCO2 + glassCO2 + aluminumCO2);
    }
    
    /**
     * Mutator method calculates net waste by taking the waste emission from individuals
     * and subtracting that by the waste reduction from recycling
     */
    
    public void calcNetWasteReduction()
    {
        calcGrossWasteEmission();
        calcWasteReduction();
        netWasteEmission = grossWasteEmission - wasteReduction;
    }
    
    /**
     * Getter method returns Gross Waste Emission
     */
    
    public double getGrossWasteEmission()
    {
        return grossWasteEmission;
    }
    
    /**
     * Getter method returns waste reduction from recycling
     */
    
    public double getWasteReduction()
    {
        return wasteReduction;
    }
    
    /**
     * Getter method returns net waste reduction
     */
    
    public double getNetWasteEmission()
    {
        return netWasteEmission;
    }
}
