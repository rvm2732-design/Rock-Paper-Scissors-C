#include <stdio.h>
#include <ctype.h>
#include "menu.h"
#include "RockPaperScissorsanimation/animation.h"

/* Small helper to flush any leftover characters (e.g. bad input) from stdin */
static void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        
    }
}

void showWelcome(void) {
    printf("=======================================\n");
    printf("     ROCK - PAPER - SCISSORS GAME       \n");
    printf("=======================================\n");
    printf("Beat the computer across as many rounds\n");
    printf("as you like. Good luck!\n");
}

void showMenu(void) {
    printf("\n--------- Make your move ---------\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("-----------------------------------\n");
    printf("Enter your choice (1-3): ");
}

Choice getPlayerChoice(void) {
    int input;
    int result;

    while (1) {
        result = scanf("%d", &input);

        if (result == 1 && input >= 1 && input <= 3) {
            clearInputBuffer();
            return (Choice)input;
        }

        
        clearInputBuffer();
        printf("Invalid choice. Please enter 1 (Rock), 2 (Paper), or 3 (Scissors): ");
    }
}

int askPlayAgain(void) {
    char response;

    printf("\nPlay again? (y/n): ");
    if (scanf(" %c", &response) != 1) {
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();

    return (tolower((unsigned char)response) == 'y');
}