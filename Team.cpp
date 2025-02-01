#include "Team.h"
#include "Soldier.h"
#include "Queen.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>

using namespace std;
std::set<std::pair<int, int>> Team::totalPositions;
std::set<std::pair<int, int>> Team::usedPositions;
int Team::gridSize = 0;
Team::Team(char teamName, int gridSize, int teamSize)
{
    srand(time(0) + reinterpret_cast<uintptr_t>(this));
    this->teamName = teamName;
    this->gridSize = gridSize + 1;
    this->teamSize = teamSize;

    this->numberOfSoldiers = teamSize;
    this->numberOfQueens = 1;

    for (int x = 0; x < this->gridSize; x++)
    {
        for (int y = 0; y < this->gridSize; y++)
        {
            totalPositions.insert({x, y});
        }
    }

    addWarrior(0, "Queen");

    for (int i = 1; i <= numberOfSoldiers; i++)
    {
        addWarrior(i, "Soldier");
    }
}

void Team::addWarrior(int id, string warriorType)
{

    int x, y;
    do
    {
        x = rand() % gridSize;
        y = rand() % gridSize;
    } while (usedPositions.find({x, y}) != usedPositions.end());

    usedPositions.insert({x, y});

    if (warriorType == "Queen")
    {
        Queen *queen = new Queen(id, x, y);
        warriors.push_back(queen);
    }
    else if (warriorType == "Soldier")
    {
        Soldier *soldier = new Soldier(id, x, y);
        warriors.push_back(soldier);
    }
}

// vector<Warrior *> Team::attackOpponent(Team &enemies)
// {
//     int warriorIndex = rand() % warriors.size();
//     int enemyIndex = rand() % enemies.warriors.size();
//     cout << warriors[warriorIndex]->getType() << ") at ("
//          << warriors[warriorIndex]->getPosition().at(0) << ", " << warriors[warriorIndex]->getPosition().at(1) << ")";
//     warriors[warriorIndex]->move();
//     warriors[warriorIndex]->attack(enemies.warriors[enemyIndex]);
//     vector<Warrior *> battleWarriors = {warriors[warriorIndex], enemies.warriors[enemyIndex]};
//     return battleWarriors;
// }

bool Team::isTeamAlive()
{
    for (int i = 0; i < warriors.size(); i++)
    {
        if (!warriors[i]->isAlive())
        {
            warriors.erase(warriors.begin() + i);
        }
    }
    return !warriors.empty();
}
