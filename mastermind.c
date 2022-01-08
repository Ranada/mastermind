// mastermind.c
// Command line game for guessing a secret four digit code using numbers between 0 and 7 (ex: 1234)
// Original author: Neil Ranada

#include "mastermind.h"

/* Start mastermind */
void mastermind(int* attempts, char *secret_code, char* guess_code, int length)
{    
    
    intro_message(attempts);
    play_round(attempts, secret_code, length, guess_code);
}

int main(int argc, char* argv[])
{
    *attempts = atoi(get_attempts(argc, argv));
    secret_code = get_code(argc, argv);
    length = strlen(secret_code);
    guess_code = "";
    
    mastermind(attempts, secret_code, guess_code, length);
    return 0;
}
