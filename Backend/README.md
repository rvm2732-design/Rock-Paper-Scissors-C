# Rock Paper Scissors (Console Game)

A simple console-based Rock Paper Scissors game written in C, where a player
competes against the computer across as many rounds as they like.

## Folder Structure

```
RockPaperScissors/
│
├── src/
│   ├── main.c
│   ├── game.c
│   ├── menu.c
│
├── include/
│   ├── game.h
│   ├── menu.h
│
├── docs/
│   └── PRD.md
│
└── README.md
```

## Building

From the project root:

```bash
gcc -Wall -Wextra -std=c11 src/main.c src/game.c src/menu.c -o rps
```

## Running

```bash
./rps
```

## How to Play

1. On your turn, enter `1` for Rock, `2` for Paper, or `3` for Scissors.
2. The computer randomly picks one of the three.
3. The winner is determined using standard rules:
   - Rock beats Scissors
   - Scissors beats Paper
   - Paper beats Rock
   - Same choice = Draw
4. The score is tracked across rounds.
5. After each round you're asked whether you want to play again (`y`/`n`).

## Skills Practiced

- Variables
- if-else / switch statements
- Loops
- Functions
- Random numbers (`rand()`)
- Header files
- Modular programming (split across `main.c`, `game.c`, `menu.c`)
- Basic C project structure

## Future Improvements

- Best of 5 mode
- Difficulty levels
- Multiplayer mode
- Save high scores
- Colorful terminal output
- GUI version using SDL
- Online multiplayer