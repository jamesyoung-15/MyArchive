#ifndef __MATCH_H__
#define __MATCH_H__

#include "player.h"

class Match {
    private:
        Player* p1;
        Player* p2;

    public:
        Match(Player* const p1, Player* const p2);

        void play();
};

#endif // __MATCH_H__
