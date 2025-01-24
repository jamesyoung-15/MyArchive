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
        sortTitles(movies,1);
        printMovies(movies);
        System.out.println();
        System.out.println("Sorted by Year - descending:");
        sortYears(movies,2);
        printMovies(movies);
        System.out.println();
        System.out.println("Sorted by Studios:");
        sortStudios(movies,1);
        printMovies(movies);
    }
    public static void printMovies(Movie[] a)
    {
        for(int i = 0; i < a.length; i++)
        {
            System.out.println(a[i].toString());
        }
    }
    public static void sortTitles(Movie[] a, int b)
    {
        if(b==1)
        {
            for (int i = 0; i < a.length - 1; ++i)
            {
                int minIndex = i;
                for (int j = i + 1; j < a.length; ++j)
                {
                    if ((a[j].getStudio()).compareTo(a[minIndex].getStudio()) < 0)
                    {
                        minIndex = j;
                    }
                }
                Movie temp = a[i];
                a[i] = a[minIndex];
                a[minIndex] = temp;
            }
        }
        else if (b==2)
        {
            for (int i = 0; i < a.length - 1; ++i)
            {
                int minIndex = i;
                for (int j = i + 1; j < a.length; ++j)
                {
                    if ((a[j].getStudio()).compareTo(a[minIndex].getStudio()) > 0)
                    {
                        minIndex = j;
                    }
                }
                Movie temp = a[i];
                a[i] = a[minIndex];
                a[minIndex] = temp;
            }
        }
        else
        {
            System.out.println("ERROR");
        }
    }
    public static void sortYears(Movie[] a, int b)
    {
        Movie temp;
        int i;
        int k;
        int posmax;
        if(b==1)
        {
            for ( i = a.length - 1 ; i > 0 ; i-- )
            {
                posmax = 0;
                for ( k = 1 ; k <= i ; k++ )
                {
                    if ( a[ k ].getYear() > a[ posmax ].getYear() )
                    {
                        posmax = k;
                    }
                }
                temp = a[ i ];
                a[ i ] = a[posmax ];
                a[ posmax ] = temp;
            }
        }
        else if (b==2)
        {
            for ( i = a.length - 1 ; i > 0 ; i-- )
            {
                posmax = 0;
                for ( k = 1 ; k <= i ; k++ )
                {
                    if ( a[ k ].getYear() < a[ posmax ].getYear() )
                    {
                        posmax = k;
                    }
                }
                temp = a[ i ];
                a[ i ] = a[posmax ];
                a[ posmax ] = temp;
            }
        }
        else
        {
            System.out.println("ERROR");
        }
    }
    public static void sortStudios(Movie[] a, int b)
    {
        if(b==1)
        {
            for (int i = 0; i < a.length - 1; ++i)
            {
                int minIndex = i;
                for (int j = i + 1; j < a.length; ++j)
                {
                    if ((a[j].getStudio()).compareTo(a[minIndex].getStudio()) < 0)
                    {
                        minIndex = j;
                    }
                }
                Movie temp = a[i];
                a[i] = a[minIndex];
                a[minIndex] = temp;
            }
        }
        else if (b==2)
        {
            for (int i = 0; i < a.length - 1; ++i)
            {
                int minIndex = i;
                for (int j = i + 1; j < a.length; ++j)
                {
                    if ((a[j].getStudio()).compareTo(a[minIndex].getStudio()) > 0)
                    {
                        minIndex = j;
                    }
                }
                Movie temp = a[i];
                a[i] = a[minIndex];
                a[minIndex] = temp;
            }
        }
        else
        {
            System.out.println("ERROR");
        }
    }
       public static void mergeYears( Movie[] a, int low, int mid, int high )
    {
        Movie[] temp = new Movie[ high - low + 1 ];
        int i = low, j = mid + 1, n = 0;
        while ( i <= mid || j <= high )
        {
            if ( i > mid )
            {
                temp[ n ] = a[ j ];
                j++;
            }
            else if ( j > high )
            {
                temp[ n ] = a[ i ];
                i++;
            }
            else if ( a[ i ].getYear() > a[ j ].getYear() )
            {
                temp[ n ] = a[ i ];
                i++;
            }
            else
            {
                temp[ n ] = a[ j ];
                j++;
            }
            n++;
        }
        for ( int k = low ; k <= high ; k++ )
        {
            a[ k ] = temp[ k - low ];
        }
    } 
    public static void mergeTitles(Movie[] a, Movie[] left, Movie[] right)
    {
        int c = 0;
        int d = 0;
        for (int i = 0; i < a.length; i++) {
            if (d >= right.length || (c < left.length && (left[c].getTitle()).compareToIgnoreCase(right[d].getTitle()) < 0)) 
            {
                a[i] = left[c];
                c++;
            } else {
                a[i] = right[d];
                d++;
            }
        }
    }
    public static void mergeStudios(Movie[] a, Movie[] left, Movie[] right)
    {
        int c = 0;
        int d = 0;
        for (int i = 0; i < a.length; i++) {
            if (d >= right.length || (c < left.length && (left[c].getStudio()).compareToIgnoreCase(right[d].getStudio()) < 0)) 
            {
                a[i] = left[c];
                c++;
            } else {
                a[i] = right[d];
                d++;
            }
        }
    }
    }