
/**
 * Abstract class for a homework reading assignment
 *
 * @author James Young
 * @version Jan 22, 2020
 */
public abstract class HomeworkV4 implements Comparable<HomeworkV4>
{
        
        //instance variables
        private int pagesRead;
        private String typeHomework;
        
        /**
         * 
         */
        public HomeworkV4()
        {
            pagesRead = 0;
            typeHomework = "None";
        }
        
        /**
         * getter method that returns number of pages that needs to be read
         */
        public int getPagesRead()
        {
                return pagesRead;
        }
        
        /**
         * method sets number of pages needed to be read
         */
        public void setPagesRead(int pages)
        {
            pagesRead = pages;
        }
        
        /**
         * getter method returns the string of subject of the homework
         */
        public String getType(){
                return typeHomework;
        }
        
        /**
         * method sets subject of homework
         */
        public void setType(String type)
        {
            typeHomework = type;
        }
        
        /**
         * abstract method whose purpose in extended classes is 
         * to create an assignment by setting the number of pages to read 
         * and the homework type
         */
        public abstract void createAssignment(int p);
        
        public int compareTo(HomeworkV4 obj){
            if(pagesRead < obj.pagesRead){
                return 1;
            }
            else if(pagesRead == obj.pagesRead){
                return 0;
            }
            else return -1;
        }
        
        public abstract String toString();

}
                
