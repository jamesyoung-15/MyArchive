//please read the "Important requirements" for what you CANNOT do
#include <iostream>
using namespace std;

const int MAX_SIZE = 12;

//this function simply returns you the maximum of the two given integers a and b
//you can use it if you want, but do NOT modify this function
int max(int a, int b)
{
    return a>b?a:b;
}

//this function returns true if the given cell (x,y) is a doctor (for the infectWithPower simulation) and returns false otherwise
//you can use it if you want, but do NOT modify this function
bool isDoctor(char map[][MAX_SIZE], int width, int height, int x, int y)
{
    if(x<0 || x>=width || y<0 || y>=height)
        return false;
    else
        return map[y][x] >= 'A' && map[y][x] <= 'I';
}

//this function returns true if the given cell (x,y) is infected (for the infectWithPower simulation) and returns false otherwise
//you can use it if you want, but do NOT modify this function
bool isInfected(char map[][MAX_SIZE], int width, int height, int x, int y)
{
    if(x<0 || x>=width || y<0 || y>=height)
        return false;
    return map[y][x] >= '0' && map[y][x] <= '9';
}


void printMap(char map[][MAX_SIZE], int width, int height, int x=0, int y=0)
{
    if (y<0 || y>=height)
    {
        return;
    }
    cout << map[y][x];
    if(x<0 || x>=width-1)
    {
        cout<<"\n";
        return printMap(map, width, height, x=0, y+1);
    }
    else
    {
        cout<<" ";
        return printMap(map, width, height, x+1, y);
    }
    
}

int countCharacter(char map[][MAX_SIZE], int width, int height, char c, int x=0, int y=0)
{
    int characterCount =0;

    if(map[y][x]==c)
    {
        characterCount +=1;
    }
    if (y<0 || y>height)
    {
        return characterCount;
    }
    else if(x<0 || x>width)
    {
        return characterCount + countCharacter(map, width, height,c, x=0, y+1);
    }
    else
    {
        return characterCount + countCharacter(map, width, height,c, x+1, y);
    }
}

int infect(char map[][MAX_SIZE], int width, int height, int x, int y)
{
    char person = 'p';
    char inf = 'v';
    char empty = '.';

    //BASE CASES
    //if not person
    if(map[y][x]==empty)
    {
        return 0;
    }
    //if already infected
    else if(map[y][x] == inf)
    {
        return 0;
    }
    //out of bounds
    else if (y<0 || y>height || x<0 || x>width)
    {
        return 0;
    }
    //Infect cases
    //if it's a person
    else if(map[y][x]==person)
    {
        map[y][x]=inf;
        return 1+infect(map,width,height,x+1,y)+infect(map,width,height,x-1,y)+infect(map,width,height,x,y+1)+infect(map,width,height,x,y-1);
    }
    else
    {
        return 0;
    }
}

int getProtectionLevel(char map[][MAX_SIZE], int width, int height, int x, int y)
{
    int protectionLevel=0;
    if(y<0 || y>height || x<0 || x>width)
    {
        return 0;
    }
    else if(map[y][x]=='.')
    {
        return 0;
    }
    //if current location is person
    else if(map[y][x]=='p')
    {
        //if above is doctor
        if(isDoctor(map,width,height,x,y+1))
        {
            //compare current protection level to make sure it is the max
            if(int(map[y+1][x])-64 >protectionLevel)
            {
                protectionLevel = int(map[y+1][x])-64;
            }
            //compare to doctor below
            if(isDoctor(map,width,height,x,y-1))
            {
                if(protectionLevel<int(map[y-1][x])-64)
                {
                    protectionLevel = int(map[y-1][x])-64;
                }
            }
            //compare to doctor on the right
            if(isDoctor(map,width,height,x+1,y))
            {
                if(protectionLevel<int(map[y][x+1])-64)
                {
                    protectionLevel = int(map[y][x+1])-64;
                }
            }
            //compare to doctor on the left
            if(isDoctor(map,width,height,x-1,y))
            {
                if(protectionLevel<int(map[y][x-1])-64)
                {
                    protectionLevel = int(map[y][x-1])-64;
                }
            }
        }
        //if below is doctor
        if(isDoctor(map,width,height,x,y-1))
        {
             //compare current protection level to make sure it is the max
            if(int(map[y-1][x])-64 >protectionLevel)
            {
                protectionLevel = int(map[y-1][x])-64;
            }
            //compare to doctor above
            if(isDoctor(map,width,height,x,y+1))
            {
                if(protectionLevel<int(map[y+1][x])-64)
                {
                    protectionLevel = int(map[y+1][x])-64;
                }
            }
            //compare to doctor on the right
            if(isDoctor(map,width,height,x+1,y))
            {
                if(protectionLevel<int(map[y][x+1])-64)
                {
                    protectionLevel = int(map[y][x+1])-64;
                }
            }
            //compare to doctor on the left
            if(isDoctor(map,width,height,x-1,y))
            {
                if(protectionLevel<int(map[y][x-1])-64)
                {
                    protectionLevel = int(map[y][x-1])-64;
                }
            }
        }
        //if right is doctor
        if(isDoctor(map,width,height,x+1,y))
        {
            //compare current protection level to make sure it is the max
            if(int(map[y][x+1])-64 >protectionLevel)
            {
                protectionLevel = int(map[y][x+1])-64;
            }
            //compare to doctor below
            if(isDoctor(map,width,height,x,y-1))
            {
                if(protectionLevel<int(map[y-1][x])-64)
                {
                    protectionLevel = int(map[y-1][x])-64;
                }
            }
            //compare to doctor above
            if(isDoctor(map,width,height,x,y+1))
            {
                if(protectionLevel<int(map[y+1][x])-64)
                {
                    protectionLevel = int(map[y+1][x])-64;
                }
            }
            //compare to doctor on the left
            if(isDoctor(map,width,height,x-1,y))
            {
                if(protectionLevel<int(map[y][x-1])-64)
                {
                    protectionLevel = int(map[y][x-1])-64;
                }
            }
        }
        //if left is doctor
        if(isDoctor(map,width,height,x-1,y))
        {
            //compare current protection level to make sure it is the max
            if(int(map[y][x-1])-64 >protectionLevel)
            {
                protectionLevel = int(map[y][x-1])-64;
            }
            //compare to doctor below
            if(isDoctor(map,width,height,x,y-1))
            {
                if(protectionLevel<int(map[y-1][x])-64)
                {
                    protectionLevel = int(map[y-1][x])-64;
                }
            }
            //compare to doctor above
            if(isDoctor(map,width,height,x,y+1))
            {
                if(protectionLevel<int(map[y+1][x])-64)
                {
                    protectionLevel = int(map[y+1][x])-64;
                }
            }
            //compare to doctor on the right
            if(isDoctor(map,width,height,x+1,y))
            {
                if(protectionLevel<int(map[y][x+1])-64)
                {
                    protectionLevel = int(map[y][x+1])-64;
                }
            }
        }
        return protectionLevel;
    }
    else
    {
        return 0;
    }

}

void infectWithPower(char map[][MAX_SIZE], int width, int height, int x, int y, int power)
{
    int protection = getProtectionLevel(map,width,height,x,y);
    if(map[y][x]=='.')
    {
        return;
    }
    if(isDoctor(map,width,height,x,y))
    {
        return;
    }
    if(y<0 || y>=height)
    {
        return;
    }
    if(x<0 || x>=width)
    {
        return;
    }
    if(protection>=power)
    {
        return;
    }
    if(isInfected(map,width,height,x,y))
    {
        int test = int(map[y][x])-48;
        // cout<<"before: "<<x<<y<<power<<test<<endl;
        // printMap(map,width,height);
        int newMax = max(test,power);
        char charMax = newMax + 48;
        if(protection>=newMax)
        {
            map[y][x] = 'p';
        }
        else{
            map[y][x] = charMax;
        }
        // cout<<"after: "<<map[y][x]<<endl;
        // printMap(map,width,height);
        // cout<<endl;
    }
    if(power<1)
    {
        return;
    }
    if(map[y][x]=='p')
    {
        map[y][x] = power + '0';
        //printMap(map,width,height);
        //cout<<endl;
    }
    infectWithPower(map, width, height, x+1, y, power-1);
    infectWithPower(map, width, height, x, y+1, power-1);
    infectWithPower(map, width, height, x, y-1, power-1);
    infectWithPower(map, width, height, x-1, y, power-1);
}

int random(int seed, int n)
{
    if(n<=0)
    {
        return seed;
    }
    int sqn = seed*seed;
    string str = to_string(abs(sqn));
    if(str.length()%2!=0 && str.length()>6)
    {
        str.insert(0,"0");
    }
    if(str.length()==6)
    {
        str.insert(0,"00");
    }
    if(str.length()==5)
    {
        str.insert(0,"000");
    }
    if(str.length()==4)
    {
        str.insert(0,"0000");
    }
        if(str.length()==3)
    {
        str.insert(0,"00000");
    }
    if(str.length()==2)
    {
        str.insert(0,"000000");
    }
    if(str.length()==1)
    {
        str.insert(0,"0000000");
    }
    int middleIndex = str.length()/2;
    int lowIndex = middleIndex - (middleIndex/2);
    int highIndex = middleIndex + (middleIndex/2)-2;
    string newStr = str.substr(lowIndex,highIndex);
    if(newStr.length()<2)
    {
    newStr = "0";
    }
    seed = stoi(newStr);

    return random(seed, n-1);
}

void infectWithProbability(char map[][MAX_SIZE], int width, int height, int x, int y, int threshold, int seed, int n=1)
{
    //cout<<n <<" " << seed<< " ";
    seed = random(seed,1);
    //cout<<seed<<" "<<threshold<<" "<<endl;
    if(map[y][x]=='.')
    {
        return;
    }
    if(x<0 || x>=width)
    {
        return;
    }
    if(y<0 || y>=height)
    {
        return;
    }
    if(map[y][x]=='p')
    {
        map[y][x] = n+'0';
    }
    if(isInfected(map,width,height,x,y))
    {
        int test = int(map[y][x])-48;
        // cout<<"before: "<<test<< " " << n << " "<< x << " "<< y <<" "<<endl;
        // printMap(map,width,height);
        // cout<<endl;
        if(test>n)
        {
            map[y][x] = n+48;
        }
        // cout<<"after"<<endl;
        // printMap(map,width,height);
        // cout<<endl;
    }
    if(seed<threshold)
    {
        return;
    }
    infectWithProbability(map,width,height,x+1,y,threshold,seed,n+1);
    infectWithProbability(map,width,height,x-1,y,threshold,seed,n+1);
    infectWithProbability(map,width,height,x,y+1,threshold,seed,n+1);
    infectWithProbability(map,width,height,x,y-1,threshold,seed,n+1);

}

int main()
{
    cout << "Welcome to the infection simulator!" << endl;
    cout << "Which test case do you want to run?" << endl;
    int testCaseNumber = 0;
    cin >> testCaseNumber;

    cout << "Running test case " << testCaseNumber << "... If you do not see a complete output below, that could mean runtime errors happened (e.g. infinite recursion). Check your code carefully." << endl;

    if(testCaseNumber == 1)
    {
        int width = 6;
        int height = 5;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.', '.'},
            {'p', 'p', 'p', '.', 'p', '.'},
            {'.', 'p', '.', 'p', 'p', '.'},
            {'p', 'p', '.', '.', '.', 'p'},
            {'.', 'p', '.', '.', 'p', '.'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 2)
    {
        int width = 5;
        int height = 6;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.'},
            {'p', 'p', 'p', '.', 'p'},
            {'.', 'p', '.', 'p', 'p'},
            {'p', 'p', '.', '.', '.'},
            {'.', 'p', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 3)
    {
        int width = 5;
        int height = 6;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.'},
            {'p', 'p', 'p', '.', 'p'},
            {'.', 'p', '.', 'p', 'p'},
            {'p', 'p', '.', '.', '.'},
            {'.', 'p', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        cout << "#infected = " << infect(map, width, height, 1, 1) << endl;
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 4)
    {
        int width = 5;
        int height = 6;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.'},
            {'p', 'p', 'p', '.', 'p'},
            {'.', 'p', '.', 'p', 'p'},
            {'p', 'p', '.', '.', '.'},
            {'.', 'p', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        infect(map, width, height, 1, 1); 
        //this test case is very similar to the previous test case
        //the only difference is that we do not output the return value of the infect function
        //this is to give partial credits to students who could only modify the map correctly
        //but not getting a correct return value
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 5)
    {
        int width = 5;
        int height = 6;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'p', 'p', '.', 'p', 'p'},
            {'p', 'p', 'p', '.', '.'},
            {'p', 'p', '.', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p'},
            {'p', '.', '.', '.', '.'},
            {'p', 'p', 'p', 'p', 'p'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        cout << "#infected = " << infect(map, width, height, 4, 5) << endl;
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 6)
    {
        int width = 5;
        int height = 6;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.'},
            {'p', 'p', 'p', '.', 'p'},
            {'.', 'p', '.', 'p', 'p'},
            {'p', 'p', '.', '.', '.'},
            {'.', 'p', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        cout << "#infected = " << infect(map, width, height, 0, 0) << endl;
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 7)
    {
        int width = 5;
        int height = 6;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.'},
            {'p', 'p', 'p', '.', 'v'},
            {'.', 'p', '.', 'v', 'v'},
            {'p', 'p', '.', '.', '.'},
            {'.', 'p', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        cout << "# of p = " << countCharacter(map, width, height, 'p') << endl;
        cout << "# of v = " << countCharacter(map, width, height, 'v') << endl;
        cout << "# of . = " << countCharacter(map, width, height, '.') << endl;
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 8)
    {
        int width = 8;
        int height = 5;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p', '.', '.', '.'},
            {'.', 'p', 'p', 'B', 'p', '.', '.', 'p'},
            {'.', '.', '.', '.', 'p', 'p', '.', 'p'},
            {'.', '.', '.', '.', 'p', '.', '.', '.'}
        };
        cout << "========================" << endl;
        cout << "getProtectionLevel at (3,2) = " << getProtectionLevel(map, width, height, 3, 2) << endl;
        cout << "getProtectionLevel at (2,2) = " << getProtectionLevel(map, width, height, 2, 2) << endl;
        cout << "getProtectionLevel at (4,2) = " << getProtectionLevel(map, width, height, 4, 2) << endl;
        cout << "getProtectionLevel at (3,1) = " << getProtectionLevel(map, width, height, 3, 1) << endl;
        cout << "getProtectionLevel at (3,3) = " << getProtectionLevel(map, width, height, 3, 3) << endl;
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 9)
    {
        int width = 8;
        int height = 5;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'C', '.', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p', '.', '.', '.'},
            {'.', 'p', 'A', 'B', 'p', '.', '.', 'p'},
            {'.', '.', '.', '.', 'p', 'p', '.', 'p'},
            {'.', '.', '.', '.', 'p', '.', '.', '.'}
        };
        cout << "========================" << endl;
        cout << "getProtectionLevel at (3,2) = " << getProtectionLevel(map, width, height, 3, 2) << endl;
        cout << "getProtectionLevel at (2,2) = " << getProtectionLevel(map, width, height, 2, 2) << endl;
        cout << "getProtectionLevel at (4,2) = " << getProtectionLevel(map, width, height, 4, 2) << endl;
        cout << "getProtectionLevel at (3,1) = " << getProtectionLevel(map, width, height, 3, 1) << endl;
        cout << "getProtectionLevel at (3,3) = " << getProtectionLevel(map, width, height, 3, 3) << endl;
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 10)
    {
        int width = 8;
        int height = 5;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'.', 'p', '.', 'p', '.', '.', '.', 'p'},
            {'p', 'p', 'p', 'p', 'p', '.', '.', '.'},
            {'.', 'p', 'p', 'p', 'p', '.', '.', 'p'},
            {'.', '.', '.', '.', 'p', 'p', '.', 'p'},
            {'.', '.', '.', '.', 'p', '.', '.', '.'}
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        infectWithPower(map, width, height, 1, 1, 3);
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 11)
    {
        int width = 8;
        int height = 8;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        infectWithPower(map, width, height, 3, 3, 8);
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 12)
    {
        int width = 8;
        int height = 8;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'C', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        infectWithPower(map, width, height, 3, 3, 8);
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 13)
    {
        cout << "========================" << endl;
        cout << "random(1234, 1) = " << random(1234, 1) << endl;
        cout << "random(1234, 2) = " << random(1234, 2) << endl;
        cout << "random(1234, 3) = " << random(1234, 3) << endl;
        cout << "random(1234, 4) = " << random(1234, 4) << endl;
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 14)
    {
        cout << "========================" << endl;
        cout << "random(1001, 1) = " << random(1001, 1) << endl;
        cout << "random(1001, 2) = " << random(1001, 2) << endl;
        cout << "random(1001, 3) = " << random(1001, 3) << endl;
        cout << "random(1001, 4) = " << random(1001, 4) << endl;
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 15)
    {
        int width = 8;
        int height = 8;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        infectWithProbability(map, width, height, 4, 4, 3200, 1234);
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }
    else if(testCaseNumber == 16)
    {
        int width = 8;
        int height = 8;
        char map[MAX_SIZE][MAX_SIZE] = {
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', '.', '.', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        };
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
        infectWithProbability(map, width, height, 4, 4, 3200, 1234);
        cout << "========================" << endl;
        printMap(map, width, height);
        cout << "========================" << endl;
    }

    return 0;
}