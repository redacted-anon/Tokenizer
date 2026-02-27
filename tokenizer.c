#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


void clear_screen(void)
{
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif    
}


void tokenize_input(char user_input[100])
{
    int index = 0;
    char *token = strtok(user_input, " ,");
    
    while (token != NULL)
    {   
        printf("\tIndex: %d \t|\t Value: %s\n", index, token);
        index ++;
        token = strtok(NULL, " ,");
    }
}


void get_input(void)
{
    char s[100];

    while (true)
    {
        printf("\nEnter some text (type 'exit' to end the program): ");
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';

        if (strcmp(s, "exit") == 0 || strcmp(s, "e") == 0) 
        {
            clear_screen();
            exit(EXIT_SUCCESS);
        } else if (strcmp(s, "clear") == 0 || strcmp(s, "c") == 0)
        {
            clear_screen();
        } else
        {
            printf("\n");
            tokenize_input(s);
        }
    }
}


int main(void)
{
    get_input();
    printf("\n");
    return 0;
}