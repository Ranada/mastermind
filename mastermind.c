// mastermind.c
// Mastermind is game for guessing a four digit secret code using non-repeating digits between 0 through 7 (ex: 1357)
// Original author: Neil Ranada

#include "mastermind.h"

int main(int argc, char* argv[])
{   
    play_mastermind(argc, argv);
    
    if (continue_game == false)
    {
        printf("Game Over.\n");
        return 0;
    }
}