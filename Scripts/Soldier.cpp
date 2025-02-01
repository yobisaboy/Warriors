#include "Soldier.h"
#include <iostream>
using namespace std;

Soldier::Soldier(int id, int x, int y) : Warrior(id, 10, 10, 15, x, y)
{
}

const string Soldier::getType() const
{
    return "Soldier";
}

void Soldier::attack(Team &enemies)
{
    int ogX, ogY;

    ogX = this->getPosition().at(0);
    ogY = this->getPosition().at(1);

    cout << "Soldier " << getId() << " at (" << ogX << ", " << ogY << ") is attacking." << endl;

    int option = 1;
    vector<Warrior *> enemyWarriors = enemies.warriors;
    set<pair<int, int>> optionAttacks;
    for (const auto &pos : unavailablePositions)
    {
        int sqX = (ogX - pos.first) * (ogX - pos.first);
        int sqY = (ogY - pos.second) * (ogY - pos.second);
        if (sqX + sqY == 1 || sqX + sqY == 2)
        {
            for (const auto &warrior : enemyWarriors)
            {
                int enemyX = warrior->getPosition().at(0);
                int enemyY = warrior->getPosition().at(1);
                if (enemyX == pos.first && enemyY == pos.second)
                {
                    cout << "Attack " << option << ": " << pos.first << ", " << pos.second << endl;
                    optionAttacks.insert({pos.first, pos.second});
                    option++;
                }
            }
        }
    }
    if (option == 1)
    {
        cout << "No warriors are available for attack." << endl;
    }
    else
    {
        int selectedAttack;
        cout << "Pick your attack: ";
        cin >> selectedAttack;

        auto it = optionAttacks.begin();
        std::advance(it, selectedAttack - 1);

        if (it != optionAttacks.end())
        {
            for (const auto &warrior : enemyWarriors)
            {
                int enemyX = warrior->getPosition().at(0);
                int enemyY = warrior->getPosition().at(1);
                if (enemyX == it->first && enemyY == it->second)
                {
                    warrior->setHealth(warrior->getHealth() - this->getDamagePower());

                    cout << this->getType() << " at (" << this->getPosition().at(0) << ", " << this->getPosition().at(1)
                         << ") attacks " << warrior->getType() << " at (" << warrior->getPosition().at(0) << ", " << warrior->getPosition().at(1)
                         << ") for " << this->getDamagePower() << " damange." << endl;

                    if (warrior->getHealth() > 0)
                    {
                        cout << warrior->getType() << " at (" << warrior->getPosition().at(0) << ", " << warrior->getPosition().at(1)
                             << ") is still alive with " << warrior->getHealth() << " health." << endl;
                    }
                    else
                    {
                        cout << warrior->getType() << " at (" << warrior->getPosition().at(0) << ", " << warrior->getPosition().at(1)
                             << ") is dead. " << endl;
                    }
                }
            }
        }
    }
}

void Soldier::move()
{
    int ogX, ogY;

    ogX = this->getPosition().at(0);
    ogY = this->getPosition().at(1);

    vector<vector<int>> availableMoves;

    for (const auto &pos : availablePositions)
    {
        if (unavailablePositions.find(pos) == unavailablePositions.end())
        {
            availableMoves.push_back({pos.first, pos.second});
        }
    }

    cout << "Soldier " << getId() << " at (" << ogX << ", " << ogY << ") is moving." << endl;

    int option = 1;
    set<pair<int, int>> optionMoves;
    for (const auto &pos : availableMoves)
    {
        int sqX = (ogX - pos[0]) * (ogX - pos[0]);
        int sqY = (ogY - pos[1]) * (ogY - pos[1]);
        if (sqX + sqY == 1 || sqX + sqY == 2)
        {
            cout << "Move " << option << ": " << pos[0] << ", " << pos[1] << endl;
            optionMoves.insert({pos[0], pos[1]});
            option++;
        }
    }
    if (optionMoves.size() > 0)
    {
        int selectedMove;
        cout << "Pick your move: ";
        cin >> selectedMove;

        auto it = optionMoves.begin();
        std::advance(it, selectedMove - 1);

        if (it != optionMoves.end())
        {
            unavailablePositions.erase({ogX, ogY});
            Warrior::setPosition(it->first, it->second);
            unavailablePositions.insert({Warrior::x, Warrior::y});

            cout << "Soldier " << getId() << " at (" << ogX << ", " << ogY << ") moves to (" << Warrior::x << ", " << Warrior::y << ")." << endl;
        }
    }
    else
    {
        cout << "No available moves." << endl;
    }
}
