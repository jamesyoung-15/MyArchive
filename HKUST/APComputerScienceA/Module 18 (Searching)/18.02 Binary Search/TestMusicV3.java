public class TestMusicV3 {
    public static void main(String[] args)
    {
        int test = 0;
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
        printMusic(myMusic);
        myMusic = insertionSort(myMusic);
        test = searchTitle(myMusic, "Wonderwall");
        System.out.println("Search - Title - Wonderwall");
        if (test != -1)
        {
            System.out.println("Found: " + myMusic[test].getTitle() + ", " + myMusic[test].getYear() + ", " + myMusic[test].getArtist());
        }
        else
        {   
            System.out.println("Not found.");
        }
        System.out.println();
        test = searchTitle(myMusic, "Yellow");
        System.out.println("Search - Title - Yellow");
        if (test != -1)
        {
            System.out.println("Found: " + myMusic[test].getTitle() + ", " + myMusic[test].getYear() + ", " + myMusic[test].getArtist());
        }
        else
        {   
            System.out.println("Not found.");
        }
        System.out.println();
        searchYear(myMusic, 2001);
        searchYear(myMusic, 2004);
        searchArtist(myMusic, "Tupac");
    }
    public static void printMusic(Music[] r)
    {
        System.out.printf("%-25s%-15s%-20s\n", "Title", "Year", "Artist");
        System.out.println("---------------------------------------------------");
        for(int i = 0; i < r.length; i++)
        {
           System.out.println(r[i]);
        }
        System.out.println();
    }
    public static Music[] insertionSort(Music[] r)
    {        
        Music[] sorted = new Music[r.length];
        for ( int i = 0 ; i < r.length ; i++ )
        {
            String next = r[i].getTitle();
            int insertindex = 0;
            int k = i;
            while ( k > 0 && insertindex == 0 )
            {
                if ( next.compareTo( sorted[k - 1].getTitle() ) > 0 )
                {
                    insertindex = k;
                }
                else
                {
                    sorted[k] = sorted[k - 1];
                }
                k--;
            }
            sorted[ insertindex ] = r[i];
        }
        return sorted;
    }
    public static int searchTitle(Music[] r, String toFind )
    {
        int high = r.length;
        int low = -1;
        int probe;

        while ( high - low > 1 )
        {
            probe = ( high + low ) / 2;
            if ( r[probe].getTitle().compareTo(toFind) > 0)
            {    
                high = probe;
            }
            else
            {
                low = probe;
            }
        }
        if ( (low >= 0) && (r[low].getTitle().compareTo(toFind) == 0 ))
        {
            return low;
        }
        else
        {
            return -1;
        }
    }
    public static void searchYear(Music[] r, int toFind)
    {
        int found = 0;
        
        System.out.println("Search - Year - " + toFind);
        for(int i = 0; i < r.length; i++)
        {
            if (r[i].getYear() == toFind)
            {
                System.out.println("Found: " + r[i].getTitle() + ", " + r[i].getYear() + ", " + r[i].getArtist());
                found++;
            }
        }
        if (found == 0)
        {
            System.out.println("Not found.");
        }
        System.out.println();
    }
    public static void searchArtist(Music[] r, String toFind)
    {
        int found = 0;
        
        System.out.println("Search - Artist - " + toFind);
        for(int i = 0; i < r.length; i++)
        {
            if (r[i].getArtist().compareTo(toFind) == 0)
            {
                System.out.println("Found: " + r[i].getTitle() + ", " + r[i].getYear() + ", " + r[i].getArtist());
                found++;
            }
        }
        if (found == 0)
        {
            System.out.println("Not found.");
        }
        System.out.println();
    }
}