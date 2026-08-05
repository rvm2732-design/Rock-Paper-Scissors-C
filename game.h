#ifndef GAME_H
#define GAME_H

/* Choices are represented as:
 *   1 -> Rock
 *   2 -> Paper
 *   3 -> Scissors
 */
typedef enum {
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
} Choice;

/* Result of a single round, from the player's perspective */
typedef enum {
    RESULT_DRAW = 0,
    RESULT_WIN = 1,
    RESULT_LOSE = 2
} RoundResult;

/* Keeps track of the running score across rounds */
typedef struct {
    int playerScore;
    int computerScore;
    int draws;
    int roundsPlayed;
} Score;

/* Generates a random choice for the computer (1-3) */
Choice getComputerChoice(void);

/* Converts a Choice enum value to its display string ("Rock"/"Paper"/"Scissors") */
const char *choiceToString(Choice choice);

/* Compares the player's choice against the computer's choice and
 * returns the result from the player's point of view */
RoundResult determineWinner(Choice playerChoice, Choice computerChoice);

/* Prints the round summary: both choices and the outcome */
void displayResult(Choice playerChoice, Choice computerChoice, RoundResult result);

/* Updates the running score based on the round result */
void updateScore(Score *score, RoundResult result);

/* Prints the current score */
void displayScore(const Score *score);

#endif /* GAME_H */