#include "swiss.h"

#include "match.h"

Swiss::Swiss(int numRounds, const PlayerList& list) : 
    curRound(0), numRounds(numRounds), list(list)
{
    this->list.sort();
}

Swiss::~Swiss()
{

}

void Swiss::play() {
    while (curRound < numRounds) {
        curRound += 1;
        
        int numScores = curRound * 2 - 1;
        PlayerList** lists = new PlayerList*[numScores];

        int startIndex = 0;
        for (int i=numScores-1; i>=0; --i) {
            int endIndex = startIndex;
            while (endIndex < list.getNumPlayers() && list.getPlayer(endIndex)->getScore() == i) {
                ++endIndex;
            }
            // endIndex should now be the index of the first player with lower score than i
            lists[i] = list.splice(startIndex, endIndex);
            startIndex = endIndex;
        }

        for (int i=numScores-1; i>=0; --i) {
            if (lists[i]->getNumPlayers() == 0) continue;
            lists[i]->sort();

            // Find the middle ranked player M
            // who is the first player in pot 2
            // If there are odd players, the last player will be moved to the next pairing list
            int midIndex = lists[i]->getNumPlayers() / 2;

            // Pair player 1 with M, player 2 with M+1, etc.
            for (int j=0; j<midIndex; ++j) {
                Match m {lists[i]->getPlayer(j), lists[i]->getPlayer(j + midIndex)};
                m.play();
            }

            // If there is a player left, push that player to the next list
            if (lists[i]->getNumPlayers() % 2 == 1) {
                Player* lastPlayer = lists[i]->getPlayer(lists[i]->getNumPlayers() - 1);
                // If this is the last group, this player receives a bye
                if (i == 0) {
                    lastPlayer->addScore(2);
                }
                else {
                    lists[i-1]->addPlayer(lastPlayer);
                }
            }
        }

        list.sort();
        printLeaderboard();

        for (int i=0; i<numScores; ++i) {
            delete lists[i];
        }
        delete [] lists;

    }
}
