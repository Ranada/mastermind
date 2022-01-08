#ifndef MASTERMIND_H
#define MASTERMIND_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* MACROS */
#define DASH 45
#define T 116
#define C 99
#define DEFAULT_ATTEMPTS "10"
#define TRUE 1
#define FALSE 0

/* Global Variables */
char* txt_attempts;
char* secret_code;
char* your_guess;
int* num_attempts;
char* random_code;
int length;

/* Function prototypes */
int* check_c_flag_argument(char* code, int* continue_game);
int* check_t_flag_argument(char* attempts, int* continue_game);
char* get_random_code(void);
char* get_code(int argc, char* argv[]);
char* get_attempts(int argc, char* argv[]);
char* get_guess(void);
int validate_guess(char* guess, int length);
int compare_code(int* num_attempts, char* secret_code, int length, char* your_guess);
void play_round(int* num_attempts, char* secret_code, int length, char* your_guess);
void intro_message(int* num_attempts);
void ask_for_guess(char* guess);
void c_flag_error_message(void);
void t_flag_error_message(void);
void length_error_message(int length);
void digit_error_message(void);
void try_again_message(void);
void placement_result_message(int well_placed_count, int misplaced_count);
void win_message(char* secret_code);
void game_over_message(char* secret_code);
void attempts_message(int attempts);
void start_mastermind(int argc, char* argv[]);

#endif //MASTERMIND_H