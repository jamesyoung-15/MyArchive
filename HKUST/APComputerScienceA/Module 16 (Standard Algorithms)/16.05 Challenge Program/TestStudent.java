
/**
 * Client class tests student object
 *
 * @author James Young
 * @version Feb 23, 2020
 */
import java.util.*;
public class TestStudent
{
    public static void main(String[] args)
    {
        System.out.println("Starting Gradebook:");
        System.out.println();
        
        //arraylist for students and their quiz scores
        ArrayList<Student> myClass = new ArrayList<Student>();
        Student pat = new Student("Patrick Star",70,80,90,100,90);
        myClass.add(pat);
        Student pepe = new Student("Pepe the Frog",80,85,90,85,80);
        myClass.add(pepe);
        Student ligma = new Student("Ligma Balls",50,79,89,99,100);
        myClass.add(ligma);
        Student naruto = new Student("Naruto Uzmaki",85,80,85,88,89);
        myClass.add(naruto);
        Student shrek = new Student("Shrek",70,70,90,70,80);
        myClass.add(shrek);
        printScores(myClass);
        
        //change name
        System.out.println();
        System.out.println("Changing Shrek's name to Donkey:");
        shrek.replaceName("Donkey");
        System.out.println();
        printScores(myClass);

        //change quiz score
        System.out.println();
        System.out.println("Changing Patrick's quiz 1 score to 80:");
        pat.replaceQuiz(1, 80);
        System.out.println();
        printScores(myClass);
        
        //replace students
        System.out.println();
        System.out.println("Replacing Ligma Balls with Spooderman (80, 80, 80, 90, 90):");
        ligma.replaceStudent("Spooderman",80,80,80,90,90);
        System.out.println();
        printScores(myClass);
        
        //insert new student
        System.out.println();
        System.out.println("Inserting Donkey Kong (85, 95, 70, 0, 100) before Naruto:");
        insertStudent(myClass, "Naruto Uzmaki", "Donkey Kong", 85, 95, 70, 60, 100);
        System.out.println();
        printScores(myClass);
        
        //delete a student
        System.out.println();
        System.out.println("Deleting Pepe the Frog:");
        deleteStudent(myClass, "Pepe the Frog");
        System.out.println();
        printScores(myClass);
    }
    //print
    public static void printScores(ArrayList<Student> classScores)
    {
        System.out.printf("%s %8s %5s %5s %5s %5s \n"," Student name","Q1","Q2","Q3","Q4","Q5");
        System.out.println("------------------------------------------------");
        for(Student t : classScores)
        {
            System.out.print(t.toString());
        }
    }
    
    //insert student method
    public static void insertStudent(ArrayList<Student> classlist, String findName, String newName,
                                     int q1, int q2, int q3, int q4, int q5)
    {
        int location = 0;
        for(int i=0; i<classlist.size();i++)
        {
            if(classlist.get(i).getName().equals(findName))
            {
                location = i;
                break;
            }
        }
        classlist.add(location, new Student(newName, q1, q2, q3, q4, q5));
    }
    
    //delete student method
    public static void deleteStudent(ArrayList<Student> classlist, String findName)
    {
        int location = 0;
        int i;
        for(i=0;i<classlist.size();i++)
        {
            if(classlist.get(i).getName().equals(findName))
            {
                location = i;
                break;
            }
        }
        if(i != classlist.size())
        {
            classlist.remove(location);
        }
    }
}