#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
* main - Get the process id. 
* Return: 0
*/
int main(void)
{
    pid_t my_pid;

    my_pid = getppid();
    printf("%u\n", my_pid);
    return (0);
}