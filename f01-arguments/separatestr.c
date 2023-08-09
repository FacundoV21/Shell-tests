#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
* main - Get a  line from the user and print it. 
* Return: 0
*/

char *getin(void)
{
    char *save = NULL;
    size_t len = 0;

    printf("$ ");
    if ((getline(&save, &len, stdin)) != -1)
    {
		return (save);
    }
    else 
    {
        printf("\n");
        return (NULL);
    }
}

char **separate(void)
{
    char *in = NULL, *in_cpy = NULL, *token = NULL, **arr;
    int i = 0, j;

    if ((in = getin()) != NULL)
    {
        in_cpy = malloc(sizeof(char) * strlen(in));
        strcpy(in_cpy, in);

        token = strtok(in, " \n");

        while (token != NULL)
        {
            i++;
            token = strtok(NULL, " \n");
        }
        i++;

        arr = malloc(sizeof(char*) * i);

        token = strtok(in_cpy, " \n");

        for (j = 0; token != NULL ; j++)
        {
            arr[j] = malloc(sizeof(char) * strlen(token));
            strcpy(arr[j], token);
            token = strtok(NULL, " \n");
        }
        arr[j] = NULL;
        return (arr);
    }
    return (NULL);
}

int main(void)
{
    char **arr;
    int i = 0;

    arr = separate();

    while (arr[i] != NULL)
    {
        printf("%s\n", arr[i]);
        i++;
    }
}