
/**
 * Tests and prints results from Homework class.
 *
 * @author James Young
 * @version Jan 22, 2020
 */
import java.util.ArrayList;
public class testHomework {
    public static void main(String[] args){
        //initalize variables
        
        Math m = new Math();
        m.createAssignment(59);
                
        Chemistry c = new Chemistry();               
        c.createAssignment(70);
                
                
        English e = new English();                
        e.createAssignment(520);
                
                
        History h = new History();                
        h.createAssignment(101);
                
                
        //arraylist to organize subjects        
        ArrayList<Homework> hw = new ArrayList<Homework>();
                
        hw.add(m);                
        hw.add(c);                
        hw.add(e);                
        hw.add(h);  
        System.out.println("My Homework Reading To-Do");
        System.out.println("-------------------------------------");
        for(Homework i : hw){           
            System.out.println(i.toString());      
        }
                
            }
}