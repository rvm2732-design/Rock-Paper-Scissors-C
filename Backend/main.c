#include <stdio.h>
#include <stdlib.h>  
#include <time.h>     

#include "game.h"
#include "menu.h"
#include "RockPaperScissorsanimation/animation.h"

int main(void) {
    Score score = {0, 0, 0, 0};
    int playAgain = 1;

    
    srand((unsigned int)time(NULL));

    showWelcome();

    while (playAgain) {
        showMenu();

        Choice playerChoice = getPlayerChoice();
        Choice computerChoice = getComputerChoice();

        playCountdown();
        playShakeAnimation(playerChoice, computerChoice);

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