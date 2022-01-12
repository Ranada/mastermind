#ifndef MASTERMIND_H
#define MASTERMIND_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* MACROS */
#define CODE_LENGTH 4
#define TRUE 1
#define FALSE 0

/* Global Variables */
char* secret_code;
char* guess_code;

/* Function prototypes */
void play_mastermind(int argc, char* argv[]);
void check_arguments(int argc, char* argv[]);
void check_c_flag(int argc, char* argv[]);
void check_c_argument(char* argv[], int i);
void check_proper_digits(char* user_set_code, int length);
void check_non_repeating(char* user_set_code);
void c_flag_error_message();
void check_t_flag(int argc, char* argv[]);
void check_t_argument(char* argv[], int i);
void check_if_integer(char* user_set_attempts, int length);
void t_flag_error_message();
void generate_random_code();
int continue_game(int result);
void game_over_message();

#endif //MASTERMIND_H