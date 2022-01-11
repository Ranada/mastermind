#include "mastermind.h"

void play_mastermind(int argc, char* argv[])
{   
    check_arguments(argc, argv);

    // Check command line for arguments
        // If no arguments
            // Generate 4 digit secret code using non-repeating numbers from 0 to 7 (ex. 1357)
            // Number of attempts is 10
        // If "-c" flag is present
            // Check for 4 digit secret code using non-repeating numbers from 0 to 7 (ex. 1357)
                // If secret code is good
                    // Assign to Secret code variable
                // Else
                    // Show error message and ask to re-enter valid argument
        // If "-t" flag is present
            // Check argument is a number
            // If argument is a number
                // Assignt to Attempts variable
            // Else
                // Show error message and ask to re-enter valid argument
    
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