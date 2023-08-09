#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
* main - Print the maximum process id possible. 
* Return: 0
*/

int main(void)
{
    int rd, op;
    char *buff;

    buff = malloc(sizeof(char) * 2048);
    if (buff == NULL)
		return (-1);

    op = open("/proc/sys/kernel/pid_max", O_RDONLY);
    if (op == -1)
		return (0);

    rd = read(op, buff, sizeof(unsigned int) + 1);

    write(STDOUT_FILENO, buff, rd);
    printf("\n");
	close(op);

    return (rd);
}