
/**
 * This class performs a frequency analysis of the letters in a message and use the results to decipher a secret message.
 *
 * @author James Young
 * @version Jan 13, 2020
 */

import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.io.PrintWriter;
import java.util.ArrayList;

public class FrequencyAnalysis
{
    	static ArrayList<Character> Alphabet = new ArrayList<Character>();
	static ArrayList<Integer> characterCount = new ArrayList<Integer>();
	static int totalCount = 0;
	
	//method adds alphabets to array Alphabet
	public static void setupAlphabet() {
		for (int i = 97; i < 123; i++) {
			char letter = (char)i;
			Alphabet.add(letter);
		}
	}
	
	//method calculates frequency of character in text file
	public static void frequencyFromSubset(File in) throws IOException {
		Scanner scanner = new Scanner(in);
		while (scanner.hasNextLine()) {
			String data = scanner.nextLine();
			data = data.toLowerCase(); //convert each line to lower case
			int count = 0;
			int index = 0;
			for (int i = 97; i < 123; i++) {
				char letter = (char)i;
				count = 0;
				for (int j = 0; j < data.length(); j++) {
					char c = data.charAt(j);
					if (c == letter) {
						count++;
					}
				}
				int total =+ count;
				totalCount = totalCount + count;
				characterCount.add(index, total);
				index++;
			}
			
		}
		
	}
	
	
	//prints character and the frequency
	public static void printFromSubsetData() {
		System.out.println("Letter\t /\t Frequency\t /\t Percentage");
		for(int i = 0; i < Alphabet.size(); i++) {
			char letter = Alphabet.get(i);
			int count = characterCount.get(i);
			double percent = (double)count/totalCount;
			percent = (double)percent*100; 
			System.out.print(letter + "\t /\t " + count + "\t\t /\t ");
			System.out.printf("%.2f\n", percent);
	
		}
	}
	
	//creates text file and writes result on it
	public static void outputData() throws IOException {
		PrintWriter output = new PrintWriter(new File("plainTextFreq.txt"));
		output.println("Letter\t /\t Frequency\t /\t Percentage");
		int index = 0;
		for (int i = 0; i < Alphabet.size(); i++) {
			char letter = Alphabet.get(index);
			int count = characterCount.get(index);
			double percent = (double)count/totalCount;
			percent = (double)percent*100; 
			output.print(letter + "\t /\t " + count + "\t\t /\t ");
			output.printf("%.2f\n", percent);
			index++;
		}
		output.close();
	}
}
