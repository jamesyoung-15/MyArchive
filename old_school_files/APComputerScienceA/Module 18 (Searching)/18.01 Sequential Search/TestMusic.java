public class TestMusic {
	public static void main(String[] args)
	{
	    Music[] myMusic = new Music[10];
	    myMusic[0] = new Music("Jesus of Suburbia",2004, "Green Day");
	    myMusic[1] = new Music("Famous Last Words",2006,"My Chemical Romance");
	    myMusic[2] = new Music("Only God can Judge me", 1999,"Tupac");
	    myMusic[3] = new Music("Numb",2003,"Linkin Park");
	    myMusic[4] = new Music("Mr.Brightside",2003,"The Killers");
	    myMusic[5] = new Music("Wonderwall",1995,"Oasis");
	    myMusic[6] = new Music("Not Afraid",2010,"Eminem");
	    myMusic[7] = new Music("Juicy",1994,"The Notorious B.I.G.");
	    myMusic[8] = new Music("Bohemian Rhapsody",1975,"Queen");
	    myMusic[9] = new Music("Yellow",2000,"Coldplay");
	    printmyMusic(myMusic);
	    System.out.println();
	    System.out.println("Search - Title - Numb");
	    System.out.println("Time                     Location        Person");
	    System.out.println("-------------------------------------------------------------");
	    findTitle(myMusic, "Numb");
	    System.out.println();
	    System.out.println("Search - Title - Juicy");
	    System.out.println("Time                     Location        Person");
	    System.out.println("------------------------------------------------------------");
	    findTitle(myMusic, "Juicy");
	    System.out.println();
	    System.out.println("Search - Year - 1994");
	    System.out.println("Time                     Location        Person");
	    System.out.println("-----------------------------------------------------------");
	    findYear(myMusic, 1994);
	    System.out.println();
	    System.out.println("Search - Artist - Green Day");
	    System.out.println("Time                     Location        Person");
	    System.out.println("-----------------------------------------------------------");
	    findSinger(myMusic, "Green Day");
	    System.out.println();
	}
	public static void printmyMusic(Music[] r)
	{
	    System.out.println("Time                     Location        Person");
	    System.out.println("------------------------------------------------------------");
	    for(int i = 0; i < r.length; i++)
	    {
	       if(r[i] != null)
	       {
	           System.out.println(r[i]);
	       }
	    }
	}
	public static void findSinger(Music[] r, String toFind)
	{
	    int found = 0;
	    for(int i = 0; i < r.length; i++)
	    {
	        if (r[i].getArtist() != null)
	        {
	            if (r[i].getArtist().compareTo(toFind) == 0)
	            {
	                System.out.println(r[i]);
	                found++;
	            }
	        }
	    }
	    if (found == 0)
	    { // we have not found the location
	        System.out.println("There are no listings for " + toFind);
	        System.out.println();
	    } 
	    else
	    {
	        System.out.print("There were " + found + " listings for " + toFind);
	        System.out.println();
	    }
	}
	public static void findTitle(Music[] r, String toFind)
	{
	    int found = 0;
	    for(int i = 0; i < r.length; i++)
	    {
	        if (r[i].getTitle() != null && toFind != null) //java.lang.NullPointerException occurs here
	        {
	            if (r[i].getTitle().compareTo(toFind) == 0)
	            {
	                System.out.println(r[i]);
	                found++;
	            }
	        }
	    }
	    if (found == 0)
	    { // we have not found the location
	        System.out.println("There are no listings for " + toFind);
	        System.out.println();
	    } 
	    else
	    {
	        System.out.print("There were " + found + " listings for " + toFind);
	        System.out.println();
	    }
	}
	public static void findYear(Music[] r, int toFind)
	{
	    int found = 0;
	    for(int i = 0; i < r.length; i++)
	    {
	        if (r[i].getYear() == toFind)
	        {
	            System.out.println(r[i]);
	            found++;
	        }
	    }
	    if (found == 0)
	    { // we have not found the location
	        System.out.println("There are no listings for " + toFind);
	        System.out.println();
	    } 
	    else
	    {
	        System.out.print("There were " + found + " listings for " + toFind);
	        System.out.println();
	    }
	}	
}