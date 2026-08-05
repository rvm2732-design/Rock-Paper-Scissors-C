#include <stdio.h>
#include <stdlib.h>   // for srand()
#include <time.h>     // for time()

#include "game.h"
#include "menu.h"

int main(void) {
    Score score = {0, 0, 0, 0};
    int playAgain = 1;

    /* Seed the random number generator once at program start */
    srand((unsigned int)time(NULL));

    showWelcome();

    while (playAgain) {
        showMenu();

        Choice playerChoice = getPlayerChoice();
        Choice computerChoice = getComputerChoice();

        RoundResult result = determineWinner(playerChoice, computerChoice);

        displayResult(playerChoice, computerChoice, result);
        updateScore(&score, result);
        displayScore(&score);

        playAgain = askPlayAgain();
    }

    printf("\nThanks for playing! Final score:\n");
    displayScore(&score);
    printf("Goodbye!\n");

    return 0;
}