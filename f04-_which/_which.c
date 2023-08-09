#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
* main - function to get a file in a path.
* @ac: arguments count.
* @av: argument values, array of strings with arguments, in this cases comand lines and arguments.
*/


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

char **separate(char *str, char *separator)
{
    char *in = NULL, *in_cpy = NULL, *token = NULL, **arr;
    int i = 0, j;

	if (str == NULL)
		return (NULL);

	//in = malloc(sizeof(char) * strlen(str) + 1);
	in = strdup(str);
    if (in != NULL)
    {
        in_cpy = malloc(sizeof(char) * strlen(in) + 1);
        strcpy(in_cpy, in);

        token = strtok(in, separator);

        while (token != NULL)
        {
            i++;
            token = strtok(NULL, separator);
        }
        i++;

        arr = malloc(sizeof(char*) * i);

        token = strtok(in_cpy, separator);

        for (j = 0; token != NULL ; j++)
        {
            arr[j] = malloc(sizeof(char) * strlen(token));
            strcpy(arr[j], token);
            token = strtok(NULL, separator);
        }
        arr[j] = NULL;
        return (arr);
    }
    return (NULL);
}

int main(void)
{
	char *prompt, **command_path, **arr, **dirs;
	char *path = "/usr/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	int i = 0, j = 0;
	struct stat st;
	//pid_t child_pid;
    //int status;

	prompt = malloc(sizeof(char) * 1024);

	while (1)
	{
		printf("$");
		prompt = getin();
		printf("%s", prompt);
		printf(">>>>>>\n");
		arr = separate(prompt, " \n\t");
		printf("%s\n", arr[0]);
		dirs = separate(path, ":");


		command_path = malloc(sizeof(char*) * 10);
		while (dirs[i] != NULL)
		{
			command_path[i] = malloc(sizeof(char) * (strlen(arr[0]) + strlen(dirs[i]) + 2));
			strcpy(command_path[i], dirs[i]);
			strcat(command_path[i], "/");
			strcat(command_path[i], arr[0]);
			i++;
		}
		
		while (1)
		{
			if (stat(command_path[j], &st) == 0)
			{
				printf("found it\n");
				break;
			}
			else
			{
				printf("not found yet\n");
			}
			j++;
		}

	}
}