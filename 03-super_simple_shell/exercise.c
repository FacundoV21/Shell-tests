#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char *buffer;
    size_t bufsize = BUFFER_SIZE;
    size_t characters;
    pid_t child_pid;
    int status;
    char *argv[2];

    buffer = (char *)malloc(bufsize * sizeof(char));

    if (buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    while (1)
    {
        printf("#cisfun$ ");
        characters = getline(&buffer, &bufsize, stdin);

        // Remove newline character from the buffer
        buffer[characters - 1] = '\0';

        if (strcmp(buffer, "exit") == 0)
        {
            free(buffer);
            exit(0);
        }

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }

        // Child process
        if (child_pid == 0)
        {
            argv[0] = buffer;
            argv[1] = NULL;
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("Error:");
                free(buffer);
                exit(1);  // End child process if command fails
            }
        }
        else
        {
            wait(&status);  // Parent process waits for child to finish
        }
    }

    free(buffer); // To free the allocated buffer. This line will not execute in the current loop structure, but it's a good practice to free your malloc'ed memory.
    return (0);
}