
 /**
 * The Test2D class demonstrates assigning values to and
 * traversing a two dimensional array.
 *
 * @author Dennis Ritchie
 * @version 06/09/17
 */
public class Test2D
{

    // purpose: accepts a two dimensional array, the test number to modify
    // and the value to add to the current test scores
    public static void curveTest(int[][] scores, int testNum, int value)
    {
        int col = testNum -1;
        for(int row = 0; row < scores.length; row++)
        {
            scores[row][col] += 5;
        }
    }

    public static void printScores(int[][] scores)
    {
        int numOfTests = scores[0].length;  // the number of tests equals the number of columns

        //print the table and column headings
        System.out.println("         Test Scores");
        System.out.print("Student ");
        for(int i = 0; i < numOfTests; i++)
            System.out.printf("%5d", i+1);
        System.out.println();

        // print the body of the table with row headings
        for(int row = 0; row < scores.length; row ++)
        {
            System.out.printf("%5d   ", row +1);    // Student Number

            for(int col = 0; col < scores[row].length; col ++)
            {
                System.out.printf("%5d", scores[row][col]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {

        //int[][] testScores = new int[5][4];
    
        int[][] testScores = { { 98, 100, 75, 89},
                               {100,  95, 97, 85},
                               { 67,  77, 79, 80},
                               {100,  99, 95, 87},
                               {100,  95, 90, 85} };
    
         int numRows = testScores.length;
         int numCols = testScores[0].length;

         System.out.println("Original table of scores: ");
         printScores(testScores);
         System.out.println();
         System.out.println();
         curveTest(testScores, 4, 5);
         System.out.println("Table of scores after curving Test 4 by 5 pts: ");
         //System.out.printf(" Test #%3d", row);
         printScores(testScores);
         System.out.println();
    }
}
