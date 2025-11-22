#ifndef PROGRAM_OPERATION
#define PROGRAM_OPERATION

#define ASCII_ART_LINES 6
#define ASCII_ART_CHARACTERS 50
#define NUMBER_OF_MENU_ITEMS 10
#define SIZE_OF_MENU_ITEMS 50

void display_ascii_art(void);
void display_menu(void);
char ask_command(void);
int check_user_command(char command_given);
int function_router(char command, char program_string[]);

#endif
