#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "", "", NULL};
	char *opts[] = {"-la", "-l", "-a", "-d", "-f"};
	char *dirs[] = {"/usr/", "/bin/", "../", "/abc/", "/root/"};
	int i, status;
	pid_t child_pid;
	
	for (i = 0; i < 5; i++)
	{
		argv[1] = opts[i];
		printf("%s\n", argv[1]);
		argv[2] = dirs[i];
		printf("%s\n", argv[2]);

		child_pid = fork();

		if (child_pid == -1)
		{
			printf("error");
			return (-1);
		}
		else if (child_pid == 0) 
		{
			if (execve(argv[0], argv, NULL) == -1)
				printf("ERROR\n"); 

			return (-1);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
