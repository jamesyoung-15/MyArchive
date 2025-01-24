/**
 * Create mock election to demonstrate traversal algorithms
 * 
 * @author (James Young)
 * @date (Feb 16)
 */

public class ElectionTesterV3
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
        
        System.out.println();
        String name = "Jerome Boateng";
        lucy.replaceName(name);
        sum = 0;
        
        //replace name START
        System.out.println("<Change Lucy w/ Jerome Boateng>");
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
        //replace name END
        
        System.out.println();
        myles.replaceVotes(100);
        sum = 0;
        
        //new new votes
        System.out.println("<Replace Myles Turner's original vote to 100 Votes>");
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
        //end
    }
}