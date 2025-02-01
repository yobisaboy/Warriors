#pragma once

#include "Team.h"
#include <iostream>
using namespace std;


class BattleSimulator
{
private:
    int roundNumber;
    Team teamA;
    Team teamB;


public:
    BattleSimulator(Team teamA, Team teamB);

    void startBattle();
    void inBattle(string teamName, Team &team, Team &enemies);    
    void endBattle();

};
