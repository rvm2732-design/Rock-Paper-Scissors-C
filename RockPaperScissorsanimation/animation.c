#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include "animation.h"
#include "../game.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void sleepMs(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* Small ASCII faces used while "shaking" through choices */
static const char *shakeFrames[3] = {
    "  ( )  Rock",
    "  [~]  Paper",
    " <'>'>  Scissors"
};

void playCountdown(void) {
    const char *beats[] = { "Rock...", "Paper...", "Scissors...", "SHOOT!" };
    int i;

    for (i = 0; i < 4; i++) {
        printf("\r%-20s", beats[i]);
        fflush(stdout);
        sleepMs(500);
    }
    printf("\n");
}

void playShakeAnimation(Choice playerChoice, Choice computerChoice) {
    int cycles = 6; /* how many times the icons flicker before settling */
    int i;

    printf("\n");
    for (i = 0; i < cycles; i++) {
        int frame = i % 3;
        printf("\rYou: %-16s   Computer: %-16s",
               shakeFrames[frame], shakeFrames[(frame + 1) % 3]);
        fflush(stdout);
        sleepMs(150);
    }

    /* Final settle: show what was actually chosen */
    printf("\rYou: %-16s   Computer: %-16s\n",
           choiceToString(playerChoice), choiceToString(computerChoice));
    sleepMs(300);
}