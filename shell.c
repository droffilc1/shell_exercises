#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - super simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char *args[] = {"/bin/ls", NULL};
	char *lineptr = NULL;
	size_t n = 0;
	int status;
	size_t len;
	pid_t child_pid;
	char *token;
	int i = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&lineptr, &n, stdin) == -1)
		{
			perror("Error");
		}

		len = strlen(lineptr);
		if (len > 0 && lineptr[len - 1] == '\n')
			lineptr[len - 1] = '\0';

		token = strtok(lineptr, " ");
		i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if (i == 0)
			continue;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(lineptr);
	return (0);
}
