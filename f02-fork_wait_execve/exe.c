#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "../", NULL};

	if (execve(argv[0], argv, NULL) == -1)
		printf("ERROR\n"); 

	return (-1);
}
