
/**
 * Chemistry class that tells how much pages left to read, extends Homework class.
 *
 * @author James Young
 * @version Jan 22, 2020
 */
public class ChemistryV3 extends HomeworkV3
{
     /**
     * Constructor call Homework's constructor
     */
    public ChemistryV3()
    {
        super();
    }
    
    /**
     * Abstract method for creating an assignment, parameter number of pages
     */
    public void createAssignment(int p) {
                setPagesRead(p);
                setType("Chemistry");
    }
        
    /**
     * Method lists the homework type and the number of pages
     */
    public String toString(){
        return getType() + "- " + getPagesRead() + " pages to read.";
    }
    
    /**
     * Overrides newReading() in Processing class
     * Method subtracts subtract the number of pages you have read and update the number of pages left to read.
     */
    public void newReading() { 
        System.out.print("Before Reading: "); 
        System.out.println(toString()); //get original pages needed to be read
        System.out.print("After Reading: "); 
        int newPages = getPagesRead() - 1; //test by minusing one page from original pages needed to be read
        System.out.println(getType() + " - " + newPages + " pages to read."); //should print new pages
        System.out.println();
    }
}
