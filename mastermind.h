#ifndef MASTERMIND_H
#define MASTERMIND_H

/* Libraries */
#include <stdio.h>
#include <string.h>

/* MACROS */
#define CODE_LENGTH 4

/* Global Variables */
char* secret_code;
char* guess_code;
int* attempts;

/* Function prototypes */
void play_mastermind(int argc, char* argv[]);
void check_arguments(int argc, char* argv[]);
void check_c_flag(int argc, char* argv[]);
void check_c_argument(char* argv[], int i);

#endif //MASTERMIND_H