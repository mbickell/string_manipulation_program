#include <stdio.h>
#include "generic.h"
#include "string_functions.h"

int count_vowels(char s[])
{
    int i = 0;
    int counter = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            counter++;
            break;
        }

        i++;
    }

    return counter;
}

int count_consonants(char s[])
{
    int i = 0;
    int letter_count = 0;
    int vowel_count = count_vowels(s);

    while (s[i] != '\0')
    {
        if (UPPERCASE_CHAR_CHECK(s[i]) || LOWERCASE_CHAR_CHECK(s[i]))
        {
            letter_count++;
        }

        i++;
    }

    return letter_count - vowel_count;
}

void to_upper(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        char current_char = s[i];

        if (LOWERCASE_CHAR_CHECK(current_char))
        {
            current_char -= DISTANCE_FROM_UPPER_TO_LOWER_CHAR;
        }

        s[i] = current_char;

        i++;
    }

    s[i] = '\0';

    printf("\n");
}

void to_lower(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        char current_char = s[i];

        if (UPPERCASE_CHAR_CHECK(current_char))
        {
            current_char += DISTANCE_FROM_UPPER_TO_LOWER_CHAR;
        }

        s[i] = current_char;

        i++;
    }

    s[i] = '\0';

    printf("\n");
}

void print_string(char s[])
{
    printf("%s\n", s);
}

void read_string(char s[])
{
    char buffer[STRING_SIZE];
    int i = 0;

    printf("\nGive string: ");
    fgets(buffer, STRING_SIZE, stdin);

    while (buffer[i] != '\0')
    {
        s[i] = buffer[i];
        i++;
    }

    s[i] = '\0';

    printf("\n");
}

void read_file(char s[])
{
    char buffer[STRING_SIZE];
    FILE *file_pointer;

    file_pointer = fopen(FILE_NAME, "r");
    int i = 0;

    if (file_pointer == NULL)
    {
        printf("File cannot be read\n\n");
    }
    else
    {
        fgets(buffer, STRING_SIZE, file_pointer);

        while (buffer[i] != '\0')
        {
            s[i] = buffer[i];
            i++;
        }

        s[i] = '\0';

        fclose(file_pointer);
        printf("%s\n", buffer);
    }
}

void write_file(char s[])
{
    FILE *file_pointer;

    file_pointer = fopen(FILE_NAME, "w");

    if (file_pointer == NULL)
    {
        printf("File cannot be read\n");
    }
    else
    {
        fputs(s, file_pointer);
        fclose(file_pointer);
    }
    printf("\n");
}