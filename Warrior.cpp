#include "Warrior.h"
#include "Team.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>
using namespace std;
std::set<std::pair<int, int>> Warrior::unavailablePositions;
std::set<std::pair<int, int>> Warrior::availablePositions;
Warrior::Warrior(int id, int health, int power, int damagePower, int x, int y)
{
    this->id = id;
    this->health = health;
    this->power = power;
    this->damagePower = damagePower;
    this->x = x;
    this->y = y;

    srand(time(0));

    for (const auto &pos : Team::totalPositions)
    {
        availablePositions.insert({pos.first, pos.second});
    }

    for (const auto &pos : Team::usedPositions)
    {
        unavailablePositions.insert({pos.first, pos.second});
    }
}

// void Warrior::move()
// {

//     int ogX, ogY;
//     ogX = x;
//     ogY = y;
//     vector<vector<int>> availableMoves;

//     for (const auto &pos : availablePositions)
//     {
//         if (unavailablePositions.find(pos) == unavailablePositions.end())
//         {
//             availableMoves.push_back({pos.first, pos.second});
//         }
//     }

//     for (const auto &pos : availableMoves)
//     {
//         int sqX = (x - pos[0]) * (x - pos[0]);
//         int sqY = (y - pos[1]) * (y - pos[1]);
//         if (sqX + sqY == 1 || sqX + sqY == 2)
//         {
//             unavailablePositions.erase({x, y});
//             setPosition(pos[0], pos[1]);
//             unavailablePositions.insert({x, y});
//             cout << " moves to (" << x << ", " << y << ")." << endl;
//             break;
//         }
//     }

//     if (ogX == x && ogY == y)
//     {
//         cout << " has no available moves." << endl;
//     }
// }

bool Warrior::isAlive()
{
    return health > 0;
}

int Warrior::getId()
{
    return id;
}

vector<int> Warrior::getPosition()
{
    return {x, y};
}

void Warrior::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Warrior::getDamagePower()
{
    return damagePower;
}

int Warrior::setDamagePower(int damagePower)
{
    this->damagePower = damagePower;
    return damagePower;
}

int Warrior::getHealth()
{
    return health;
}

int Warrior::setHealth(int health)
{
    this->health = health;
    return health;
}