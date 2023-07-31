  
/**

@author: James Young
@date: Nov 11, 2019
@assignment: Question 3 of APCSA Semester 1 Exam FRQ 
 
 * 

Question 3:

This question involves a class named FileText that represents a text file.

  public class FileText
  {

      private String fileName;
      private int fileBytes;
      private ArrayList<String> wordList; // the contents of the text file

      // constructors not shown

      // postcondition: calculates the number of bytes in this file and updates
      // the instance variable fileBytes
      public void fileSize()
      {

      }

      // precondition: 0 < newWords.length < wordList.size ()
      // postcondition: elements from the newWords array are placed into consecutive
      // odd index positions of the wordlist ArrayList
      // postcondition: the value of fileBytes is updated
      public void mergeWords(String[] newWords)
      {

      }

      // other methods not shown

  }

The wordlist ArrayList stores the words (tokens) found in a text file. Suppose wordlist contains the following elements:

   [Mary, had, a, little, lamb]

The fileSize method; the size of the file is computed in bytes. Each character in a word counts as one byte. In addition, there is a space in between each word, and each of those spaces also counts as one byte. For the example above, the fileSize method would compute 4 + 3 + 1 + 6 + 4 as the sum of the lengths of each String in the ArrayList. The value of fileBytes would be this sum plus 4, because there would be 4 spaces in between the 5 words.

For the mergeWords method, assume the values for the newWords array are as follows:

   {"one", "two", "three"}

After the method has executed, fileBytes will have an updated value, and wordlist would contain the following elements:

   [Mary, one, had, two, a, three, little, lamb]

Complete the fileSize and mergeWords methods below. Be sure to include the method headers. (12 points)
*/

import java.util.ArrayList;

public class Question3
  {

      private String fileName;
      private int fileBytes;
      private ArrayList<String> wordList; // the contents of the text file

      public Question3 (ArrayList<String> words)
      {
          wordList = words;
          fileBytes = 0;
      }

      // postcondition: calculates the number of bytes in this file and updates
      // the instance variable fileBytes
      public void fileSize()
      {
          
          for(String s : wordList) 
          {
                int itemLength = s.length();
                fileBytes = fileBytes + itemLength;   
            }
          fileBytes = fileBytes + wordList.size() -1;
      }
      
      public int getFileSize()
      {
          return fileBytes;
        }

      // precondition: 0 < newWords.length < wordList.size ()
      // postcondition: elements from the newWords array are placed into consecutive
      // odd index positions of the wordlist ArrayList
      // postcondition: the value of fileBytes is updated
      public void mergeWords(String[] newWords)
      {
          int j = 0;
          for (int index = 0; index <= newWords.length + 2; index++)
          {
              if (index % 2 != 0)
              {
                  String word = newWords[j];
                  wordList.add(index, word);
                  j++;
              }
          }
      }

      public ArrayList<String> getMergeWords()
      {
          return wordList;
      }
      // other methods not shown

  }