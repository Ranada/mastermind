#include "mastermind.h"

void play_mastermind(int argc, char* argv[])
{   
    check_arguments(argc, argv);

    if (argc == 1)
    {
        generate_random_code();
    }

    // Check command line for arguments
        // If no arguments
            // Generate 4 digit secret code using non-repeating numbers from 0 to 7 (ex. 1357)
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

void generate_random_code()
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

    secret_code = random_code;
    printf("RANDOM SECRET CODE: %s\n", secret_code);
}