#include "shell.h"
/**
 * parse_input - Tokenises the input line
 * @input: The input line
 * Return: Array of tokens
 */
char **parse_input(char *input)
{
    char **tokens;
    size_t bufsize = BUFFER_SIZE, position = 0;
    char *token;

    tokens = malloc(bufsize * sizeof(char *));
    if (!tokens)
    {
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\n");
    while (token != NULL)
    {
        tokens[position] = strdup(token);
        position++;

        if (position >= bufsize)
        {
            bufsize += BUFFER_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\n");
    }
    tokens[position] = NULL;
    return (tokens);
}