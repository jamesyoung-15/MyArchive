/**
 * Method class for ElectionTesterV3 and V4
 * 
 * @author (James Young)
 * @date (Feb 16)
 */

public class Candidate
{
    private String name;
    private int numVotes;
    public Candidate3(String name, int numVotes){
        this.name = name;
        this.numVotes = numVotes;
    }
    public String getName(){
        return name;
    }
    public int getVotes(){
        return numVotes;
    }
    public void replaceName(String n){
        name = n;
    }
    public void replaceVotes(int v){
        numVotes = v;
    }
    public String toString(){
        return getName() + " received " + getVotes() + " votes.";
    }
}