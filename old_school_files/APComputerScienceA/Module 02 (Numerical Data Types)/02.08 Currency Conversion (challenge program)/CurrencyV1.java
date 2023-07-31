
/**
 * Author: James Young
 * Purpose: Write a program to convert currencies using current exchange rates.
 * Find the amount spent by a traveler in each country and the dollar amount remaining upon her return. 
 * Date: July 12, 2019
 */
public class CurrencyV1
{
    public static void main(String args[])
    {
        //Declare and initialize local variables
        double startingUsDollars = 6500.00;     // starting US Dollars

        double ausdSpent = 1553.6;            // Australian Dollars spent
        double ausdExchangeRate = 1.43914;     // 1 US dollar = 1.44 Australian dollars
        double dollarsSpentInAustralia = ausdSpent / ausdExchangeRate;      // US dollars spent in Australia
        double dollarsAfterAustralia = startingUsDollars - dollarsSpentInAustralia;  // US dollars remaining after Australia
        //remaining variables below here

        // Message to user stating purpose
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        System.out.println("This program converts an amount of money");
        System.out.println("from a specific country into the equivalent");
        System.out.println("currency of another country given the current");
        System.out.println("exchange rate.");
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        System.out.println();
        System.out.println("Starting USD: " + startingUsDollars);
        System.out.println();
        
        
        // Message to user about money spent in Australia to USD
        System.out.println("AUSTRALIA:");
        System.out.println("   Australian dollar spent:    " + ausdSpent);
        System.out.println("   USD equivalent:             " + dollarsSpentInAustralia);
        System.out.println("   US dollars remaining:       " + dollarsAfterAustralia);
        System.out.println();
        
        
        double euroSpent = 1745.0;            // Euros spent
        double euroExchangeRate = 0.8778;     // 1 US dollar = 0.88 Euros 
        double dollarsSpentInSpain = euroSpent / euroExchangeRate;      // US dollars spent in Spain
        double dollarsAfterSpain = dollarsAfterAustralia - dollarsSpentInSpain;  // US dollars remaining after Spain
        
        // Message to user about money spent in Spain to USD
        System.out.println("Spain:");
        System.out.println("   Euros spent:                " + euroSpent);
        System.out.println("   USD equivalent:             " + dollarsSpentInSpain);
        System.out.println("   US dollars remaining:       " + dollarsAfterSpain);
        System.out.println();

        
        double hkdSpent = 3545.0;            // HKD spent
        double hkdExchangeRate = 7.8117;     // 1 US dollar = 7.81 HKD 
        double dollarsSpentInHk = hkdSpent / hkdExchangeRate;      // US dollars spent in HK
        double dollarsAfterHk = dollarsAfterSpain - dollarsSpentInHk;  // US dollars remaining after HK
        
        System.out.println("Hong Kong:");
        System.out.println("   HKD spent:                  " + hkdSpent);
        System.out.println("   USD equivalent:             " + dollarsSpentInHk);
        System.out.println("   US dollars remaining:       " + dollarsAfterHk);
        System.out.println("===================================================");
        System.out.println("Remaining USD:                 " + dollarsAfterHk);

        
        
        // Conversion
        // code goes below here




        // Complete the code below for Souvenir Purchases
        System.out.println();
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        System.out.println("Souvenir Purchases");
        System.out.println(" (all values in US Dollars) ");
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        //Calculations for Souvenir #1
        int costItem1 = 12;                         //cost per item of first souvenir
        int budget1 = 100;                          //budget for first item
	    int totalItems1 = 0; 		//how many items can be purchased
	    int fundsRemaining1 = 0;  //how much of the budget is left

	    totalItems1 = budget1/costItem1;			//find how many can be bought
	    fundsRemaining1 = budget1 - costItem1*totalItems1;	//find reamining funds

        System.out.println("Item 1");
        System.out.println("   Cost per item: $" + costItem1 );
        System.out.println("   Budget: $"+ budget1);
        System.out.println("   Total items purchased: " +  totalItems1);
        System.out.println("   Funds remaining: $"  +  fundsRemaining1);
        System.out.println();

        //Calculations for Souvenir #2
        double costItem2 = 29.99;                       //cost per item of second souvenir
        int budget2 = 500;                              //budget for second item
	    int totalItems2 = 0; 	//how many items can be purchased
	    double fundsRemaining2 = 0.0;  	//how much of the budget is left

	    totalItems2 = (int)(budget2/costItem2);
	    fundsRemaining2 = budget2 - costItem2*totalItems2;

        System.out.println("Item 2");
        System.out.println("   Cost per item: $" + costItem2 );
        System.out.println("   Budget: $"+ budget2);
        System.out.println("   Total items purchased: " +  totalItems2);
        System.out.println("   Funds remaining: $"  +  fundsRemaining2);

    } // end of main method
} // end of class

