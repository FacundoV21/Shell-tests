#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
* main - Prints all the arguments passed. 
* Return: 0
*/

int main (int ac, char **av)
{
    char *print;
    int i, j;

    for (i = 0; av[i] != NULL; i++)
    {
        print = av[i];
        for (j = 0; print[j] != '\0'; j++)
        {
            printf("%c", print[j]);
        }
        printf(" ");
    }
    printf("\n");
}
