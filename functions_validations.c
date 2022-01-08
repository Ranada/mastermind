#include "mastermind.h"

/* Check to see the -c flag argument (secret code) contains four digits using numbers between 0 and 7 */

int* check_c_flag_argument(char* code, int* continue_game)
{
    int i;

    if (strlen(code) != 4)
    {
        *continue_game = FALSE;
        return continue_game;
    }

    for (i = 0; i < (int)strlen(code); i++)
    {
        if (code[i] < '0' || code[i] > '7')
        {
            *continue_game = FALSE;
            return continue_game;
            break;
        }
    }
    return continue_game;
}

/* Check to see the -t flag argument (number of attempts) contains only numbers */

int* check_t_flag_argument(char* attempts, int* continue_game)
{
    int i;
    for (i = 0; i < (int)strlen(attempts); i++)
    {
        if (attempts[i] < '0' || attempts[i] > '9')
        {
            *continue_game = FALSE;
            return continue_game;
            break;
        }
    }
    return continue_game;
}

/* Check if input for guess to secret code is valid */
void validate_guess(char* guess, int length)
{
    int i;
    int retry = FALSE;

    // Check to see guess is correct length
    if (length != 4)
    {
        length_error_message(length);
        retry = TRUE;
    }

    // Check to see if guess uses numbers between 0 and 7
    for (i = 0; i < length; i++)
    {
        if (guess[i] < '0' || guess[i] > '7')
        { 
            digit_error_message();
            retry = TRUE;
            break;
        }
    }

    // for (i = 0; i < HIGHEST_SECRET_DIGIT; i++)
    // {
    //     for (k = 0; k < i; k++)
    //     {
    //         if (guess[i] == guess[k])
    //         {
    //             retry = TRUE;
    //             break;
    //         }
    //     }
    // }

    // If any of the validations fail above have player retry round
    if (retry == TRUE)
    {
        try_again_message();
        ask_for_guess(guess);
    }
}
