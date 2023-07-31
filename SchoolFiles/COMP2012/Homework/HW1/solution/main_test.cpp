#include <iostream>
#include <cstring>
#include <string>

#include "player.h"
#include "match.h"
#include "swiss.h"

bool SELECT_PROMPT = false;

int main() {
    if (SELECT_PROMPT) std::cout << "Select testing module: ";
    int mode;
    std::cin >> mode;
    if (SELECT_PROMPT) std::cout << std::endl;
    std::cin.get();

    if (mode == 1) {
        std::cout << "Testing task 1: Player constructor/destructor" << std::endl;

        if (SELECT_PROMPT) std::cout << "Select test case: ";
        int caseNum;
        std::cin >> caseNum;
        if (SELECT_PROMPT) std::cout << std::endl;
        std::cin.get();

        switch (caseNum) {
            case 1:
                {
                    std::cout << "Test case 1 selected." << std::endl;
                    Player p {"Test", 1000};
                    p.print(); std::cout << std::endl;
                }
                break;
            case 2:
                {
                    std::cout << "Test case 2 selected." << std::endl;
                    char name[] {'T', 'e', 's', 't', '\0'};
                    Player p {name, 1000};
                    p.print(); std::cout << std::endl;
                    name[3] = 'f';
                    p.print(); std::cout << std::endl;
                }
                break;
            case 3:
                {
                    std::cout << "Test case 3 selected." << std::endl;
                    const char* name = "Test";
                    Player p1 {name, 1000};
                    {
                        Player p2 {name, 2000};
                        p2.print(); std::cout << std::endl;
                    }
                    p1.print(); std::cout << std::endl;
                }
                break;
            default:
                std::cout << "Unrecognized test case." << std::endl;
                break;
        }
    }
    else if (mode == 2) {
        std::cout << "Testing task 2: PlayerList constructor/destructor & task 3: addPlayer()" << std::endl;

        Player a {"Alice", 1000};
        Player b {"Bob", 1500};
        Player c {"Carol", 2000};
        Player d {"David", 2500};

        if (SELECT_PROMPT) std::cout << "Select test case: ";
        int caseNum;
        std::cin >> caseNum;
        if (SELECT_PROMPT) std::cout << std::endl;
        std::cin.get();

        switch (caseNum) {
            case 1:
                {
                    std::cout << "Test case 1 selected." << std::endl;
                    PlayerList empty;
                    std::cout << "Empty PlayerList has " << empty.getNumPlayers() << " players." << std::endl;
                }
                break;
            case 2:
                {
                    std::cout << "Test case 2 selected." << std::endl;
                    PlayerList pl;
                    pl.addPlayer(&a);
                    pl.addPlayer(&b);
                    pl.addPlayer(&c);
                    pl.addPlayer(&d);
                    std::cout << "PlayerList has " << pl.getNumPlayers() << " players." << std::endl;
                }
                break;
            case 3:
                {
                    std::cout << "Test case 3 selected." << std::endl;
                    PlayerList pl;
                    pl.addPlayer(&a);
                    pl.addPlayer(&b);
                    pl.addPlayer(&c);
                    pl.addPlayer(&d);
                    PlayerList copy {pl};
                    std::cout << "Copied PlayerList has " << copy.getNumPlayers() << " players." << std::endl;
                }
                break;
            case 4:
                {
                    std::cout << "Test case 4 selected." << std::endl;
                    PlayerList pl;
                    pl.addPlayer(&a);
                    pl.addPlayer(&b);
                    PlayerList copy {pl};
                    copy.getPlayer(0)->addScore(2);
                    std::cout << "Copied PlayerList player 0's score is " << copy.getPlayer(0)->getScore() << "." << std::endl;
                    std::cout << "Original PlayerList player 0's score is " << pl.getPlayer(0)->getScore() << "." << std::endl;
                }
                break;
            case 5:
                {
                    std::cout << "Test case 5 selected." << std::endl;
                    PlayerList pl;
                    pl.addPlayer(&a);
                    pl.addPlayer(&b);
                    PlayerList copy {pl};
                    copy.addPlayer(&c);
                    copy.addPlayer(&d);
                    std::cout << "Copied PlayerList has " << copy.getNumPlayers() << " players." << std::endl;
                    std::cout << "Original PlayerList has " << pl.getNumPlayers() << " players." << std::endl;
                }
                break;
            case 6:
                {
                    std::cout << "Test case 6 selected." << std::endl;
                    PlayerList pl;
                    pl.addPlayer(&a);
                    pl.addPlayer(&b);
                    {
                        PlayerList copy {pl};
                        copy.addPlayer(&c);
                        copy.getPlayer(0)->addScore(1);
                    }
                    std::cout << "PlayerList has " << pl.getNumPlayers() << " players." << std::endl;
                    // std::cout << "PlayerList player 0's score is " << pl.getPlayer(0)->getScore() << "." << std::endl;
                }
                break;
            case 7:
                {
                    std::cout << "Test case 7 selected." << std::endl;
                    PlayerList pl;

                    Player** players = new Player*[26];
                    for (int i=0; i<13; ++i) {
                        players[i] = new Player(std::string(1, 'A' + i).c_str(), 1000 + 101 * i % 1000);
                        pl.addPlayer(players[i]);
                    }

                    pl.getPlayer(10)->addScore(2);
                    PlayerList copy {pl};
                    copy.getPlayer(10)->addScore(2);

                    for (int i=13; i<26; ++i) {
                        players[i] = new Player(std::string(1, 'A' + i).c_str(), 1000 + 103 * i % 1000);
                        pl.addPlayer(players[i]);
                    }

                    {
                        PlayerList copy2 {pl};
                        copy2.getPlayer(10)->addScore(1);
                    }

                    std::cout << "Copied PlayerList has " << copy.getNumPlayers() << " players." << std::endl;
                    std::cout << "Original PlayerList has " << pl.getNumPlayers() << " players." << std::endl;
                    // std::cout << "PlayerList player 10's score is " << pl.getPlayer(10)->getScore() << "." << std::endl;

                    for (int i=0; i<26; ++i) {
                        delete players[i];
                    }
                    delete [] players;
                }
                break;
            default:
                std::cout << "Unrecognized test case." << std::endl;
                break;
        }
    }
    else if (mode == 3) {
        std::cout << "Testing task 3: sort() and splice()" << std::endl;

        Player a {"Alice", 1000};
        Player b {"Bob", 1500};
        Player c {"Carol", 2000};
        Player d {"David", 2500};
        PlayerList pl;
        pl.addPlayer(&a);
        pl.addPlayer(&d);
        pl.addPlayer(&c);
        pl.addPlayer(&b);

        if (SELECT_PROMPT) std::cout << "Select test case: ";
        int caseNum;
        std::cin >> caseNum;
        if (SELECT_PROMPT) std::cout << std::endl;
        std::cin.get();

        switch (caseNum) {
            case 1:
                {
                    std::cout << "Test case 1 selected." << std::endl;
                    pl.sort();
                    for (int i=0; i<pl.getNumPlayers(); ++i) {
                        pl.getPlayer(i)->print(); std::cout << ": " << pl.getPlayer(i)->getScore() << std::endl;
                    }
                }
                break;
            case 2:
                {
                    std::cout << "Test case 2 selected." << std::endl;
                    a.addScore(2);
                    pl.sort();
                    for (int i=0; i<pl.getNumPlayers(); ++i) {
                        pl.getPlayer(i)->print(); std::cout << ": " << pl.getPlayer(i)->getScore() << std::endl;
                    }
                }
                break;
            case 3:
                {
                    std::cout << "Test case 3 selected." << std::endl;
                    a.addScore(1);
                    c.addScore(1);
                    pl.sort();
                    for (int i=0; i<pl.getNumPlayers(); ++i) {
                        pl.getPlayer(i)->print(); std::cout << ": " << pl.getPlayer(i)->getScore() << std::endl;
                    }
                }
                break;
            case 4:
                {
                    std::cout << "Test case 4 selected." << std::endl;
                    PlayerList* spl = pl.splice(0, 2);
                    std::cout << "Splice has " << spl->getNumPlayers() << " players." << std::endl;
                    // std::cout << "Splice player 0's ELO is " << spl->getPlayer(0)->getELO() << "." << std::endl;
                    // std::cout << "Splice player 1's ELO is " << spl->getPlayer(1)->getELO() << "." << std::endl;
                    delete spl;
                }
                break;
            case 5:
                {
                    std::cout << "Test case 5 selected." << std::endl;
                    PlayerList* spl = pl.splice(3, 3);
                    if (spl)
                        std::cout << "Splice has " << spl->getNumPlayers() << " players." << std::endl;
                    else
                        std::cout << "Splice has 0 players." << std::endl;
                    delete spl;
                }
                break;
            case 6:
                {
                    std::cout << "Test case 6 selected." << std::endl;
                    PlayerList* spl = pl.splice(-1, 8);
                    if (spl)
                        std::cout << "Splice has " << spl->getNumPlayers() << " players." << std::endl;
                    else
                        std::cout << "Splice has 0 players." << std::endl;
                    delete spl;
                }
                break;
            case 7:
                {
                    std::cout << "Test case 7 selected." << std::endl;
                    PlayerList pl;

                    Player** players = new Player*[26];
                    for (int i=0; i<26; ++i) {
                        players[i] = new Player(std::string(1, 'A' + i).c_str(), 1000 + 107 * i % 1000);
                        players[i]->addScore(i % 5);
                        pl.addPlayer(players[i]);
                    }

                    pl.sort();
                    for (int i=0; i<pl.getNumPlayers(); ++i) {
                        pl.getPlayer(i)->print(); std::cout << ": " << pl.getPlayer(i)->getScore() << std::endl;
                    }

                    for (int i=0; i<26; ++i) {
                        delete players[i];
                    }
                    delete [] players;
                }
                break;
            default:
                std::cout << "Unrecognized test case." << std::endl;
                break;
        }
    }
    else if (mode == 4) {
        std::cout << "Testing task 4: Swiss constructor" << std::endl;

        if (SELECT_PROMPT) std::cout << "Select test case: ";
        int caseNum;
        std::cin >> caseNum;
        if (SELECT_PROMPT) std::cout << std::endl;
        std::cin.get();

        switch (caseNum) {
            case 1:
                {
                    std::cout << "Test case 1 selected." << std::endl;
                    Player a {"Alice", 1000};
                    Player b {"Bob", 1500};
                    Player c {"Carol", 2000};
                    Player d {"David", 2500};
                    PlayerList pl;
                    pl.addPlayer(&a);
                    pl.addPlayer(&d);
                    pl.addPlayer(&c);
                    pl.addPlayer(&b);

                    Swiss s {1, pl};
                    s.printLeaderboard();
                }
                break;
            case 2:
                {
                    std::cout << "Test case 2 selected." << std::endl;
                    PlayerList pl;

                    Player** players = new Player*[26];
                    for (int i=0; i<26; ++i) {
                        players[i] = new Player(std::string(1, 'A' + i).c_str(), 1000 + 109 * i % 1000);
                        pl.addPlayer(players[i]);
                    }

                    Swiss s {1, pl};
                    s.printLeaderboard();

                    for (int i=0; i<26; ++i) {
                        delete players[i];
                    }
                    delete [] players;
                }
                break;
            default:
                std::cout << "Unrecognized test case." << std::endl;
                break;
        }
    }
    else if (mode == 5) {
        std::cout << "Testing task 5: Swiss::play()" << std::endl;

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
        }
    else {
        std::cout << "Unrecognized test case." << std::endl;
    }

    return 0;
}