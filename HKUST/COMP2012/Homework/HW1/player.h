#ifndef __CORE_H__
#define __CORE_H__

#include <iostream>

class Player {
    private:
        char* name;
        int elo;
        int score;

    public:
        // TASK 1: Implement the conversion constructor and destructor
        Player(const char* const name, const int elo);
        ~Player();

        // The following copy constructor and assignment operator are deleted
        Player(const Player& player) = delete;
        Player& operator=(const Player&) = delete;

        // The accessor, mutator and print functions are given
        int getELO() const { return elo; }
        int getScore() const { return score; }

        void addScore(const int points) { score += points; }

        void print() const {
            std::cout << name << " (" << elo << ")";
        }
};

class PlayerList {
    private:
        int numPlayers;
        Player** players;

    public:
        // TASK 2: Implement the default constructor, conversion constructor and destructor
        PlayerList();
        PlayerList(const PlayerList& list);
        ~PlayerList();

        // The following accessor functions are given
        int getNumPlayers() const { return numPlayers; }
        Player* getPlayer(const int index) const { return players[index]; }

        // TASK 3: Implement PlayerList insert, sort and splice
        void addPlayer(Player* const player);
        void sort();
        PlayerList* splice(const int startIndex, const int endIndex) const;
};

#endif // __CORE_H__
