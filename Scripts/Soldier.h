#pragma once

#include "Warrior.h"
#include "Team.h"

class Soldier : public Warrior
{
private:
    int x;
    int y;
    int id;

public:
    Soldier(int id, int x, int y);

    const string getType() const override;
    void attack(Team &enemies) override;
    void move() override;
};
