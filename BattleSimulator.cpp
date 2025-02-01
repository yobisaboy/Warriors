#include "BattleSimulator.h"
#include <iostream>
using namespace std;
// #include <thread>
// #include <chrono>

BattleSimulator::BattleSimulator(Team teamA, Team teamB)
    : roundNumber(1), teamA(teamA), teamB(teamB)
{
    cout << "Welcome to the Battle Simulator!" << endl;
    cout << "Team A and Team B are about to fight..." << endl;
}
void printStatus(string teamName, Team &team)
{

    cout << teamName << ":" << endl;
    for (Warrior *warrior : team.warriors)
    {
        cout << warrior->getType() << " -> ";
        cout << "ID: " << warrior->getId();
        cout << "; Health: " << warrior->getHealth();
        cout << "; Position: (";
        for (int i = 0; i < warrior->getPosition().size(); i++)
        {
            cout << warrior->getPosition().at(i);
            if (i != warrior->getPosition().size() - 1)
            {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }
};

void BattleSimulator::startBattle()
{
    cout << "--------------------" << endl;
    cout << "Round " << roundNumber << ":" << endl;
    if (teamA.isTeamAlive())
    {
        printStatus("Team A", teamA);
        printStatus("Team B", teamB);
        inBattle("A", teamA, teamB);
    }
    cout << "--------------------" << endl;

    if (teamB.isTeamAlive())
    {
        printStatus("Team A", teamA);
        printStatus("Team B", teamB);
        inBattle("B", teamB, teamA);
    }

    endBattle();
    cout << "--------------------" << endl;
}

void BattleSimulator::inBattle(string teamName, Team &team, Team &enemies)
{
    cout << "Team " << teamName << "'s turn:" << endl;

    bool validWarrior = false;
    int warriorIndex;
    do
    {
        cout << "Enter your warrior id: ";
        cin >> warriorIndex;
        for (const auto &warrior : team.warriors)
        {
            if (warrior->getId() == warriorIndex)
            {
                validWarrior = true;
                break;
            }
        
        }
    } while (validWarrior == false);

    if (!validWarrior)
    {
        cout << "Invalid warrior id!" << endl;
        cout << "--------------------" << endl;
    }

    bool validMove = false;

    do
    {
        char moveChoice;
        cout << "Move(m) or Attack(a)? ";
        cin >> moveChoice;
        if (moveChoice == 'm' || moveChoice == 'M')
        {
            // move
            for (const auto &warrior : team.warriors)
            {
                if (warrior->getId() == warriorIndex)
                {
                    warrior->move();
                }
            }

            validMove = true;
        }
        else if (moveChoice == 'a' || moveChoice == 'A')
        {
            // attack
            for (const auto &warrior : team.warriors)
            {
                if (warrior->getId() == warriorIndex)
                {
                    warrior->attack(enemies);
                }
            }

            validMove = true;
        }
        else
        {
            cout << "Invalid choice!" << endl;
            cout << "--------------------" << endl;
        }
    } while (validMove == false);
}

void BattleSimulator::endBattle()
{
    if (!teamA.isTeamAlive())
    {
        cout << "Team B wins the battle!" << endl;
    }
    else if (!teamB.isTeamAlive())
    {
        cout << "Team A wins the battle!" << endl;
    }
    else
    {
        roundNumber++;
        startBattle();
    }
}