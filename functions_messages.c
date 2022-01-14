#include "mastermind.h"

void game_over_message()
{
    printf("Game Over.\n");
}

void c_flag_error_message()
{
    printf("\nOops! Your command line entry after the '-c' flag must be four non-repeating digits between 0 and 7 (ex: 1357).\n\n");
}

void t_flag_error_message()
{
    printf("\nOops! Your command line entry after the '-t' flag must an integer greater than 0.\n\n");
}

void intro_message(int* attempts)
{
    printf("\n--------------------------------------------------------------------------------------------\n\n");
    printf("                                     MASTERMIND GAME                                          \n\n");
    printf("I have a four digit code made up of four non-repeating numbers between 0 and 7. (ex: 1357)     \n\n");
    printf("                                Can you guess what it is?                                      \n\n");
    printf("                              Number of tries available: %i                                    \n\n", *attempts);
    printf("--------------------------------------------------------------------------------------------\n\n");
}