#include "mastermind.h"

/* If a secret code is not set by the game master, randomly generate a four digit code with numbers between 0 and 7 */

char* get_random_code()
{
    int i;
    char* random_code;
    int num_of_digits = 4;
    random_code = malloc(sizeof(char) * (num_of_digits + 1));

    srand(time (0));

    for (i = 0; i < num_of_digits; i++)
    {
        random_code[i] = '0' + (rand() % 8);
    }

    random_code[num_of_digits + 1] = '\0';

    return random_code;
}