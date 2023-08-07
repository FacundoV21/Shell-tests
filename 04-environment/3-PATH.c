#include <stdio.h>
#include <string.h>

extern char **environ;

void print_PATH_dirs(void)
{
    char *path = _getenv("PATH");
    char *token = strtok(path, ":");
    while (token)
    {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}