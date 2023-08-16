#include "shell.h"
/**
 * direct_execute - Executes the command if it starts with '/' or '.'.
 * @tokens: The command and its arguments.
 */
void direct_execute(char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) /* Child */
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			fprintf(stderr, "%s: %s\n", tokens[0], strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* If fork() fails */
	{
		perror("./shell");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
			}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
/**
 * path_execute - Searches for the command in the PATH and executes it.
 * @tokens: The command and its arguments.
 */
void path_execute(char **tokens, char *argv[])
{
	pid_t pid;
	int status;
	path_t *path_list;
	char *full_path;

	path_list = parse_path();
	full_path = search_path(tokens[0], path_list);
	if (full_path)
	{
		free(tokens[0]);  /* free the old command */
		tokens[0] = full_path;  /* replace with full path */
		pid = fork(); /* Fork and Execute the command */
		if (pid == 0) /* Child */
		{
			if (execve(tokens[0], tokens, environ) == -1)
			{
				fprintf(stderr, "%s: %s\n", tokens[0], strerror(errno));
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0) /* If fork() fails */
		{
			perror("./shell");
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
				}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokens[0]);
	}
	free_path_list(path_list);
}
/**
 * execute_command - Execute a given command
 * @tokens: The command and its arguments
 */
void execute_command(char **tokens, char *input_line, char *argv[])
{
	int i;

	if (tokens[0] && strcmp(tokens[0], "exit") == 0)
	{ /* Cleanup and exit */
		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(input_line);
		free(tokens);
		exit(EXIT_SUCCESS);
	}
    /* If the command starts with '/' or '.', just execute directly */
	if (tokens[0][0] == '/' || tokens[0][0] == '.')
	{
		direct_execute(tokens);
		return;
	}
    /* Otherwise, search for it in the PATH */
	path_execute(tokens, argv);
}
