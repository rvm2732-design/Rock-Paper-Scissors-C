# Rock Paper Scissors

A complete Rock Paper Scissors project developed in multiple stages, starting with a modular C console implementation and progressing to a 2D web-based version.

The project demonstrates programming fundamentals, modular code organization, file handling, game logic, and frontend development.

---

 Project Structure

```text
Rock-Paper-Scissors-C/
│
├── .vscode/
│   └── tasks.json
│
├── Backend/
│   ├── game.c
│   ├── game.h
│   ├── main.c
│   ├── menu.c
│   ├── menu.h
│   ├── verify_build.c
│   ├── README.md
│   └── rps.exe
│
├── RockPaperScissors2D/
│   ├── index.html
│   ├── css/
│   │   └── style.css
│   └── js/
│       ├── game.js
│       └── ui.js
│
├── RockPaperScissors/
│   ├── animation.c
│   └── animation.h
│
└── README.md

Project Versions
1. C Console Version

The original version of the game was developed in C.

It focuses on:

C programming fundamentals
Functions
Header files
Modular programming
Game logic
User input
Conditional statements
Loops
Random number generation
Console-based interface

The game allows the player to select:

Rock
Paper
Scissors

The computer generates its own choice and the winner is determined using the standard Rock Paper Scissors rules.

2. 2D Web Version

The project was later redesigned as a 2D web game.

The web version uses:

HTML
CSS
JavaScript
Emoji-based hand representations
Interactive buttons
Game score tracking
Player vs Computer gameplay
Dynamic UI updates
Hand Representation
Choice	Icon
Rock	✊
Paper	✋
Scissors	✌️

The 2D version does not require external image assets.

How the Game Works

The player selects one of the three choices:

Rock
Paper
Scissors

The computer randomly selects its choice.

The rules are:

Rock     beats Scissors
Scissors beats Paper
Paper    beats Rock

If both players select the same option, the round is a draw.

Technologies Used
C Version
C
GCC
VS Code
Modular .c and .h files
Web Version
HTML5
CSS3
JavaScript
VS Code

Web Version Structure
RockPaperScissors2D/
│
├── index.html
│
├── css/
│   └── style.css
│
└── js/
    ├── game.js
    └── ui.js
index.html

Contains the structure of the game interface.

style.css

Controls:

Layout
Typography
Buttons
Game cards
Scoreboard
Animations
Responsive styling
game.js

Contains the core game logic, including:

Player choice
Computer choice
Winner calculation
Score management
Round results
ui.js

Handles the interaction between the game logic and the webpage.
