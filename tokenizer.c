#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


void tokenize_input(char user_input[100])
{
    int index = 0;
    char *token = strtok(user_input, " ");
    
    while (token != NULL)
    {   
        printf("\tIndex: %d \t|\t Value: %s\n", index, token);
        index ++;
        token = strtok(NULL, " ");
    }
}


void get_input(void)
{
    char s[100];

    printf("\nEnter some text (type 'exit' to end the program): ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    if (strcmp(s, "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    } else
    {
        printf("\n");
        tokenize_input(s);
    }
}


int main(void)
{
    get_input();
    printf("\n");
    return 0;
}