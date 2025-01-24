#include <iostream>

#include "player.h"
#include "match.h"
#include "swiss.h"

int main() {
    std::cout << "Please input number of players: ";
    int numPlayers;
    std::cin >> numPlayers;
    std::cout << std::endl;
    std::cin.get();

    Player** players = new Player*[numPlayers];
    PlayerList list;
    
    std::cout << "Please input each players' names followed by their ELO rating." << std::endl;
    for (int i=0; i<numPlayers; ++i) {
        char name[30];
        std::cin.getline(name, sizeof(name));

        char elo_str[30];
        std::cin.getline(elo_str, sizeof(elo_str));
        int elo = atoi(elo_str);

        players[i] = new Player{name, elo};
        list.addPlayer(players[i]);
    }

    std::cout << "Please input number of rounds: ";
    int numRounds;
    std::cin >> numRounds;
    std::cout << std::endl;

    Swiss s {numRounds, list};
    s.printLeaderboard();
    s.play();

    for (int i=0; i<numPlayers; ++i) {
        delete players[i];
    }
    delete [] players;

    return 0;
}