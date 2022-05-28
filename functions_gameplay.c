#include "mastermind.h"

int play_mastermind(int argc, char* argv[])
{
    char* guess;
    int* continue_game;

    guess = malloc(sizeof(char) * 5);
    continue_game = malloc(sizeof(int) * 1);

    attempts = set_attempts();
    secret_code = generate_random_code();
    *continue_game = YES;

    check_arguments(argc, argv, continue_game);

    if (*continue_game == YES)
    {
        intro_message(attempts);
        play_round(attempts, secret_code, guess, continue_game);
    }

    free(guess);
    free(continue_game);
    free(attempts);

    guess = NULL;
    continue_game = NULL;
    attempts = NULL;

    return 0;
}

char* generate_random_code()
{
    int i;
    int k;
    int n;
    char* random_code;

    random_code = malloc(sizeof(char) * (CODE_LENGTH + 1));

    srand(time (0));

    for (i = 0; i < CODE_LENGTH; i++)
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

    random_code[CODE_LENGTH + 1] = '\0';

    return random_code;
}

int* set_attempts()
{
    attempts = malloc(sizeof(int) * 100);
    *attempts = 10;

    return attempts;
}

int* play_round(int* attempts, char* secret_code, char* guess, int* continue_game)
{
    *continue_game = YES;

    while (*attempts > 0)
    {
        get_guess_code(attempts, guess);
        check_guess(guess, continue_game);

        if (*continue_game == NO)
        {
            play_round(attempts, secret_code, guess, continue_game);
        }
        else
        {
            compare_code(attempts, secret_code, guess);
        }
    }

    return 0;
}

void get_guess_code(int* attempts, char* guess)
{
    printf("Attempts left: %i\n", *attempts);
    printf("Enter your four digit guess (pick non-repeating numbers between 0 and 7):\n");
    scanf("%s", guess);
}

void compare_code(int* attempts, char* secret_code, char* guess)
{
    if (strcmp(secret_code, guess) == 0)
    {
        congrats_message(secret_code);
        *attempts = 0;
    }
    else
    {
        get_success_rate(secret_code, guess);
        (*attempts)--;

        if (*attempts == 0)
        {
            game_over_message();
        }
    }
}

void get_success_rate(char* secret_code, char* guess)
{
    int well_placed_count = 0;
    int misplaced_count = 0;
    int j;
    int k;

    for (j = 0; j < CODE_LENGTH; j ++)
    {
        for (k = 0; k < CODE_LENGTH; k++)
        {
            if (guess[j] == secret_code[k] && j == k)
            {
                well_placed_count++;
            }
            if (guess[j] == secret_code[k] && j != k)
            {
                misplaced_count++;
            }
        }
    }

    success_rate_message(well_placed_count, misplaced_count);
}
