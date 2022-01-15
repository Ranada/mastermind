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
char* guess;
int* attempts;
int* continue_game;

/* Function prototypes */
int play_mastermind(int argc, char* argv[]);
char* generate_random_code();
void check_arguments(int argc, char* argv[], int* continue_game);
void check_c_flag(int argc, char* argv[], int* continue_game);
void check_c_argument(char* argv[], int i, int* continue_game);
void check_proper_digits(char* string_input, int length, int* continue_game);
void check_non_repeating(char* string_input, int* continue_game);
void c_flag_error_message();
void check_t_flag(int argc, char* argv[], int* continue_game);
void check_t_argument(char* argv[], int i, int* continue_game);
void check_if_integer(char* user_set_attempts, int length, int* continue_game);
void t_flag_error_message();
int* set_attempts();
void intro_message(int* attempts);
int* play_round(int* attempts, char* secret_code, char* guess, int* continue_game);
void get_guess_code(int* attempts, char* guess);
void check_guess(char* guess, int* continue_game);
void guess_error_message();
void compare_code(int* attempts, char* secret_code, char* guess);
void get_success_rate(char* secret_code, char* guess);
void success_rate_message(int well_placed_count, int misplaced_count);
void congrats_message(char* secret_code);
void game_over_message();

#endif //MASTERMIND_H