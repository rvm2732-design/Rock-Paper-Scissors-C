#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

Choice getComputerChoice(void) {
    /* rand() % 3 gives 0-2, add 1 to map onto ROCK(1)/PAPER(2)/SCISSORS(3) */
    return (Choice)(rand() % 3 + 1);
}

const char *choiceToString(Choice choice) {
    switch (choice) {
        case ROCK:     return "Rock";
        case PAPER:    return "Paper";
        case SCISSORS: return "Scissors";
        default:       return "Unknown";
    }
}

RoundResult determineWinner(Choice playerChoice, Choice computerChoice) {
    if (playerChoice == computerChoice) {
        return RESULT_DRAW;
    }

    switch (playerChoice) {
        case ROCK:
            return (computerChoice == SCISSORS) ? RESULT_WIN : RESULT_LOSE;
        case PAPER:
            return (computerChoice == ROCK) ? RESULT_WIN : RESULT_LOSE;
        case SCISSORS:
            return (computerChoice == PAPER) ? RESULT_WIN : RESULT_LOSE;
        default:
            return RESULT_DRAW;
    }
}

void displayResult(Choice playerChoice, Choice computerChoice, RoundResult result) {
    printf("\nYou chose:      %s\n", choiceToString(playerChoice));
    printf("Computer chose: %s\n", choiceToString(computerChoice));

    switch (result) {
        case RESULT_WIN:
            printf(">> You Win!\n");
            break;
        case RESULT_LOSE:
            printf(">> Computer Wins!\n");
            break;
        case RESULT_DRAW:
        default:
            printf(">> It's a Draw!\n");
            break;
    }
}

void updateScore(Score *score, RoundResult result) {
    if (score == NULL) {
        return;
    }

    score->roundsPlayed++;

    switch (result) {
        case RESULT_WIN:
            score->playerScore++;
            break;
        case RESULT_LOSE:
            score->computerScore++;
            break;
        case RESULT_DRAW:
        default:
            score->draws++;
            break;
    }
}

void displayScore(const Score *score) {
    if (score == NULL) {
        return;
    }

    printf("\n----- SCOREBOARD -----\n");
    printf("Rounds Played : %d\n", score->roundsPlayed);
    printf("You           : %d\n", score->playerScore);
    printf("Computer      : %d\n", score->computerScore);
    printf("Draws         : %d\n", score->draws);
    printf("-----------------------\n");
}