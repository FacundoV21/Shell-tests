#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
* main - Get a  line from the user and print it. 
* Return: 0
*/

int main(void)
{
    char *save = NULL;
    size_t len = 0;

    printf("$ ");
    while ((getline(&save, &len, stdin)) != -1)
    {
        
        printf("%s\n", save);
        printf("$ ");
    }
}