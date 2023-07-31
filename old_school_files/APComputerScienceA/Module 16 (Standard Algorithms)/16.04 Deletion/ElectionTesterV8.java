/**
 * Purpose: Same as ElectionTesterV7 but uses an arraylist
 * 
 * @author (James Young)
 * @date (Feb 16)
 */

import java.util.*;
public class ElectionTesterV8
{
    public static void main(String[] args)
    {
        int sum = 0; 
        int counter = 0;
        
        //replaced array from Electiontester3 to arraylist
        ArrayList<Candidate> c = new ArrayList<Candidate>();
        Candidate lucy = new Candidate("Lucy Robertson", 5000);
        c.add(lucy);
        Candidate griez = new Candidate("Antoine Griezmann", 4000);
        c.add(griez);
        Candidate michael = new Candidate("Michael Jordan", 6000);
        c.add(michael);
        Candidate tim = new Candidate("Tim Duncan", 2500);
        c.add(tim);
        Candidate joe = new Candidate("Joe Cole", 1800);
        c.add(joe);
        Candidate jj = new Candidate("JJ Reddick", 3000);
        c.add(jj);
        Candidate goat = new Candidate("Lio Messi", 2000);
        c.add(goat);
        Candidate myles = new Candidate("Myles Turner", 8000);
        c.add(myles);
        Candidate tony = new Candidate("Tony Parker", 500);
        c.add(tony);
        Candidate antony = new Candidate("Anthony Davis", 10000);
        c.add(antony);
        
        //original votes Start
        
        System.out.println("Original Results:");
        for(Candidate t : c)
        {
            sum += t.getVotes();
            counter++;
        }
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(Candidate t : c)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            t.getName(), t.getVotes(), ((double)t.getVotes() / sum) * 100);
        }
        System.out.println();
        //original votes End
        
        //replace name Start
        System.out.println("Total number of votes in election: " + sum);
        System.out.println();
        System.out.println("<Change Lucy w/ Jerome Boateng>");
        System.out.println();
        lucy.replaceName("Jerome Boateng");
        sum = 0;
        for(Candidate t : c)
        {
            sum += t.getVotes();
            counter++;
        }
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(Candidate t : c)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            t.getName(), t.getVotes(), ((double)t.getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        System.out.println();
        //replace name End
        
        //replace votes Start
        System.out.println("<Replace Myles Turner's original votes to 100 Votes>");
        System.out.println();
        myles.replaceVotes(100);
        sum = 0;
        for(Candidate t : c)
        {
            sum += t.getVotes();
            counter++;
        }
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(Candidate t : c)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            t.getName(), t.getVotes(), ((double)t.getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //end
        
                //insert candidate START
        System.out.println();
        String name = "Jerome Boateng";
        insertCandidate(c, "Myles Turner", name, 1400);
        sum = 0;
        
        System.out.println("<Add Jerome Boateng w/ 1400 Votes>");
        for(Candidate t : c)
        {
            sum += t.getVotes();
        }
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(Candidate t : c)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            t.getName(), t.getVotes(), ((double)t.getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Insert candidate END
        
        //Insert Position Start
        System.out.println();
        insertPosition(c, 5, "Donald Duck", 1400);
        sum = 0;
        
        
        System.out.println("<Adds Donald Duck w/ 1400 Votes to position 5>");
        for(Candidate t : c)
        {
            sum += t.getVotes();
        }
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(Candidate t : c)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            t.getName(), t.getVotes(), ((double)t.getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Insert Pos end
        
        //Delete Position Start
        System.out.println();
        deleteByLoc(c,6);
        
        System.out.println("<Deletes candidate in position 6>");
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(Candidate t : c)
        {
            sum += t.getVotes();
            counter++;
        }
        for(Candidate t : c)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            t.getName(), t.getVotes(), ((double)t.getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Delete Pos end
        
        //Delete Name Start
        System.out.println();
        int location = 0;
        for(Candidate t : c)
        {
            sum += t.getVotes();
            counter++;
        }
        deleteByName(c, "Myles Turner");
        System.out.println("<Deletes candidate by name: Myles Turner>");
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(Candidate t : c)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            t.getName(), t.getVotes(), ((double)t.getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Delete Name end
    }
    
    public static void insertPosition(List<Candidate> list, int location, String name, int votes) 
    {          
       // insert item into ArrayList
       list.add(location, new Candidate(name, votes));
    }
    public static void insertCandidate(List<Candidate> list, String find, String name, int votes) 
    {
        int location = 0;
        // find location of item you want to insert before
        for(int index = 0; index < list.size(); index++)
        {
          if (list.get(index).getName().equals(find))
          {
               location = index;
          }
        }
        // insert item into ArrayList
        list.add(location, new Candidate(name, votes));
    }
    public static void deleteByLoc(List<Candidate> list, int location) 
    {          
       // delete item from ArrayList
       list.remove(location);
    }   
    public static void deleteByName(List<Candidate> list, String find) 
    {
        int location = 0;
        int index;
        // find location of item you want to delete
        for(index = 0; index < list.size(); index++)
        {
          if (list.get(index).getName().equals(find))
          {
              location = index;
              break;
            }
        }
        // delet  item from ArrayList
        if (index != list.size())
        {
         list.remove(location);
        }
    }
}