// my_mastermind.c
// Command line game for guessing a secret four digit code using numbers between 0 and 7 (ex: 1234)
// Original author: Neil Ranada

#include "mastermind.h"

int i;
int j;
int k;
int l;
int n;

/* Start game with introduction message */

void intro_message(int* num_attempts)
{
    printf("---------------------------------------------------------\n");
    printf("                   My Mastermind Game                    \n");
    printf("---------------------------------------------------------\n");
    printf("\n");
    
    printf("Let's play a game! I'm thinking of a four digit code.\n");
    printf("Can you guess the digits in the exact order?\n");
    printf("I'll give you %i attempts.\n", *num_attempts);
    printf("\n");
}

/* Show error message if characters other than 0 through 7 are entered after the command line -c flag */

void c_flag_error_message()
{
    printf("Game master: \"Oops! You need to fix your command line entry.\n");
    printf("The numbers you enter for your secret code after the '-c' flag\n");
    printf("must be four digits long using numbers between 0 and 7 (ex: -c 1234).\n");
    printf("(ex: -c 1234)\"\n");
    printf("\n");
}

/* Show error message if non-numbers are entered after the command line -t flag */

void t_flag_error_message()
{
    printf("Game master: \"Oops! You need to fix your command line entry.\n");
    printf("The characters you entered after the '-t' flag should only contain numbers. (ex: -t 10)\"\n");
    printf("\n");
}

/* Check to see the -c flag argument (secret code) contains four digits using numbers between 0 and 7 */

int* check_c_flag_argument(char* code, int* continue_game)
{
    if (strlen(code) != 4)
    {
        *continue_game = FALSE;
        return continue_game;
    }

    for (k = 0; k < (int)strlen(code); k++)
    {
        if (code[k] < '0' || code[k] > '7')
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
    for (k = 0; k < (int)strlen(attempts); k++)
    {
        if (attempts[k] < '0' || attempts[k] > '9')
        {
            *continue_game = FALSE;
            return continue_game;
            break;
        }
    }
    return continue_game;
}

/* If a secret code is not set by the game master, randomly generate a four digit code with numbers between 0 and 7 */

char* get_random_code()
{
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

    for (l = 0; l < length; l++)
    {
        if (guess[l] < '0' || guess[l] > '7')
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

/* Show congratulations message if player correctly guesses secret code */

void win_message(char* secret_code)
{
    printf("\n");
    printf("********************************************\n");
    printf("                  CONGRATS!                 \n");
    printf("********************************************\n");
    printf("You correctly guessed the secret code: %s\n", secret_code);
    printf("\n");
    return;
}

/* Compare the player's four digit guess with the four digit code set by the game master */

int compare_code(int* num_attempts, char* secret_code, int length, char* your_guess)
{
    int well_placed_count = 0;
    int misplaced_count = 0;

    for (j = 0; j < length; j ++)
    {   
        for (k = 0; k < length; k++)
        {
            if (your_guess[j] == secret_code[k] && j == k)
            {
                well_placed_count++;
            }
            if (your_guess[j] == secret_code[k] && j != k)
            {
                misplaced_count++;
            }
        }
    }
    printf("Well placed guesses: %i\n", well_placed_count);
    printf("Close but misplaced guesses: %i\n", misplaced_count);

    if (well_placed_count == 4)
    {
        win_message(secret_code);
        *num_attempts = 0;
        return *num_attempts;
    }
    printf("\n");

    return *num_attempts;
}

/* Show a message ending the game if the player has zero attempts left and is unable to guess the secret code */

void game_over_message(char* secret_code)
{
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("                        END GAME                         \n");
    printf("---------------------------------------------------------\n");
    printf("Nice try, the secret code was: %s\n", secret_code);
    printf("Good luck next time.\n");
}

/* Show the player the number of attempts left each round */

void attempts_message(i)
{
    printf("----------------------------------------------------------\n");
    printf("Number of attempts left: %i\n", i);
}

/* Function used to start each round of game play */

void play_round(int* num_attempts, char* secret_code, int length, char* your_guess)
{
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

int main(int argc, char* argv[])
{
    char* txt_attempts;
    int* num_attempts;
    char* secret_code;
    int length;
    char* your_guess;
    
    txt_attempts = get_attempts(argc, argv);
    num_attempts = malloc(sizeof(int));
    *num_attempts = atoi(txt_attempts);
    secret_code = get_code(argc, argv);
    length = strlen(secret_code);
    your_guess = "";
    
    intro_message(num_attempts);
    play_round(num_attempts, secret_code, length, your_guess);
    
    return 0;
}