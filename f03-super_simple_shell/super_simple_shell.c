#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


char *getin(void)
{
    char *save = NULL;
    size_t len = 0;

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

        token = strtok(in, " \n\t");

        while (token != NULL)
        {
            i++;
            token = strtok(NULL, " \n\t");
        }
        i++;

        arr = malloc(sizeof(char*) * i);

        token = strtok(in_cpy, " \n\t");

        for (j = 0; token != NULL ; j++)
        {
            arr[j] = malloc(sizeof(char) * strlen(token));
            strcpy(arr[j], token);
            token = strtok(NULL, " \n\t");
        }
        arr[j] = NULL;
        return (arr);
    }
    return (NULL);
}

int main(void)
{
    pid_t child_pid;
    int status;
    char **arr;

    while (1)
    {
        printf("#cisfun$ ");
        arr = separate();

        if (strcmp(arr[0], "exit") == 0)
        {
            exit(0);
        }

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }

        if (child_pid == 0)
        {
            if (execve(arr[0], arr, NULL) == -1)
            {
                perror("Error:");
                exit(1);
            }
        }
        else
        {
            wait(&status);
        }
    }

    return (0);
}