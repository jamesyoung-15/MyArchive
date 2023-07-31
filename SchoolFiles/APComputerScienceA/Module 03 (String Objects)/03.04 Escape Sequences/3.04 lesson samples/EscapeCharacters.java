
/**
 * The purpose of this program is to demonstrate the use 
 * of escape sequences when printing literal constants.
 * 
 * Read the instructions in the comments for each block 
 * of code below so that you can experiment on your own.
 * 
 * @author Ada Lovelace
 * @version 06/03/17
 */
public class EscapeCharacters
{
	public static void main(String[] args)
	{
	    // Use of the newline escape sequence: \n
	    // What happens if you delete the n after the backslashes?
	    // What happens if you change println to print?
	    System.out.println("This\ndemonstrates\nthe\nnewline\nescape\nsequence\n.");
	    
	    // Use of the tab escape sequence: \t
	    // What happens if you delete the t after the backslashes?
	    // What happens if you change print to println?
	    // Try to discover how many tab positions it is practical to print  
	    // across the screen by modifying the following print statement.
	    
	    System.out.print("Tab\tTab\tTab\tTab\tTab\n");
	    System.out.println();   
	    

	    // Use the escape sequence for quotation marks: \"
	    // The print statement should display the following to the screen: 
	    // Anna said, "Please use escape sequences correctly."
	    // There should be quotes around what Anna said.
	    // What happens if you remove the \ before the "?
	    
	    System.out.println("Anna said, \"Please use escape sequences correctly.\"");
	    System.out.println();   
	    

	    // Use the escape sequence for backslashes: \\
	    // The print statement should display the following to the screen: 
	    // The file path is: C:\JavaProjects\LiteralConstants.java
	    // There should be quotes around the file path and there should be backslashes where indicated.
	    // What happens if change the \\ to just \?
	    
	    System.out.println("The file path is: C:\\JavaProjects\\LiteralConstants.java");
	    System.out.println();   
	    
	}//end of main method
}//end of class