#include <iostream>
#include "Warrior.h"
#include "Queen.h"
#include "Soldier.h"
#include "BattleSimulator.h"
#include "Team.h"
#include <thread>
#include <cstdlib>

using namespace std;

// void printStatus(string teamName, Team &team)
// {
//     cout << teamName << ":" << endl;
//     for (Warrior *warrior : team.warriors)
//     {
//         cout << warrior->getType() << " -> ";
//         cout << "ID: " << warrior->getId();
//         cout << "; Health: " << warrior->getHealth();
//         cout << "; Position: (";
//         for (int i = 0; i < warrior->getPosition().size(); i++)
//         {
//             cout << warrior->getPosition().at(i);
//             if (i != warrior->getPosition().size() - 1)
//             {
//                 cout << ", ";
//             }
//         }
//         cout << ")" << endl;
//     }
// };

void checkGridSize(int gridSize, int numEachTypeWarriors)
{
    int checkGrid = (gridSize + 1) * (gridSize + 1);
    int checkWarriors = 4 * numEachTypeWarriors;

    if (checkGrid <= checkWarriors)
    {
        cout << "Not enough space for all warriors, increase the battle grid." << endl;
        cout << "Please restart the program..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        exit(0);
    }
}

int main()
{
    int gridSize = 2;
    int numEachTypeWarriors = 1;

    cout << "Welcome to Warriors!" << endl;
    cout << "Two teams are going to battle..." << endl;

    checkGridSize(gridSize, numEachTypeWarriors);

    Team teamA('A', gridSize, numEachTypeWarriors);
    Team teamB('B', gridSize, numEachTypeWarriors);

    BattleSimulator battleSimulator(teamA, teamB);

    battleSimulator.startBattle();

    cout << "Press Enter to exit..." << endl;
    cin.ignore();
    cin.get();

    return 0;
}
