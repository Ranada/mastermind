#ifndef MASTERMIND_H
#define MASTERMIND_H

/* Libraries */
#include <stdio.h>

/* MACROS */
#define CODE_LENGTH 4

/* Global Variables */
char possible_digits[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};
char* secret_code[CODE_LENGTH];
char* guess_code[CODE_LENGTH];
int* attempts;

/* Function prototypes */
void play_mastermind(int argc, char* argv[]);

#endif //MASTERMIND_H