#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DASH 45
#define T 116
#define C 99
#define DEFAULT_ATTEMPTS "10"
#define MIN 0
#define MAX 9999

int i;
int j;
int k;
int n;

int end_game()
{
    return 0;
}


void intro_message(int* num_attempts)
{
    printf("---------------------------------------------------------\n");
    printf("                   My Mastermind Game                    \n");
    printf("---------------------------------------------------------\n");
    printf("\n");
    
    printf("Let's play a game! I'm thinking of a four digit code.\n");
    printf("Can you guess the digits in the exact order?\n");
    printf("I'll give you %i attempts\n", *num_attempts);
    printf("\n");
}

void c_flag_error_message()
{
    printf("Oops! You need to fix your command line entry.\n");
    printf("The numbers you enter for your secret code after the '-c' flag\n");
    printf("must be four digits long using numbers between 0 and 7.\n");
    printf("(ex: -c 1234)\n");
    printf("\n");
}

char* get_code(int argc, char* argv[])
{
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
                if (strlen(code) != 4)
                {
                    c_flag_error_message();
                    exit(0);
                }

                for (k = 0; k < (int)strlen(code); k++)
                {
                    if (code[k] <= 48 || code[k] >= 55)
                    {
                        c_flag_error_message();
                        exit(0);
                    }
                }
                return code;
            }
        }
        printf("\n");
    }
    return 0;
}

char* get_attempts(int argc, char* argv[])
{
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
                return attempts;
            }
        }
        printf("\n");
    }
    return DEFAULT_ATTEMPTS;
}

int get_random_code()
{
    srand(time (0));
    int random_code = MIN + rand() / (RAND_MAX / (MAX - MIN + 1) + 1);

    return random_code;
}

char* get_guess()
{
    char* guess;
    guess = malloc(sizeof(char)*100);

    printf("Enter your four digit guess:\n");
    scanf("%s", guess);

    int length = strlen(guess);

    if (length != 4)
    {
        printf("\n");
        printf("Oops! You entered %i digits. You need to enter 4 digits. You wasted an attempt. Try again.\n", length);
    }
    
    printf("\n");

    return guess;
}

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

void game_over_message(char* secret_code)
{
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("                        END GAME                         \n");
    printf("---------------------------------------------------------\n");
    printf("Nice try, the secret code was: %s\n", secret_code);
    printf("Good luck next time.\n");
}

void attempts_message(i)
{
    printf("----------------------------------------------------------\n");
    printf("Number of attempts left: %i\n", i);
}

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
