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