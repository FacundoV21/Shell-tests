#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str, const char *delim)
{
    char **tokens = NULL;
    size_t count = 0;
    char *token;

    token = strtok(str, delim);
    while (token)
    {
        tokens = realloc(tokens, sizeof(char *) * (count + 1));
        tokens[count] = token;
        count++;
        token = strtok(NULL, delim);
    }
    tokens = realloc(tokens, sizeof(char *) * (count + 1));
    tokens[count] = NULL;  // Null terminate the array

    return tokens;
}

int main(void)
{
    char str[] = "Hello this is a test";  // Sample input
    char **tokens = split_string(str, " ");

    for (size_t i = 0; tokens[i]; i++)
    {
        printf("%s\n", tokens[i]);
    }

    free(tokens);  // Free allocated memory
    return (0);
}