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

void ask_for_guess(char* guess)
{
    printf("Enter your four digit guess (pick numbers between 0 and 7):\n");
    scanf("%s", guess);
    printf("\n");
}

/* Show the player error message if they do not enter proper number of digits*/
void length_error_message(int length)
{
    printf("Game master: \n\"Oops! You entered %i digits or characters. You need to enter 4 digits.\"\n", length);
}

/* Show the player error message if they do not enter digits within the allowable range*/
void digit_error_message()
{
    printf("Game master: \n\"Oops! You need to enter non-repeated digits between 0 and 7.\"\n");
}

/* Ask player to try again if they make an incorrect entry*/
void try_again_message()
{
    printf("\"Try again!\" \n\n");
}

/* Show player wellplaced and misplaced number of guesses */
void placement_result_message(int well_placed_count, int misplaced_count)
{
    printf("Well placed guesses: %i\n", well_placed_count);
    printf("Close but misplaced guesses: %i\n", misplaced_count);
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