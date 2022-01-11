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
            printf("I am a C FLAG!\n");
            check_c_argument(argv, i);  
        }
    }
}

void check_c_argument(char* argv[], int i)
{
    char* c_flag_arg = argv[i + 1];
    int c_flag_arg_length = strlen(c_flag_arg);
    int j;

    printf("C FLAG ARGUMENT: %s\n", c_flag_arg);
    
    if (c_flag_arg_length == CODE_LENGTH)
    {
        for (j = 0; j < c_flag_arg_length; j++)
        {
            char ch = c_flag_arg[j];
            
            if (ch > '0' && ch < '7')
            {
                check_non_repeating(c_flag_arg);

                if (continue_game)
                {
                    secret_code = c_flag_arg;
                    printf("I'M THE NEW SECRET CODE!: %s\n", secret_code);
                }
            }
        }
    }
}

void check_non_repeating(char* string)
{
    int i;
    int j;

    for (i = 0; i < CODE_LENGTH; i++)
    {
        for (j = 0; j < CODE_LENGTH; j++)
        {
            char ch_one = string[i];
            char ch_two = string[j];
            // printf("i %i %c\n", i, string[i]);
            // printf("j %i %c\n\n", j, string[j]);

            if (i != j && ch_one == ch_two)
            {
                printf("I REPEAT!\n");
                game_over_message();
                end_game();
                break;
            }
        }
    }
}

void end_game()
{
    printf("END GAME FUNCTION\n");
    exit(0);
}