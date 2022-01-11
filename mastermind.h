#ifndef MASTERMIND_H
#define MASTERMIND_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/* MACROS */
#define CODE_LENGTH 4

/* Global Variables */
char* secret_code;
char* guess_code;
int* attempts;
bool* continue_game;

/* Function prototypes */
void play_mastermind(int argc, char* argv[]);
void check_arguments(int argc, char* argv[]);
void check_c_flag(int argc, char* argv[]);
void check_c_argument(char* argv[], int i);
void check_non_repeating(char* string);
void game_over_message();
void end_game();

#endif //MASTERMIND_H