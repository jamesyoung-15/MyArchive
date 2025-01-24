#ifndef __SWISS_H__
#define __SWISS_H__

#include "player.h"

class Swiss {
    private:
        int curRound;
        int numRounds;
        PlayerList list;

    public:
        // TASK 4: Implement the conversion constructor and destructor
        Swiss(const int numRounds, const PlayerList& list);
        ~Swiss();

        // TASK 5: Implement the function to conduct the Swiss tournament
        void play();

        // The leaderboard print function is given
        void printLeaderboard() const {
            std::cout << "===================================" << std::endl;
            std::cout << "ROUND " << curRound << "/" << numRounds << " ENDED." << std::endl;
            for (int i=0; i<list.getNumPlayers(); ++i) {
                list.getPlayer(i)->print();
                std::cout << ": " << list.getPlayer(i)->getScore() << std::endl;
            }
            std::cout << "===================================" << std::endl;
        }
};

#endif // __SWISS_H__