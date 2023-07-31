
/**

@author: James Young
@purpose: Check work for question 3
 * 
 */
import java.util.ArrayList;
public class Question3Tester
{
    public static void main(String[] args)
    {
        ArrayList<String> words = new ArrayList<String>();
        
        words.add("Mary");
        words.add("had");
        words.add("a");
        words.add("Little");
        words.add("Lamb");
        
        String [] newWords = {"one", "two", "three"};
        
        Question3 n = new Question3 (words);
        n.fileSize();
        System.out.println("Number of bytes: " + n.getFileSize());
        n.mergeWords(newWords);
        System.out.println("New array: " + n.getMergeWords());
        
    }
}
