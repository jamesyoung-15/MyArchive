
/**
 * Tests and prints results from Homework class.
 *
 * @author James Young
 * @version Jan 22, 2020
 */
import java.util.ArrayList;
public class testHomeworkV3 {
    public static void main(String[] args){
        //initalize variables
        
        MathV3 m = new MathV3();
        m.createAssignment(59);
                
        ChemistryV3 c = new ChemistryV3();               
        c.createAssignment(70);
                
                
        EnglishV3 e = new EnglishV3();                
        e.createAssignment(520);
                
                
        HistoryV3 h = new HistoryV3();                
        h.createAssignment(101);
                
                
        //arraylist to organize subjects        
        ArrayList<HomeworkV3> homework = new ArrayList<HomeworkV3>();
                
        homework.add(m);                
        homework.add(c);                
        homework.add(e);                
        homework.add(h);  
        System.out.println("My Homework");
        System.out.println("-------------------------------------");
        for(HomeworkV3 i : homework){           
            i.newReading();      
        }
                
            }
}