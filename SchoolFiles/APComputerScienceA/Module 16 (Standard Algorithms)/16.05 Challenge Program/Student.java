
/**
 * Class defines student object w/ name and quiz scores
 *
 * @author James Young
 * @version Feb 23, 2020
 */
import java.util.*;
public class Student
{
    //intialize instance variables
    private String name;
    private int quiz1;
    private int quiz2;
    private int quiz3;
    private int quiz4;
    private int quiz5;
    
    //constructor
    public Student(String name, int quiz1, int quiz2, int quiz3, int quiz4, int quiz5)
    {
        this.name = name;
        this.quiz1 = quiz1;
        this.quiz2 = quiz2;
        this.quiz3 = quiz3;
        this.quiz4 = quiz4;
        this.quiz5 = quiz5;
    }
    
    //method gets quiz number 1-5
    public int getQuiz(int quizNumber)
    {
        if(quizNumber == 1)
        {
            return quiz1;
        }
        else if(quizNumber == 2)
        {
            return quiz2;
        }
        else if(quizNumber == 3)
        {
            return quiz3;
        }
        else if(quizNumber == 4)
        {
            return quiz4;
        }
        else if(quizNumber == 5)
        {
            return quiz5;
        }
        return 0;
    }
    
    //method sets quiz score
    public void setQuiz(int quizNumber, int score)
    {
        if(quizNumber == 1)
        {
            quiz1 = score;
        }
        else if(quizNumber == 2)
        {
            quiz2 = score;
        }
        else if(quizNumber == 3)
        {
            quiz3 = score;
        }
        else if(quizNumber == 4)
        {
            quiz4 = score;
        }
        else if(quizNumber == 5)
        {
            quiz5 = score;
        }
    }
    
    //getter methods below
    public String getName()
    {
        return name;
    }
    public int getquiz1()
    {
        return quiz1;
    }
    public int getquiz2()
    {
        return quiz2;
    }
    public int getquiz3()
    {
        return quiz3;
    }
    public int getquiz4()
    {
        return quiz4;
    }
    public int getquiz5()
    {
        return quiz5;
    }
    
    //to string method
    public String toString()
    {
        String printme = String.format("%13s %s %5d %5d %5d %5d %5d \n", 
        getName(),": ",getquiz1(),getquiz2(),getquiz3(),getquiz4(),getquiz5());
        return printme;
    }
    
    //changes name of student
    public void replaceName(String newname)
    {
        name = newname;
    }
    
    //replaces quiz with new score
    public void replaceQuiz(int quiznum, int newscore)
    {
        setQuiz(quiznum, newscore);
    }
    
    //replaces student and quiz scores
    public void replaceStudent(String newname, int q1, int q2, int q3, int q4, int q5)
    {
        name = newname;
        quiz1 = q1;
        quiz2 = q2;
        quiz3 = q3;
        quiz4 = q4;
        quiz5 = q5;
    }
}