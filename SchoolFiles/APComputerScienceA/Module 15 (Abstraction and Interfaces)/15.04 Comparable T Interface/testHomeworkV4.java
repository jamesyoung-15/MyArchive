
/**
 * Tests and prints results from Homework class.
 *
 * @author James Young
 * @version Jan 22, 2020
 */
import java.util.ArrayList;
public class testHomeworkV4 {
    public static void main(String[] args){
        //initalize variables
        
        MathV4 m = new MathV4();
        m.createAssignment(59);
                
        ChemistryV4 c = new ChemistryV4();               
        c.createAssignment(70);
                
                
        EnglishV4 e = new EnglishV4();                
        e.createAssignment(520);
                
                
        HistoryV4 h = new HistoryV4();                
        h.createAssignment(101);
                
                
        //arraylist to organize subjects        
        ArrayList<HomeworkV4> homework = new ArrayList<HomeworkV4>();
                
        //add subjects to arraylist
        homework.add(m);                
        homework.add(c);                
        homework.add(e);                
        homework.add(h);
        
        //printout pages to read for each subject
        System.out.println("My Homework");
        System.out.println("-------------------------------------");
        for(HomeworkV4 i : homework){           
            System.out.println(i.toString());      
        }
             
        //this section compares pages to read
        System.out.println();
        System.out.println("Comparing My Homeworks");
        System.out.println("-------------------------------------");
        
        int compareMathChem = m.compareTo(c);
        int compareMathEnglish = m.compareTo(e);
        
        if(compareMathChem == 0)
            System.out.println(m.getType() + " and " + c.getType() + " have the same assignment Length!");
        else if(compareMathChem == 1)
            System.out.println(m.getType() + " has more work than " + c.getType());
        else
            System.out.println(m.getType() + " has less work than " + c.getType());
            
        if(compareMathEnglish == 0)
            System.out.println(m.getType() + " and " + e.getType() + " have the same assignment Length!");
        else if(compareMathEnglish == 1)
            System.out.println(m.getType() + " has more work than " + e.getType());
        else
            System.out.println(m.getType() + " has less work than " + e.getType());
}
}