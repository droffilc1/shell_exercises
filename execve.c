#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int result;
	char *argv[] = {"/bin/ls", "-l", NULL};

	pid = fork();

	if (pid == -1)
	{
		perror("Failed to fork\n");
	}
	else if (pid == 0)
	{
		result = execve(argv[0], argv, NULL);
		if (result == -1)
		{
			perror("ERROR");
		}
	}
	else
	{
		wait(NULL);
		printf("Done with exection ;)\n");
	}
	return (0);
}
