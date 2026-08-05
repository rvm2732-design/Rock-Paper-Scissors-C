#ifndef MENU_H
#define MENU_H

#include "game.h"

/* Prints the welcome banner shown once at program start */
void showWelcome(void);

/* Prints the round menu with the 3 choices + rules reminder */
void showMenu(void);

/* Prompts the player for a valid choice (1-3) and returns it.
 * Keeps asking until valid input is entered. */
Choice getPlayerChoice(void);

/* Asks the player if they want to play another round.
 * Returns 1 for yes, 0 for no. */
int askPlayAgain(void);

#endif /* MENU_H */