# Warriors
by Yiu Yiu Yoyo Ho

## Description

### 1. **Game World:**
   - **Battlefield Grid Size:** 10 x 10
   - **Teams:**  
     - Each team has 4 Soldiers and 1 Queen.
   - **Rounds:**  
     - In each round, each team can only choose one warrior to either move or attack.

### 2. **Battle Setup:**
   - Two teams of warriors are randomly placed on the battlefield.
   - Warriors cannot occupy the same position.

### 3. **Game Rules:**

   - **Movement:**  
     - **Soldier:** Moves 1 unit in any direction, including diagonals.  
     - **Queen:** Moves 2 units in any direction except diagonals.

   - **Attack:**  
     - **Soldier:** Can attack an opposing warrior within 1 unit in any direction and take their position.  
     - **Queen:** Can attack only diagonally, either 1 or 2 units in range.

### 4. **Winning Condition:**
   - The last remaining team is declared the winner.

## How to Run
1. **Using Terminal:**
   - Open a terminal or command prompt window.
   - Navigate to the directory where the `program.exe` is located.
   - Type `program.exe` and hit Enter to run the program.

2. **Using GUI:**
   - Double-click the `program.exe` file to launch the application.

## Example Usage
```bash
Welcome to Warriors!
Two teams are going to battle...
Welcome to the Battle Simulator!
Team A and Team B are about to fight...
--------------------
Round 1:
Team A:
Queen -> ID: 0; Health: 15; Position: (0, 0)
Soldier -> ID: 1; Health: 10; Position: (2, 2)
Team B:
Queen -> ID: 0; Health: 15; Position: (2, 0)
Soldier -> ID: 1; Health: 10; Position: (1, 0)
Team A's turn:
Enter your warrior id: 0
Move(m) or Attack(a)? m
Queen at (0, 0) is moving.
Move 1: 0, 2
Pick your move: 1
Oueen  at (0, 0) moves to (0, 2).
--------------------
Team A:
Queen -> ID: 0; Health: 15; Position: (0, 2)
Soldier -> ID: 1; Health: 10; Position: (2, 2)
Team B:
Queen -> ID: 0; Health: 15; Position: (2, 0)
Soldier -> ID: 1; Health: 10; Position: (1, 0)
Team B's turn:
Enter your warrior id: 1
Move(m) or Attack(a)? a
Soldier 1 at (1, 0) is attacking.
No warriors are available for attack.
--------------------
Round 2:
Team A:
Queen -> ID: 0; Health: 15; Position: (0, 2)
Soldier -> ID: 1; Health: 10; Position: (2, 2)
Team B:
Queen -> ID: 0; Health: 15; Position: (2, 0)
Soldier -> ID: 1; Health: 10; Position: (1, 0)
Team A's turn:
Enter your warrior id: 1
Move(m) or Attack(a)? a
Soldier 1 at (2, 2) is attacking.
No warriors are available for attack.
--------------------
Team A:
Queen -> ID: 0; Health: 15; Position: (0, 2)
Soldier -> ID: 1; Health: 10; Position: (2, 2)
Team B:
Queen -> ID: 0; Health: 15; Position: (2, 0)
Soldier -> ID: 1; Health: 10; Position: (1, 0)
Team B's turn:
Enter your warrior id: 0
Move(m) or Attack(a)? a
Soldier 0 at (2, 0) is attacking.
Attack 1: 0, 2
Pick your attack: 1
Queen at (2, 0) attacks Queen at (0, 2) for 25 damange.
Queen at (0, 2) is dead.
--------------------
Round 3:
Team A:
Soldier -> ID: 1; Health: 10; Position: (2, 2)
Team B:
Queen -> ID: 0; Health: 15; Position: (2, 0)
Soldier -> ID: 1; Health: 10; Position: (1, 0)
Team A's turn:
Enter your warrior id: 1
Move(m) or Attack(a)? m
Soldier 1 at (2, 2) is moving.
Move 1: 1, 1
Move 2: 1, 2
Move 3: 2, 1
Pick your move: 1
Soldier 1 at (2, 2) moves to (1, 1).
--------------------
Team A:
Soldier -> ID: 1; Health: 10; Position: (1, 1)
Team B:
Queen -> ID: 0; Health: 15; Position: (2, 0)
Soldier -> ID: 1; Health: 10; Position: (1, 0)
Team B's turn:
Enter your warrior id: 1
Move(m) or Attack(a)? a
Soldier 1 at (1, 0) is attacking.
Attack 1: 1, 1
Pick your attack: 1
Soldier at (1, 0) attacks Soldier at (1, 1) for 15 damange.
Soldier at (1, 1) is dead.
Team B wins the battle!
--------------------
--------------------
--------------------
Press Enter to exit...


