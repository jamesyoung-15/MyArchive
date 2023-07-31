#include <cstddef>
#include <cstdio>
#include <iostream>

// #include "player.h"
// #include "match.h"
#include "match.h"
#include "player.h"
#include "swiss.h"
#include <cstring>


// Task 4: Implement the conversion constructor and destructor
Swiss::Swiss(const int numRounds, const PlayerList& list) // : list(list) // in the future use MIL
{
    // std::cout<<"Swiss t4"<<std::endl;
    int numPlayers = list.getNumPlayers();
    for(int i=0;i<numPlayers;i++)
    {
        this->list.addPlayer(list.getPlayer(i));
    }
    this->list.sort();
    this->numRounds = numRounds;
    this->curRound = 0;
}

// Task 4: destructor
Swiss::~Swiss()
{
}

// Task 5: Implement the function to conduct the Swiss tournament
void Swiss::play()
{
    // For each curRound from 1 to numRounds:
    for (this->curRound=1; curRound<=numRounds; curRound++) 
    {
        // create array of playerlist, there will be 2 * curRound - 1 possible scores the players can have
        PlayerList *scores = new PlayerList[2*curRound-1];
        // loop over list and add them to corresponding playerlist depending on score, can use adddPlayer() or splice()
        for(int score=0;score<2*curRound-1;score++) //loop through each scores
        {
            // lists corresponding to scores with no players are empty
            scores[score] = PlayerList();
            // int totalPlayers = 0;
            for(int j=0;j<list.getNumPlayers();j++) //loop through each player
            {
                if(score==list.getPlayer(j)->getScore())
                {
                    scores[score].addPlayer(list.getPlayer(j));
                    // totalPlayers++;        
                }
            }
            // printf("%d: %d\n",score,totalPlayers);
        }

        for(int score=2*curRound-2;score>=0;score--)
        {
            int numberPlayers = scores[score].getNumPlayers();
            // for each non-empty playerlist
            if(numberPlayers!=0)
            {
                //sort the list
                scores[score].sort();
                if(numberPlayers>1)
                {
                    // find middle index (eg. for 6 or 7 players, middle is 3)
                    int middleIndex = numberPlayers/2;
                    for(int i=0;i<middleIndex;i++)
                    {
                        Match game = Match(scores[score].getPlayer(i), scores[score].getPlayer(i+middleIndex));
                        game.play();
                    }
                }

                // if odd number of players
                if(numberPlayers%2!=0)
                {
                    // if score is 0 ie. last playerlist, give player 2 points
                    if(score==0)
                    {
                        //bye
                        scores[score].getPlayer(numberPlayers-1)->addScore(2);
                    }
                    // otherwise push player down to top of list of lower score
                    else
                    {
                        // push down player by adding player to lower score list
                        scores[score-1].addPlayer(scores[score].getPlayer(numberPlayers-1));
                    }
                }
            }
        }
    
        list.sort();
        printLeaderboard();
        // delete any dynamically allocated memory
        delete [] scores;
    }
}
