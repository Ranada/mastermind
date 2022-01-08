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

/* Automatically set the player's number of attempts to enter the secret code to 10 (or another number specified by the game master) */

char* get_attempts(int argc, char* argv[])
{
    int i;
    int j;
    int* continue_game = malloc(sizeof(int));
    *continue_game = TRUE;

    for (i = 0; i < argc; i ++)
    {
        int len =  strlen(argv[i]);

        for (j = 0; j < len; j++)
        {
            char ch = argv[i][j];
            char next_ch = argv[i][j + 1];
            char* attempts = argv[i + 1];

            if (ch == DASH && next_ch == T)
            {
                check_t_flag_argument(attempts, continue_game);

                if (*continue_game == FALSE)
                {
                    t_flag_error_message();
                    exit(0);
                }
                else
                {
                    return attempts;
                }
            }
        }
        printf("\n");
    }
    return DEFAULT_ATTEMPTS;
}

/* Get the player's guess from the command line. Show error message if entry is not four digits using numbers between 0 and 7  */

char* get_guess()
{
    int i;
    int retry = 0;
    char* guess;
    guess = malloc(sizeof(char)*100);


    printf("Enter your four digit guess (pick numbers between 0 and 7):\n");
    scanf("%s", guess);
    printf("\n");

    int length = strlen(guess);

    if (length != 4)
    {
        printf("Game master: \"Oops! You entered %i digits or characters. You need to enter 4 digits.\"\n", length);
        printf("\n");
        retry = TRUE;
    }

    for (i = 0; i < length; i++)
    {
        if (guess[i] < '0' || guess[i] > '7')
        { 
            printf("Game master: \"Uh oh! Some of the characters you entered are not numbers between 0 and 7.\"\n");
            printf("\n");
            retry = TRUE;
            break;
        }
    }

    if (retry == TRUE)
    {
        printf("Game master: \"Try again.\"\n");
        printf("\n");
        get_guess();
    }

    return guess;
}