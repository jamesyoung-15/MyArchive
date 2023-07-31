/**
 * Purpose: Create mock election to demonstrate deletion and insertion algorithms
 * 
 * @author (James Young)
 * @date (Feb 16)
 */

public class ElectionTesterV7
{
    public static void main(String[] args)
    {
        int sum = 0;
        int counter = 0;
        Candidate lucy = new Candidate("Lucy Robertson", 5000);
        Candidate griez = new Candidate("Antoine Griezmann", 4000);
        Candidate michael = new Candidate("Michael Jordan", 6000);
        Candidate tim = new Candidate("Tim Duncan", 2500);
        Candidate joe = new Candidate("Joe Cole", 1800);
        Candidate jj = new Candidate("JJ Reddick", 3000);
        Candidate goat = new Candidate("Lio Messi", 2000);
        Candidate myles = new Candidate("Myles Turner", 8000);
        Candidate tony = new Candidate("Tony Parker", 500);
        Candidate antony = new Candidate("Anthony Davis", 10000);
        Candidate[] candidates = new Candidate[] 
        {lucy, griez, michael, tim, joe, jj, goat, myles, tony, antony,};
        
        //original votes START
        System.out.println("Original Results:");
        System.out.println();
        //calculate total votes
        for(int i = 0; i < candidates.length; i++)
        {
            sum += candidates[i].getVotes();
        }
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        //print original results
        for(int i = 0; i < candidates.length; i++)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            candidates[i].getName(), candidates[i].getVotes(), ((double)candidates[i].getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //original votes END
        
        
        //insert candidate START
        System.out.println();
        String name = "Jerome Boateng";
        insertCandidate(candidates, "Myles Turner", name, 1400);
        sum = 0;
        
        System.out.println("<Add Jerome Boateng w/ 1400 Votes>");
        for(int i = 0; i < candidates.length; i++)
        {
            sum += candidates[i].getVotes();
        }
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(int i = 0; i < candidates.length; i++)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            candidates[i].getName(), candidates[i].getVotes(), ((double)candidates[i].getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Insert candidate END
        
        //Insert Position Start
        System.out.println();
        insertPosition(candidates, 5, "Donald Duck", 1400);
        sum = 0;
        
        
        System.out.println("<Adds Donald Duck w/ 1400 Votes to position 5>");
        for(int i = 0; i < candidates.length; i++)
        {
            sum += candidates[i].getVotes();
        }
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(int i = 0; i < candidates.length; i++)
        {
            System.out.printf("%17s                %5d                         %4.1f\n", 
            candidates[i].getName(), candidates[i].getVotes(), ((double)candidates[i].getVotes() / sum) * 100);
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Insert Pos end
        
        //Delete Position Start
        System.out.println();
        sum -= candidates[6].getVotes(); //have to subtract sum of deleted candidate
        deleteByLoc(candidates,6);        
        
        System.out.println("<Deletes candidate in position 6>");
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(int i = 0; i < candidates.length; i++)
        {
            if(candidates[i]!=null)
            {
                System.out.printf("%20s                %5d                         %4.1f\n", 
                candidates[i].getName(), candidates[i].getVotes(), ((double)candidates[i].getVotes() / sum) * 100);
            }
            else
            {
                i++;
            }
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Delete Pos end
        
        //Delete Name Start
        System.out.println();
        int location = 0;
        for(int i = 0; i < candidates.length; i++)
        {
          if ((candidates[i] != null) && (candidates[i].getName().equals("Myles Turner")))
          {
              location = i;
              break;
          } else if (candidates[i] == null)
          {
              location = -1;
              break;
          }  
        }
        sum -= candidates[location].getVotes();
        deleteByName(candidates, "Myles Turner");
        System.out.println("<Deletes candidate by name: Myles Turner>");
        System.out.println();
        System.out.println("Candidate               Votes Received                      % of Total Votes");
        System.out.println("-----------------------------------------------------------------------------");
        for(int i = 0; i < candidates.length; i++)
        {
            if(candidates[i]!=null)
            {
                System.out.printf("%20s                %5d                         %4.1f\n", 
                candidates[i].getName(), candidates[i].getVotes(), ((double)candidates[i].getVotes() / sum) * 100);
            }
            else
            {
                i++;
            }
        }
        System.out.println();
        System.out.println("Total number of votes in election: " + sum);
        //Delete Name end
        }

        
        public static void insertPosition(Candidate[] a, int pos, String name, int votes)
        {
        Candidate[] candidates = a;
        int position = pos;
        String n = name;
        int v = votes;
        for(int i=candidates.length-1;i>position;i--)
        {
            candidates[i] = candidates[i-1];
        }
        Candidate newperson = new Candidate(n, votes);
        candidates[position] = newperson;
        }
        public static void insertCandidate(Candidate[] a, String name, String newperson, int votes)
        {
        Candidate[] candidates = a;
        String newb = newperson;
        String n = name;
        int v = votes;
        int pos = 0;
        Candidate duk = new Candidate(newb, votes);
        for(int i=0;i<candidates.length;i++)
        {
            if(candidates[i].getName().equals(n))
            {
                pos = i;
            }
        }
        for(int i=candidates.length-1;i>pos;i--)
        {
            candidates[i] = candidates[i-1];
        }
        candidates[pos]= duk;
    }
    public static void deleteByLoc(Candidate[] a, int location) 
    {          
       if ((location > 0) && (location < a.length))
       {
              //move items up in the array -
              for(int i = location; i < a.length -1; i++)
              {
                  a[i] = a[i + 1];
              }
              a[a.length-1] = null;
       }
    }
    public static void deleteByName(Candidate[] a, String find) 
    {
        int location = 0;
        int i;
        // find location of item you want to delete
        for(i = 0; i < a.length; i++)
        {
          if ((a[i] != null) && (a[i].getName().equals(find)))
          {
              location = i;
              break;
          } else if (a[i] == null)
          {
              location = -1;
              break;
          }  
        }
        if ((i != a.length) && (location >= 0))       
        { //move items up in the array 
          for(i = location; i < a.length -1; i++)
          {
             a[i] = a[i + 1];
          }
          a[a.length-1] = null;
        }
    }
}