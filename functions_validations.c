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
            check_c_argument(argv, i);
            break;
        }
    }
}

void check_c_argument(char* argv[], int i)
{
    char* c_flag_arg = argv[i + 1];
    int c_flag_arg_length = strlen(c_flag_arg);

    printf("C FLAG ARGUMENT: %s\n", c_flag_arg);
    
    check_proper_digits(c_flag_arg, c_flag_arg_length);
}

void check_proper_digits(char* string, int length)
{
    int i;

    if (length == CODE_LENGTH)
    {
        for (i = 0; i < length; i++)
        {
            char ch = string[i];
            
            if (ch < '0' || ch > '7')
            {
                continue_game(FALSE);
                break;
            }
            else
            {
                check_non_repeating(string);
                break;
            }
        }
    }
    else
    {
        c_flag_error_message();
        continue_game(FALSE);
    }
}

void check_non_repeating(char* string)
{
    int i;
    int j;
    int continue_status;

    for (i = 0; i < CODE_LENGTH; i++)
    {
        for (j = 0; j < CODE_LENGTH; j++)
        {
            char ch_one = string[i];
            char ch_two = string[j];

            if (i != j && ch_one == ch_two)
            {
                c_flag_error_message();
                continue_status = FALSE;
                continue_game(FALSE);
                break;
            }
        }
        if (continue_status == FALSE)
        {
            break;
        }
    }
}

void end_game()
{
    printf("END GAME FUNCTION\n");
    exit(0);
}

int continue_game(int result)
{
    int continue_game = result;

    if (continue_game == FALSE)
    {
        printf("PROGRAM ENDS\n");
        return 0;
    }

    return continue_game;
}