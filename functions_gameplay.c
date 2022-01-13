#include "mastermind.h"

void play_mastermind(int argc, char* argv[])
{   
    int* attempts;
    attempts = malloc(sizeof(int));
    
    *attempts = 10;
    secret_code = generate_random_code();

    check_arguments(argc, argv);

    printf("SECRET CODE IS: %s\n", secret_code);
    printf("DEFAULT ATTEMPTS IS: %d\n", *attempts);

    // Check command line for arguments
        // If no arguments
            // Number of attempts is 10
    
    // Introduction message
        // Game instructions
        // Number of attempts

    // Round #
        // Ask to enter a four digit case using non-repeating digits between 0 and 7 (ex: 1357)
        // If well place piece (digit in the correct index place)
            // Add to well place piece count
        // If digit is part of the secret code but in the wrong index
            // Add to misplaced piece count
        // Print number of well placed pieces and miss placed pieces
    
    // If guess is correct
        // Show a congrats message and end program
    
    // If guess is not correct and not exceeded max number of attempts
        // Ask for another guess        
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

    printf("RANDOM SECRET CODE: %s\n", secret_code);

    return random_code;
}

void set_attempts(int user_set_attempts)
{
    attempts = malloc(sizeof(int));
    *attempts = 10;

    *attempts = user_set_attempts;

    printf("SET ATTEMPTS TO: %d\n", *attempts);
}