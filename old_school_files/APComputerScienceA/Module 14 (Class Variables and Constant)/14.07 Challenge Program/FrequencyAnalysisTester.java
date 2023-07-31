
/**
 * Tests FrequencyAnalysis class and prints result.
 *
 * @author James Young
 * @version Jan 13, 2020
 */

import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.io.PrintWriter;
import java.util.ArrayList;
public class FrequencyAnalysisTester
{
        public static void main(String[] args) throws IOException{
            	Scanner in = new Scanner(System.in);
                FrequencyAnalysis fa = new FrequencyAnalysis();
                System.out.println("Which file would you like to perform the Frequency Analysis test on?");
                String fileName = in.nextLine();
		File file = new File(fileName + ".txt");
		fa.setupAlphabet();
		fa.frequencyFromSubset(file);
		fa.printFromSubsetData();
		fa.outputData();
	}
            
}
