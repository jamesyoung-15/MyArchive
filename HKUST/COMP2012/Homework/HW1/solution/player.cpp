#include "player.h"

#include <cstring>

//========== PLAYER ==========//

Player::Player(const char* const name, const int elo)
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->elo = elo;
    this->score = 0;
}

Player::~Player()
{
    delete [] name;
}

//========== PLAYER LIST ==========//

PlayerList::PlayerList()
{
    this->numPlayers = 0;
    this->players = nullptr;
}

PlayerList::PlayerList(const PlayerList &list)
{
    this->numPlayers = list.numPlayers;
    this->players = new Player*[this->numPlayers];
    for (int i=0; i<this->numPlayers; ++i) {
        this->players[i] = list.players[i];
    }
}

PlayerList::~PlayerList()
{
    delete [] players;
}

void PlayerList::addPlayer(Player* const player) {
    // Copy all players to a new array with increased size
    Player** temp = new Player*[numPlayers + 1];
    for (int i=0; i<numPlayers; ++i) {
        temp[i] = players[i];
    }
    // Add the new player at the end
    temp[numPlayers] = player;
    // Clean up
    delete [] players;
    players = temp;
    numPlayers += 1;
}

void PlayerList::sort() {
    for (int i=numPlayers-1; i>=0; --i) {
        for (int j=0; j<i; ++j) {
            // Swap left and right's player content if needed
            if (players[j]->getScore() < players[j+1]->getScore() || (
                players[j]->getScore() == players[j+1]->getScore() && players[j]->getELO() < players[j+1]->getELO()
            )) {
                Player* temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
            }
        }
    }
}

PlayerList* PlayerList::splice(const int startIndex, const int endIndex) const
{
    if (startIndex < 0 || endIndex > numPlayers) return new PlayerList;
    if (endIndex <= startIndex) return new PlayerList;
    PlayerList* list = new PlayerList;
    list->numPlayers = endIndex - startIndex;
    list->players = new Player*[list->numPlayers];
    for (int i=0; i<list->numPlayers; ++i) {
        list->players[i] = players[startIndex + i];
    }
    return list;
}
