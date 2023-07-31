public class TestMovie
{
    public static void main(String[] args)
    {
        Movie tdk = new Movie("The Dark Knight",2008,"Warner Bros. Pictures");
        Movie lotr = new Movie("The Lord of the Rings: The Return of the King",2003,"New Line Cinema");
        Movie inception = new Movie("Inception",2010,"Legendary Pictures");
        Movie incredibles = new Movie("The Incredibles",2004,"Pixar");
        Movie joker = new Movie("Joker",2019,"Warner Bros. Pictures");
        Movie fightclub = new Movie("Fight Club", 1999,"Fox 2000 Pictures");
        Movie blade = new Movie("Blade Runner",1982,"Shaw Brothers");
        Movie trainingday = new Movie("Training Day",2001,"Warner Bros Pictures");
        Movie django = new Movie("Django Unchained",2012,"Columbia Pictures");
        Movie starwars = new Movie("Return of the Jedi",1983,"Lucasfilm Ltd.");
        Movie[] movies = new Movie[] {tdk, lotr, inception, incredibles, joker, fightclub, 
                                        blade, trainingday, django, starwars};
        Movie[] newmovies = new Movie[movies.length];
        System.out.println("Before Sorting:");
        printMovies(movies);
        System.out.println();
        System.out.println("Sorted by Title - ascending:");
        newmovies = sortTitles(movies,1);
        printMovies(newmovies);
        System.out.println();
        System.out.println("Sorted by Year - descending:");
        newmovies = sortYears(movies,2);
        printMovies(newmovies);
        System.out.println();
        System.out.println("Sorted by Studios:");
        newmovies = sortStudios(movies,1);
        printMovies(newmovies);
    }
    public static void printMovies(Movie[] a)
    {
        for(int i=0;i< a.length;i++)
        {
            System.out.println(a[i].toString());
        }
    }
    public static Movie[] sortTitles(Movie[] a, int b)
    {
        Movie[] newlist = new Movie[a.length];
        if(b==1)
        {
            for(int i=0;i<a.length;i++)
            {
                String next = a[i].getTitle();
                int insert = 0;
                int k =i;
                while(k>0 && insert == 0)
                {
                    if(next.compareTo( newlist[k-1].getTitle() ) > 0)
                    {
                        insert = k;
                    }
                    else
                    {
                        newlist[k] = newlist[k-1];
                    }
                    k--;
                }
                newlist[insert]=a[i];
            }
            return newlist;
        }
        else if (b==2)
        {
            for(int i=0;i<a.length;i++)
            {
                String next = a[i].getTitle();
                int insert = 0;
                int k =i;
                while(k>0 && insert == 0)
                {
                    if(next.compareTo( newlist[k-1].getTitle() ) < 0)
                    {
                        insert = k;
                    }
                    else
                    {
                        newlist[k] = newlist[k-1];
                    }
                    k--;
                }
                newlist[insert]=a[i];
            }
            return newlist;
        }
        else
        {
            return newlist;
        }
    }
    public static Movie[] sortYears(Movie[] a, int b)
    {
        Movie[] newlist = new Movie[a.length];
        if(b==1)
        {
            for(int i=0;i<a.length;i++)
            {
                Movie next = a[i];
                int insert = 0;
                int k =i;
                while(k>0 && insert == 0)
                {
                    if(next.getYear() < newlist[k-1].getYear())
                    {
                        insert = k;
                    }
                    else
                    {
                        newlist[k] = newlist[k-1];
                    }
                    k--;
                }
                newlist[insert]=next;
            }
            return newlist;
        }
        else if (b==2)
        {
            for(int i=0;i<a.length;i++)
            {
                Movie next = a[i];
                int insert = 0;
                int k =i;
                while(k>0 && insert == 0)
                {
                    if(next.getYear() < newlist[k-1].getYear())
                    {
                        insert = k;
                    }
                    else
                    {
                        newlist[k] = newlist[k-1];
                    }
                    k--;
                }
                newlist[insert]=a[i];
            }
            return newlist;
        }
        else
        {
            return newlist;
        }
    }
    public static Movie[] sortStudios(Movie[] a, int b)
    {
        Movie[] newlist = new Movie[a.length];
        if(b==1)
        {
            for(int i=0;i<a.length;i++)
            {
                String next = a[i].getStudio();
                int insert = 0;
                int k =i;
                while(k>0 && insert == 0)
                {
                    if(next.compareTo( newlist[k-1].getStudio() ) > 0)
                    {
                        insert = k;
                    }
                    else
                    {
                        newlist[k] = newlist[k-1];
                    }
                    k--;
                }
                newlist[insert]=a[i];
            }
            return newlist;
        }
        else if (b==2)
        {
            for(int i=0;i<a.length;i++)
            {
                String next = a[i].getStudio();
                int insert = 0;
                int k =i;
                while(k>0 && insert == 0)
                {
                    if(next.compareTo( newlist[k-1].getStudio() ) < 0)
                    {
                        insert = k;
                    }
                    else
                    {
                        newlist[k] = newlist[k-1];
                    }
                    k--;
                }
                newlist[insert]=a[i];
            }
            return newlist;
        }
        else
        {
            return newlist;
        }
    }
}