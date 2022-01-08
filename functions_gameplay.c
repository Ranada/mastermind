#include "mastermind.h"

/* If a secret code is not set by the game master, randomly generate a four digit code with numbers between 0 and 7 */

char* get_random_code()
{
    int i;
    int k;
    int n;
    random_code = malloc(sizeof(char) * (DEFAULT_CODE_LENGTH + 1));

    srand(time (0));

    for (i = 0; i < DEFAULT_CODE_LENGTH; i++)
    {
        n = '0' + (rand() % 8);
        random_code[i] = n;

        for (k = 0; k < i; k++)
        {
            if (random_code[i] == random_code[k])
            {
                i--;
            }
        }
    }

    random_code[DEFAULT_CODE_LENGTH + 1] = '\0';

    printf("RANDOM CODE: %s", random_code);
    return random_code;
}

/* Get a secret code entered by the game master or use an automatically generated secret code */

char* get_code(int argc, char* argv[])
{
    int i;
    int j;
    int* continue_game = malloc(sizeof(int));

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
    char* guess;
    guess = malloc(sizeof(char)*100);

    ask_for_guess(guess);

    length = strlen(guess);

    validate_guess(guess, length);

    return guess;
    free(guess);
}

/* Compare the player's four digit guess with the four digit code set by the game master */

int compare_code(int* num_attempts, char* secret_code, int length, char* your_guess)
{
    int i;
    int j;
    int well_placed_count = 0;
    int misplaced_count = 0;

    for (i = 0; i < length; i ++)
    {   
        for (j = 0; j < length; j++)
        {
            if (your_guess[i] == secret_code[j] && i == j)
            {
                well_placed_count++;
            }
            if (your_guess[i] == secret_code[j] && i != j)
            {
                misplaced_count++;
            }
        }
    }

    placement_result_message(well_placed_count, misplaced_count);

    if (well_placed_count == 4)
    {
        win_message(secret_code);
        *num_attempts = 0;
        return *num_attempts;
    }
    printf("\n");

    return *num_attempts;
}

/* Function used to start each round of game play */

void play_round(int* num_attempts, char* secret_code, int length, char* your_guess)
{
    int i;

    for (i = *num_attempts; i >= 0; i--)
    {    
        attempts_message(i);

        if (i > 0)
        {
            your_guess = get_guess();
            *num_attempts = compare_code(num_attempts, secret_code, length, your_guess);

            if (*num_attempts == 0)
            {
                break;
            }
        }
        if (i == 0)
        {
            game_over_message(secret_code);
        }
    }
}

void start_mastermind(int argc, char* argv[])
{
    txt_attempts = get_attempts(argc, argv);
    num_attempts = malloc(sizeof(int));
    *num_attempts = atoi(txt_attempts);
    secret_code = get_code(argc, argv);
    length = strlen(secret_code);
    your_guess = "";
    
    intro_message(num_attempts);
    play_round(num_attempts, secret_code, length, your_guess);
}