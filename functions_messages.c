#include "mastermind.h"

void game_over_message()
{
    printf("Game Over.\n");
}

void c_flag_error_message()
{
    printf("\n* Oops! Your command line entry after the '-c' flag must be four non-repeating digits between 0 and 7 (ex: 1357).\n\n");
}

void t_flag_error_message()
{
    printf("\n* Oops! Your command line entry after the '-t' flag must an integer greater than 0.\n\n");
}

void intro_message(int* attempts)
{
    printf("\n--------------------------------------------------------------------------------------------\n\n");
    printf("                                     MASTERMIND GAME                                          \n\n");
    printf("                            I'm thinking of a four digit code.                                \n\n");
    printf("            Each spot uses a unique number between 0 and 7 and do not repeat.                  \n\n");
    printf("                       Example: 1357 (okay) while 1155 (not okay)                              \n\n");
    printf("                         Can you guess what the secret code is?                                \n\n");
    printf("                              Number of tries available: %i                                    \n\n", *attempts);
    printf("--------------------------------------------------------------------------------------------\n\n");
}

void guess_error_message()
{
    printf("\n* Oops! Your guess must be four non-repeating digits between 0 and 7 (ex: 1357). Try again!\n");
    printf("\n--------------------------------------------------------------------------------------------\n\n");
}

void success_rate_message(int well_placed_count, int misplaced_count)
{
    printf("\nWell placed guesses: %i\n", well_placed_count);
    printf("Close but misplaced guesses: %i\n", misplaced_count);
    printf("\n--------------------------------------------------------------------------------------------\n\n");
}

void congrats_message(char* secret_code)
{
    printf("\n********************************************************************************************\n\n");
    printf("                                     CONGRATULATIONS!                                          \n\n");
    printf("                          You correctly guessed the secret code:                               \n\n");
    printf("                                           %s                                                  \n\n", secret_code);
    printf("********************************************************************************************\n\n");
}