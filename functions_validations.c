#include "mastermind.h"

void check_arguments(int argc, char* argv[], int* continue_game)
{
    if (argc > 1)
    {
        check_c_flag(argc, argv, continue_game);
        check_t_flag(argc, argv);
    }
}

/* Check "-c" flag argument */
void check_c_flag(int argc, char* argv[], int* continue_game)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        char first_char = argv[i][0];
        char second_char = argv[i][1];
        
        if (first_char == '-' && second_char == 'c')
        {
            check_c_argument(argv, i, continue_game);
            break;
        }
    }
}

void check_c_argument(char* argv[], int i, int* continue_game)
{
    char* c_flag_arg = argv[i + 1];
    int c_flag_arg_length = strlen(c_flag_arg);

    printf("C FLAG ARGUMENT: %s\n", c_flag_arg);
    
    check_proper_digits(c_flag_arg, c_flag_arg_length, continue_game);
}

void check_proper_digits(char* string_input, int length, int* continue_game)
{
    int i;

    if (length != CODE_LENGTH)
    {
        *continue_game = NO;
        return;
    }
    else if (length == CODE_LENGTH)
    {
        for (i = 0; i < length; i++)
        {
            char ch = string_input[i];
            
            if (ch < '0' || ch > '7')
            {
                ;
                *continue_game = NO;
                return;
            }
        }
    }

    check_non_repeating(string_input, continue_game);
}

void check_non_repeating(char* string_input, int* continue_game)
{
    int i;
    int j;

    for (i = 0; i < CODE_LENGTH; i++)
    {
        for (j = 0; j < CODE_LENGTH; j++)
        {
            char ch_one = string_input[i];
            char ch_two = string_input[j];

            if (i != j && ch_one == ch_two)
            {
                *continue_game = NO;
                return;
            }
        }
    }
}

/* check "-t" flag argument */
void check_t_flag(int argc, char* argv[])
{
    int i;

    for (i = 0; i < argc; i++)
    {
        char first_char = argv[i][0];
        char second_char = argv[i][1];
        
        if (first_char == '-' && second_char == 't')
        {
            check_t_argument(argv, i);
            break;
        }
    }
}

void check_t_argument(char* argv[], int i)
{
    char* t_flag_arg = argv[i + 1];
    int t_flag_arg_length = strlen(t_flag_arg);

    printf("T FLAG ARGUMENT: %s\n", t_flag_arg);
    
    check_if_integer(t_flag_arg, t_flag_arg_length);
}

void check_if_integer(char* user_set_attempts, int length)
{
    int i;

        for (i = 0; i < length; i++)
        {
            char ch = user_set_attempts[i];
            
            if (ch < '0' || ch > '9')
            {
                t_flag_error_message();
                *continue_game = NO;
                break;
            }
        }

    set_attempts(atoi(user_set_attempts));
}