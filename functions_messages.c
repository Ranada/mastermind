#include "mastermind.h"

/* Show error message if characters other than 0 through 7 are entered after the command line -c flag */

void c_flag_error_message()
{
    printf("Game master:\n");
    printf("\"Oops! You need to fix your command line entry.\n");
    printf("The numbers you enter for your secret code after the '-c' flag\n");
    printf("must be four digits long using numbers between 0 and 7.\n");
    printf("with no repeating digits (ex: -c 1234)\"\n\n");
}

/* Show error message if non-numbers are entered after the command line -t flag */

void t_flag_error_message()
{
    printf("Game master:\n");
    printf("\"Oops! You need to fix your command line entry.\n");
    printf("\"The characters you entered after the '-t' flag should only contain numbers. (ex: -t 10)\"\n");
}

/* Start game with introduction message */

void intro_message(int* num_attempts)
{
    printf("******************************************************************************\n\n");
    printf("                              My Mastermind Game                              \n\n");
    printf("Let's play a game! I'm thinking of a four digit secret code.\n\n");
    printf("- Each spot in the code is a distinct number between 0 through 7. (Example: 1367)\n");
    printf("- Digits in the secret code will not be repeated. (Example: 1133)\n");
    printf("- Can you guess the digits in the exact order?\n\n");
    printf("I'll give you %i attempts.\n\n", *num_attempts);
}

/* Show the player the number of attempts left each round */

void attempts_message(attempts)
{
    printf("-------------------------------------------------------------------------------\n\n");
    printf("Number of attempts left: %i\n", attempts);
}

/* Show congratulations message if player correctly guesses secret code */

void win_message(char* secret_code)
{
    printf("\n**********************************************************************************\n\n");
    printf("                                    CONGRATS!                                    \n\n");
    printf("                  You correctly guessed the secret code: %s\n\n", secret_code);
    printf("**********************************************************************************\n");
}

/* Show a message ending the game if the player has zero attempts left and is unable to guess the secret code */

void game_over_message(char* secret_code)
{
    printf("\n*******************************************************************************\n\n");
    printf("                                     GAME OVER                                    \n\n");
    printf("                       Nice try, the secret code was: %s\n\n", secret_code);
    printf("                              Good luck next time!\n\n");
    printf("*******************************************************************************\n");
}