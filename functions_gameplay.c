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

/* Get a secret code entered by the game master or use an automatically generated secret code */

char* get_code(int argc, char* argv[])
{
    int i;
    int j;
    int* continue_game = malloc(sizeof(int));
    char* random_code;

    *continue_game = TRUE;
    random_code = get_random_code();
    
    for (i = 0; i < argc; i ++)
    {
        int len =  strlen(argv[i]);

        for (j = 0; j < len; j++)
        {
            char ch = argv[i][j];
            char next_ch = argv[i][j + 1];
            char* code = argv[i + 1];

            if (ch == DASH && next_ch == C)
            {
                check_c_flag_argument(code, continue_game);

                if (*continue_game == FALSE)
                {
                    c_flag_error_message();
                    exit(0);
                }
                else
                {
                    return code;
                }
            }
        }
        printf("\n");
    }
    return random_code;
}