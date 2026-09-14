#ifndef GAME_H
#define GAME_H


typedef enum {
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
} Choice;

 
typedef enum {
    RESULT_DRAW = 0,
    RESULT_WIN = 1,
    RESULT_LOSE = 2
} RoundResult;


typedef struct {
    int playerScore;
    int computerScore;
    int draws;
    int roundsPlayed;
} Score;


Choice getComputerChoice(void);


const char *choiceToString(Choice choice);


RoundResult determineWinner(Choice playerChoice, Choice computerChoice);

/* Prints the round summary: both choices and the outcome */
void displayResult(Choice playerChoice, Choice computerChoice, RoundResult result);

/* Updates the running score based on the round result */
void updateScore(Score *score, RoundResult result);


void displayScore(const Score *score);

#endif 