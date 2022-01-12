#include "mastermind.h"

void game_over_message()
{
    printf("Game Over.\n");
}

void c_flag_error_message()
{
    printf("Oops! Your command line entry after the '-c' flag must be four non-repeating digits between 0 and 7 (ex: 1357).\n\n");
}

void t_flag_error_message()
{
    printf("Oops! Your command line entry after the '-t' flag must an integer greater than 0.\n\n");
}