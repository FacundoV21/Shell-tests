#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t my_pid, child_pid, parent_pid;
	int status;

	my_pid = getpid();
    printf("My process id: %u\n", my_pid);

	child_pid = fork();

	if (child_pid == -1)
	{
		printf("error");
		return (-1);
	}
	else if (child_pid == 0)
	{
		child_pid = getpid();
		parent_pid = getppid();
		printf("Im the child and my process id is: %u\n", child_pid);
		printf("Im the child and my parent process id is: %u\n", parent_pid);
	}
	else
	{
		wait(&status);
		printf("Im the parent and my process id is still: %u\n", my_pid);
	}
	return (0);
}
