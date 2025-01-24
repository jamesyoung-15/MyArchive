#include <cstddef>
#include <iostream>

#include "player.h"
// #include "match.h"
// #include "swiss.h"
#include <cstring>


// Task 1 implement player constructor 
Player::Player(const char* const name, const int elo)
{
    //debug
    // std::cout<<"t1 Constructor" <<std::endl;
    
    //allocate memory for the string name
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->score = 0;
    this->elo = elo;
}

// Task 1 implement player destroctor
Player::~Player()
{
    //debug
    // std::cout<<"Destructor player" <<std::endl;
    delete[] name;
}

// Task 2 Implement PlayerList default constructor
PlayerList::PlayerList()
{
    // sets the number of players to 0 and assign nullptr to the players array
    players = nullptr;
    this->numPlayers = 0;
}


// Task 2 Implement PlayerList constructor
PlayerList::PlayerList(const PlayerList& list)
{
    // std::cout<<"copy constr t2" <<std::endl;
  
    this->numPlayers = list.numPlayers;
    // allocate brand new array of pointers
    if(list.players!=nullptr)
    {
        this->players = new Player*[this->numPlayers];
        // assign those pointers to the same player objects
        for(int i=0;i<numPlayers;i++)
        {
            players[i] = list.players[i];
        }
    }
}


// Task 2 Implement PlayerList destructor 
PlayerList::~PlayerList()
{
    if(players!=nullptr)
    {
        // std::cout<<"t2 de" <<std::endl;
        delete [] players;
        players=nullptr;
    }
}

// Task 3
// This function adds a Player pointer to the list. 
void PlayerList::addPlayer(Player* const player)
{
    // need to handle the dynamically allocated array correctly, allocate new array if necessary 
    // if no players
    if(players==nullptr)
    {
        numPlayers++;
        players = new Player*[numPlayers];
        players[0] = player;
        return;
    }
    numPlayers++;
    Player** temp = new Player*[numPlayers];
    //copy over old players to temp
    for(int i=0;i<numPlayers-1;i++)
    {
        temp[i] = players[i];
    }
    temp[numPlayers-1] = player;
    delete [] players;
    players = temp;

    
}
// sorts array of Player pointers according to score and elo, score first then elo
void PlayerList::sort()
{
    // buble sort
    for(int i=0;i<numPlayers-1;++i)
    {
        for(int j=0;j<numPlayers-i-1;++j)
        {
            if(players[j]->getScore()<players[j+1]->getScore())
            {
                Player* temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
            }
            else if(players[j]->getScore()==players[j+1]->getScore())
            {
                if(players[j]->getELO()<players[j+1]->getELO())
                {
                    Player* temp = players[j];
                    players[j] = players[j+1];
                    players[j+1] = temp;
                }
            }
        }
    }
}

// returns a new dynamically allocated instance of PlayerList storing pointers to Players pointed at by the current PlayerList, from index startIndex to the index before endIndex.
PlayerList* PlayerList::splice(const int startIndex, const int endIndex) const
{
    // splice
    PlayerList* spliced_list = new PlayerList();
        // invalid indices, return default playerlist with no players
    if(startIndex<0 || endIndex>numPlayers || endIndex<=startIndex)
    {
        return spliced_list;
    }
    else 
    {
        for(int i=startIndex;i<endIndex;i++)
        {
            spliced_list->addPlayer(players[i]);
        }
    }
    return spliced_list;
}