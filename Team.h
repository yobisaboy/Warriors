#pragma once

#include "Warrior.h"
#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
class Warrior;
class Team
{
private:
    int numberOfSoldiers;
    int numberOfQueens;
    int teamSize;
    char teamName;

public:
    static int gridSize;
    vector<Warrior *> warriors;
    Team(char teamName, int gridSize, int teamSize);
    void addWarrior(int id, string warriorType);
    //vector<Warrior *> attackOpponent(Team &enemies);
    bool isTeamAlive();
    static std::set<std::pair<int, int>> totalPositions;
    static std::set<std::pair<int, int>> usedPositions;
};
