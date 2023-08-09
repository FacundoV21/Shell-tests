#include "shell.h"
/**
 * main - The main loop of the shell
 * Return: Always 0 (success)
 */
int main(void)
{
    char *input_line = NULL;
    size_t len = 0;
    ssize_t read;
	char **tokens;
	int i;

    while (1)
    {
        printf("#cisfun$ ");  /* Display prompt */
        read = getline(&input_line, &len, stdin);  /* Read user input */
        /* Check for EOF (ctrl+d) */
        if (read == -1)
        {
            free(input_line);
			printf("\n");
            exit(EXIT_SUCCESS);
        }
		/* Parse the input line into tokens */
        tokens = parse_input(input_line);
		/* Execute the command */
        execute_command(tokens);
        /* Free tokens */
        for (i = 0; tokens[i]; i++)
            free(tokens[i]);
        free(tokens);
    }
    free(input_line);
    return (EXIT_SUCCESS);
}