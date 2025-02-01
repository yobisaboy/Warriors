#pragma once
#include "Team.h"
#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
class Team;
class Warrior
{
private:
    int id;
    int power;
    int health;
    int damagePower;

protected:
    int x;
    int y;

public:
    Warrior(int id, int health, int power, int damagePower, int x, int y);

    virtual void move() = 0;
    virtual void attack(Team &enemies) = 0;
    bool isAlive();
    virtual const string getType() const = 0;

    int getId();

    vector<int> getPosition();
    virtual void setPosition(int x, int y);

    int getDamagePower();
    int setDamagePower(int damagePower);

    int getHealth();
    int setHealth(int health);
    static std::set<std::pair<int, int>> availablePositions;
    static std::set<std::pair<int, int>> unavailablePositions;
};
