#include "mastermind.h"

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