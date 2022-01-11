#ifndef MASTERMIND_H
#define MASTERMIND_H

/* Libraries */
#include <stdio.h>

/* MACROS */
#define CODE_LENGTH 4

/* Global Variables */
char* possible_digits[8];
char* secret_code[CODE_LENGTH];
char* guess_code[CODE_LENGTH];
int* attempts;

/* Function prototypes */
void play_mastermind(int argc, char* argv[]);
void check_arguments(int argc, char* argv[]);
void check_c_flag(int argc, char* argv[]);

#endif //MASTERMIND_H