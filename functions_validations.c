#include "mastermind.h"

void check_arguments(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("Generate random secret code %s\n", argv[0]);
    }

    if (argc > 1)
    {
        check_c_flag(argc, argv);
    }
}

void check_c_flag(int argc, char* argv[])
{
    int i;
    
    for (i = 0; i < argc; i++)
    {
        char first_char = argv[i][0];
        char second_char = argv[i][1];
        
        if (first_char == '-' && second_char == 'c')
        {
            printf("I am a C FLAG!");  
        }
    }
}