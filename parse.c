#include "shell.h"
/**
 * parse_input - Tokenises the input line
 * @input: The input line
 * Return: Array of tokens
 */
char **parse_input(char *input)
{
    char **tokens = NULL;
    size_t bufsize = BUFFER_SIZE;

    input[strcspn(input, "\n")] = '\0';/* Remove character */
    tokens = inis_toks_arr(input, tokens, &bufsize);
    if (!tokens[0])
        return (tokens);
    tokens = fill_toks_arr(tokens, &bufsize);
    return (tokens);
}
/**
 * init_toks_arr - Initialises the tokens array
 * @input: The input string
 * @tokens: The tokens array
 * @bufsize: Pointer to the buffer size
 * Return: Initialised tokens array
 */
char **inis_toks_arr(char *input, char **tokens, size_t *bufsize)
{
    char *token;

    token = strtok(input, " \t\n\"");/* Get the initial token from the input */
    if (token == NULL) /* If no tokens, allocate space for NULL */
    {
        tokens = malloc(sizeof(char *));
        if (!tokens)
        {
            fprintf(stderr, "shell: allocation error\n");
            exit(EXIT_FAILURE);
        }
        tokens[0] = NULL;
        return (tokens);
    }
    /* Allocate space based on buffer size */
    tokens = malloc(*bufsize * sizeof(char *));
    if (!tokens)
    {
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }
    return (tokens);
}
/**
 * fill_tokens_array - Fills up the tokens array
 * @tokens: The tokens array
 * @bufsize: Pointer to the buffer size
 * Return: Filled tokens array
 */
char **fill_toks_arr(char **tokens, size_t *bufsize)
{
    char *token;
    size_t position = 0;

    do
    {
        /* Duplicate the token into the array */
        tokens[position] = strdup(token);
        position++;

        /* Reallocate if buffer size is exceeded */
        if (position >= *bufsize)
        {
            *bufsize += BUFFER_SIZE;
            tokens = realloc(tokens, *bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " \t\n\"");/* Get the next token */
    } 
    while (token != NULL);
    tokens[position] = NULL;

    return (tokens);
}
