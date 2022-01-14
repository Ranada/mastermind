#include "mastermind.h"

int play_mastermind(int argc, char* argv[])
{   
    int* attempts;
    char* guess;
    int* continue_game;

    attempts = malloc(sizeof(int) * 1);
    guess = malloc(sizeof(char) * 5);
    continue_game = malloc(sizeof(int) * 1);
    
    *attempts = 10;
    secret_code = generate_random_code();
    *continue_game = YES;

    check_arguments(argc, argv, continue_game);

    if (* continue_game == NO)
    {
        c_flag_error_message();
        return 0;
    }

    intro_message(attempts);
    get_guess_code(attempts, guess);
    compare_code(attempts, secret_code, guess);

    
    

    // Round #
        // If well place piece (digit in the correct index place)
            // Add to well place piece count
        // If digit is part of the secret code but in the wrong index
            // Add to misplaced piece count
        // Print number of well placed pieces and miss placed pieces
    
    // If guess is correct
        // Show a congrats message and end program
    
    // If guess is not correct and not exceeded max number of attempts
        // Ask for another guess   
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

    printf("RANDOM SECRET CODE: %s\n", random_code);

    return random_code;
}

void set_attempts(int user_set_attempts)
{
    attempts = malloc(sizeof(int));
    *attempts = 10;

    *attempts = user_set_attempts;

    printf("SET ATTEMPTS TO: %d\n", *attempts);
}

void get_guess_code(int* attempts, char* guess)
{
    printf("Attempts left: %i\n\n", *attempts);
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
}