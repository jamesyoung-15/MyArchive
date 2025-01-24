#include "match.h"

#include <iostream>

enum MatchResult { P1=1, P2, DRAW };

Match::Match(Player* const p1, Player* const p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

void Match::play() 
{
    // Print the match players
    p1->print();
    std::cout << " vs. ";
    p2->print();
    std::cout << std::endl;

    // User inputs match result
    int res;
    do {
        std::cin >> res;
    } while (res < P1 || res > DRAW);
    MatchResult result = static_cast<MatchResult>(res);

    switch (result) {
        case P1:
            // Print "P1 defeated P2"
            p1->print();
            std::cout << " defeated ";
            p2->print();
            std::cout << std::endl;
            p1->addScore(2);
            break;
        case P2:
            // Print "P2 defeated P1"
            p2->print();
            std::cout << " defeated ";
            p1->print();
            std::cout << std::endl;
            p2->addScore(2);
            break;
        case DRAW:
            // Print "P1 and P2 drew"
            p1->print();
            std::cout << " and ";
            p2->print();
            std::cout << " drew" << std::endl;
            p1->addScore(1);
            p2->addScore(1);
            break;
        default:
            break;
    }
}