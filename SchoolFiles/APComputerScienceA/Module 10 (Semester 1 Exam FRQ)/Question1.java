/**

@author: James Young
@date: Nov 11, 2019
@assignment: Question 1 of APCSA Semester 1 Exam FRQ

 * 
Question 1:

Assume that two-dimensional arrays are used to store information about students' grades. The first is called studentScores and contains the students' numerical scores as integers. The other is studentLetters and contains the corresponding letter grades as a String (i.e. "A", "B", "C", "D", or "F"). Each row represents an individual student and each column a different assessment.

For example, if studentScores[0][0] contains 92, then the contents of studentLetters[0][0] will contain the corresponding letter grade. In this case, the letter grade is A because the professor has used a standard grading scale. Note that the professor might choose a different grading scale. Do not assume scores of 90 or above are the letter grade A.

public class Gradebook
{

      private int[][] studentScores;
      private String[][] studentLetters;

      // constructors not shown

      // postcondition: returns −1.0 if letterGrade does not appear in studentLetters
      // otherwise, returns the average of all studentScores with corresponding
      // studentLetters values that are equal to the parameter letterGrade
      public double letterAverage(String letterGrade)
      {

      }

      // other methods not shown

}

Write the method letterAverage. This method returns a double representing the average (arithmetic mean) of the student scores that correspond to a given letter grade. The method letterAverage returns −1.0 if none of the student scores corresponds to the given letter grade.

For example, given the following two-dimensional arrays:

studentScores:       96 72 84 65 89 60
                     78 86 75 61 85 73

studentLetters:      A C B D A D
                     B B C D B C

The method call letterAverage("B") would return the number 83.25, which is the average of the four scores that correspond to the letter grade B.

The method call letterAverage("F") would return −1.0 because none of the studentLetters elements are equal to F.

Complete the method letterAverage below. Be sure to include the method header. (12 points)
 */     




public class Question1
{

      private int[][] studentScores;
      private String[][] studentLetters;
      
      public Question1 (int[][] scores, String[][] letters)
      {
          studentScores = scores;
          studentLetters = letters;
        }
      
      public double letterAverage(String letterGrade)
      {

           double average = 0;

           int numOfGrades = 0;

           for (int i = 0; i<studentScores.length; i++)

           {

               for (int x =0; x<studentScores[i].length; x++)

               {
               
               if(studentLetters[i][x] == letterGrade)

                {

                      average += studentScores[i][x];

                      numOfGrades ++;

                }

                else

                 {

                       average +=0;

                 }

                }

           }

           if (average == 0)

            {

                  return average = -1.0;

            }

            else

            {

                   return average/numOfGrades;

            }

      }
    }