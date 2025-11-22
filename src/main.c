#include <stdio.h>
#include "generic.h"
#include "string_functions.h"
#include "program_operation.h"

int main(void)
{
    char program_string[STRING_SIZE] = "Hello World";
    char command = ' ';

    display_ascii_art();
    display_menu();

    while (command != 'X')
    {
        command = ask_command();
        function_router(command, program_string);
    }

    return 0;
}
