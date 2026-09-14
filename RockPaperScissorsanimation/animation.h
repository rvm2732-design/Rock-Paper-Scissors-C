#ifndef ANIMATION_H
#define ANIMATION_H

#include "../game.h"

/* Clears the terminal screen (cls on Windows, clear on POSIX) */
void clearScreen(void);

/* Sleeps for the given number of milliseconds (cross-platform) */
void sleepMs(int milliseconds);

/* Plays the "Rock... Paper... Scissors... Shoot!" countdown */
void playCountdown(void);

/* Plays a quick shake/cycle animation before revealing both choices,
 * then prints the final reveal frame */
void playShakeAnimation(Choice playerChoice, Choice computerChoice);

#endif /* ANIMATION_H */