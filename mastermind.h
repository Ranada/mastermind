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
#define YES 1
#define NO 0

/* Global Variables */
char* secret_code;
char* guess_code;
int* attempts;
char* continue_game;

/* Function prototypes */
int play_mastermind(int argc, char* argv[]);
char* generate_random_code();
void check_arguments(int argc, char* argv[], int* continue_game);
void check_c_flag(int argc, char* argv[], int* continue_game);
void check_c_argument(char* argv[], int i, int* continue_game);
void check_proper_digits(char* string_input, int length, int* continue_game);
void check_non_repeating(char* string_input, int* continue_game);
void c_flag_error_message();
void check_t_flag(int argc, char* argv[]);
void check_t_argument(char* argv[], int i);
void check_if_integer(char* user_set_attempts, int length);
void t_flag_error_message();
void set_attempts(int user_set_attempts);
void intro_message(int* attempts);
void get_guess_code(char* guess);
void game_over_message();

#endif //MASTERMIND_H