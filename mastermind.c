#include "mastermind.h"

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