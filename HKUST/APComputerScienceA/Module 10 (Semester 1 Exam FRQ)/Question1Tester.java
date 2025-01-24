
/**
 *
 * @author James Young
 * @purpose: Tester for Question 1 to check
 */
public class Question1Tester
{
    public static void main (String args[])
    {
        int [][] scores = {{96, 72, 84, 65, 89, 60,},{78, 86, 75, 61, 85, 73}};
        String [][] letters = {{"A", "C", "B", "D", "A", "D"},{"B", "B", "C","D", "B", "C"}};
        Question1 g = new Question1 (scores, letters);
        double avg = g.letterAverage("B");
        System.out.println(avg);
    }
}
