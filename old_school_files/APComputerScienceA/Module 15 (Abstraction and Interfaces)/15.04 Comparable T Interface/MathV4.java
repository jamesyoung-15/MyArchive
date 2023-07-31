/**
 * Math class that tells how much pages left to read, extends Homework class.
 *
 * @author James Young
 * @version Jan 22, 2020
 */
public class MathV4 extends HomeworkV4
{
    /**
     * Constructor call Homework's constructor
     */
    public MathV4()
    {
        super();
    }
    
    /**
     * Abstract method for creating an assignment, parameter number of pages
     */
    public void createAssignment(int p) {
                setPagesRead(p);
                setType("Math");
    }
        
    /**
     * Method lists the homework type and the number of pages
     */
    public String toString(){
        return getType() + "- " + getPagesRead() + " pages to read.";
    }
}
