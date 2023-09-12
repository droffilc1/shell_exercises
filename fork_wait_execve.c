#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork + wait + execve
 *
 * Return: Always 0.
*/
int main(void)
{
	int i;
	pid_t child_pid;
	char *argv[] = {"ls", "-l", "/tmp", NULL};
	int status;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
		}
		if (child_pid == 0)
		{
			printf("Child %d executing ls -l /tmp:\n", i + 1);
			if (execve("/bin/ls", argv, NULL))
			{
				perror("Error");
			}
                }
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}

        }
}