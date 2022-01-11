#include "mastermind.h"

void check_arguments(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("Generate secret code %s\n", argv[0]);
    }
}