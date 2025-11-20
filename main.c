#include <stdio.h>

#define STRING_SIZE 100
#define ASCII_ART_LINES 6
#define ASCII_ART_CHARACTERS 50
#define NUMBER_OF_MENU_ITEMS 10
#define SIZE_OF_MENU_ITEMS 50
#define UPPERCASE_CHAR_MAX 90
#define UPPERCASE_CHAR_MIN 65
#define LOWERCASE_CHAR_MAX 122
#define LOWERCASE_CHAR_MIN 97
#define DISTANCE_FROM_UPPER_TO_LOWER_CHAR 32

// Functions for operation of operation of program
void display_ascii_art(void);
void display_menu(void);
char ask_command(void);
int check_user_command(char command_given);
int function_router(char command, char program_string[]);

// Functions for user commands
void read_string(char s[]);
void print_string(char s[]);
int count_vowels(char s[]);
int count_consonants(char s[]);
void to_lower(char s[]);
void to_upper(char s[]);
void read_file(char s[]);
void write_file(char s[]);

int main(void)
{
    char program_string[STRING_SIZE] = "Hello World";
    char command = ' ';

    display_menu();

    while (command != 'X')
    {
        command = ask_command();
        function_router(command, program_string);
    }

    return 0;
}

void display_ascii_art(void)
{
    char ascii_art[ASCII_ART_LINES][ASCII_ART_CHARACTERS] = {
        "          __         .__\n",
        "  _______/  |________|__| ____    ____\n",
        " /  ___/\\   __\\_  __ \\  |/    \\  / ___\\\n",
        " \\___ \\  |  |  |  | \\/  |   |  \\/ /_/  >\n",
        "/____  > |__|  |__|  |__|___|  /\\___  /\n",
        "     \\/                      \\//_____/\n"};

    for (size_t i = 0; i < ASCII_ART_LINES; i++)
    {
        printf("%s", ascii_art[i]);
    }

    printf("\n");
}

void display_menu(void)
{
    char menu_items[NUMBER_OF_MENU_ITEMS][SIZE_OF_MENU_ITEMS] = {
        "A) Count the number of vowels in the string\n",
        "B) Count the number of consonants in the string\n",
        "C) Convert the string to uppercase\n",
        "D) Convert the string to lowercase\n",
        "E) Display the current string\n",
        "F) Enter another string\n",
        "G) Read string from file\n",
        "H) Write string to file\n",
        "M) Display this menu\n",
        "X) Exit the program\n"};

    display_ascii_art();

    for (int i = 0; i < NUMBER_OF_MENU_ITEMS; i++)
    {
        printf("%s", menu_items[i]);
    }

    printf("\n");
}

char ask_command(void)
{
    char command_text[] = "Give Command: ";
    char buffer[20];
    char user_input;

    int correct_input = 0;

    while (!correct_input)
    {
        printf("%s", command_text);

        fgets(buffer, sizeof(buffer), stdin);

        user_input = buffer[0];

        if (user_input >= LOWERCASE_CHAR_MIN && user_input <= LOWERCASE_CHAR_MAX)
        {
            user_input -= DISTANCE_FROM_UPPER_TO_LOWER_CHAR;
        }

        correct_input = check_user_command(user_input);

        if (!correct_input)
        {
            printf("\n");
        }
    }

    return user_input;
}

int check_user_command(char command_given)
{
    switch (command_given)
    {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'M':
    case 'X':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int function_router(char command, char program_string[])
{
    switch (command)
    {
    case 'A':
        return count_vowels(program_string);
        break;
    case 'B':
        return count_consonants(program_string);
        break;
    case 'C':
        to_upper(program_string);
        break;
    case 'D':
        to_lower(program_string);
        break;
    case 'E':
        print_string(program_string);
        break;
    case 'F':
        read_string(program_string);
        break;
    case 'G':
        read_file(program_string);
        break;
    case 'H':
        write_file(program_string);
        break;
    case 'M':
        display_menu();
        break;
    }

    return 0;
}

int count_vowels(char s[])
{
    printf("A\n");
    return 1;
}

int count_consonants(char s[])
{
    printf("B\n");
    return 1;
}

void to_upper(char s[])
{
    printf("C\n");
}

void to_lower(char s[])
{
    printf("D\n");
}

void print_string(char s[])
{
    printf("E\n");
}

void read_string(char s[])
{
    printf("F\n");
}

void read_file(char s[])
{
    printf("G\n");
}

void write_file(char s[])
{
    printf("H\n");
}